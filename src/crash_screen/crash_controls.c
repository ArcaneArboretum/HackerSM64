#include <ultra64.h>

#include "types.h"
#include "sm64.h"

#include "address_select.h"
#include "crash_draw.h"
#include "crash_main.h"
#include "crash_pages.h"
#include "crash_print.h"
#include "crash_settings.h"

#include "crash_controls.h"

#include "pages/page_stack.h"

#ifdef UNF
#include "usb/debug.h"
#endif // UNF


struct CSSetting cs_settings_group_controls[] = {
    [CS_OPT_HEADER_CONTROLS             ] = { .type = CS_OPT_TYPE_HEADER,  .name = "CONTROLS",                       .valNames = &gValNames_bool,          .val = SECTION_EXPANDED_DEFAULT,  .defaultVal = SECTION_EXPANDED_DEFAULT,  .lowerBound = FALSE,                 .upperBound = TRUE,                       },
    [CS_OPT_CONTROLS_CURSOR_WAIT_FRAMES ] = { .type = CS_OPT_TYPE_SETTING, .name = "Hold direction wait frames",     .valNames = NULL,                     .val = 10,                        .defaultVal = 10,                        .lowerBound = 0,                     .upperBound = 1000,                       },
    [CS_OPT_CONTROLS_ANALOG_DEADZONE    ] = { .type = CS_OPT_TYPE_SETTING, .name = "Analog deadzone",                .valNames = NULL,                     .val = 60,                        .defaultVal = 60,                        .lowerBound = 0,                     .upperBound = 128,                        },
    [CS_OPT_END_CONTROLS                ] = { .type = CS_OPT_TYPE_END, },
};


const enum ControlTypes cs_cont_list_default[] = {
    CONT_DESC_SWITCH_PAGE,
    CONT_DESC_PAGE_SELECT,
    CONT_DESC_SHOW_CONTROLS,
    CONT_DESC_HIDE_CRASH_SCREEN,
#ifdef UNF
    CONT_DESC_OS_PRINT,
#endif // UNF
    CONT_DESC_LIST_END,
};


CrashScreenDirections gCSDirectionFlags;

static OSTime sCSInputTimeY = 0;
static OSTime sCSInputTimeX = 0;

CSController gCSCompositeControllers[1];
CSController* const gCSCompositeController = &gCSCompositeControllers[0];


const ControlType gCSControlDescriptions[] = {
    [CONT_DESC_SWITCH_PAGE      ] = { .control = STR_L"/"STR_R,                             .description = "switch page",                       },
    [CONT_DESC_PAGE_SELECT      ] = { .control = STR_L"+"STR_R,                             .description = "open page select",                  },
    [CONT_DESC_SHOW_CONTROLS    ] = { .control = STR_START,                                 .description = "show/hide page controls",           },
    [CONT_DESC_HIDE_CRASH_SCREEN] = { .control = STR_Z,                                     .description = "hide crash screen",                 },
#ifdef UNF
    [CONT_DESC_OS_PRINT         ] = { .control = STR_Z"+"STR_START,                         .description = "print page to developer console",   },
#endif // UNF
    [CONT_DESC_SCROLL_LIST      ] = { .control = STR_UP"/"STR_DOWN,                         .description = "scroll list",                       },
    [CONT_DESC_CURSOR           ] = { .control = STR_UP"/"STR_DOWN"/"STR_LEFT"/"STR_RIGHT,  .description = "move cursor",                       },
    [CONT_DESC_CURSOR_VERTICAL  ] = { .control = STR_UP"/"STR_DOWN,                         .description = "move cursor",                       },
    [CONT_DESC_CURSOR_HORIZONTAL] = { .control = STR_LEFT"/"STR_RIGHT,                      .description = "move cursor",                       },
    [CONT_DESC_JUMP_TO_ADDRESS  ] = { .control = STR_A,                                     .description = "jump to specific address",          },
    [CONT_DESC_TOGGLE_ASCII     ] = { .control = STR_B,                                     .description = "toggle bytes as hex or ascii",      },
#ifdef INCLUDE_DEBUG_MAP
    [CONT_DESC_TOGGLE_FUNCTIONS ] = { .control = STR_B,                                     .description = "toggle function names",             },
#endif // INCLUDE_DEBUG_MAP
    [CONT_DESC_CYCLE_FLOATS_MODE] = { .control = STR_B,                                     .description = "toggle floats mode",                },
    [CONT_DESC_CHANGE_SETTING   ] = { .control = STR_A"/"STR_B"/"STR_LEFT"/"STR_RIGHT,      .description = "change selected setting",           },
    [CONT_DESC_RESET_SETTING    ] = { .control = STR_A"+"STR_B,                             .description = "reset selected setting to default", },
};


// Updates gCSDirectionFlags with directional inputs. Analog stick, D-pad, or C-buttons.
void cs_update_direction_input(void) {
    OSTime currTime = osGetTime();

    gCSDirectionFlags.pressed.up    = FALSE;
    gCSDirectionFlags.pressed.down  = FALSE;
    gCSDirectionFlags.pressed.left  = FALSE;
    gCSDirectionFlags.pressed.right = FALSE;

    s16 rawStickX  = gCSCompositeController->rawStickX;
    s16 rawStickY  = gCSCompositeController->rawStickY;
    u16 buttonDown = gCSCompositeController->buttonDown;

    s16 deadzone = cs_get_setting_val(CS_OPT_GROUP_CONTROLS, CS_OPT_CONTROLS_ANALOG_DEADZONE);

    _Bool up    = ((buttonDown & (U_CBUTTONS | U_JPAD)) || (rawStickY >  deadzone));
    _Bool down  = ((buttonDown & (D_CBUTTONS | D_JPAD)) || (rawStickY < -deadzone));
    _Bool left  = ((buttonDown & (L_CBUTTONS | L_JPAD)) || (rawStickX < -deadzone));
    _Bool right = ((buttonDown & (R_CBUTTONS | R_JPAD)) || (rawStickX >  deadzone));

    // How long to wait when holding a direction before it becomes continuous.
    const OSTime cursorWaitCycles = FRAMES_TO_CYCLES(cs_get_setting_val(CS_OPT_GROUP_CONTROLS, CS_OPT_CONTROLS_CURSOR_WAIT_FRAMES));

    if (up ^ down) {
        if (
            !(
                gCSDirectionFlags.held.up ||
                gCSDirectionFlags.held.down
            )
        ) { // Prev Y:
            // On press:
            sCSInputTimeY = currTime;
            gCSDirectionFlags.pressed.up   = up;
            gCSDirectionFlags.pressed.down = down;
        } else {
            // Held:
            OSTime diff = (currTime - sCSInputTimeY);
            if (diff > cursorWaitCycles) {
                gCSDirectionFlags.pressed.up   = up;
                gCSDirectionFlags.pressed.down = down;
            }
        }
    }

    if (left ^ right) {
        if (
            !(
                gCSDirectionFlags.held.left ||
                gCSDirectionFlags.held.right
            )
        ) { // Prev X:
            // On press:
            sCSInputTimeX = currTime;
            gCSDirectionFlags.pressed.left  = left;
            gCSDirectionFlags.pressed.right = right;
        } else {
            // Held:
            OSTime diff = (currTime - sCSInputTimeX);
            if (diff > cursorWaitCycles) {
                gCSDirectionFlags.pressed.left  = left;
                gCSDirectionFlags.pressed.right = right;
            }
        }
    }

    gCSDirectionFlags.held.up    = up;
    gCSDirectionFlags.held.down  = down;
    gCSDirectionFlags.held.left  = left;
    gCSDirectionFlags.held.right = right;
}

// Moves the viewport in a scrollable list to contain the selection cursor.
u32 cs_clamp_view_to_selection(u32 scrollIndex, u32 selectIndex, const u32 numRows, const u32 step) {
    const size_t size = ((numRows - 1) * step);

    // Selection is past the end of the viewport.
    if ((scrollIndex + size) < selectIndex) {
        scrollIndex = (selectIndex - size);
    }

    // Selection is before the beginning of the viewport.
    if (scrollIndex > selectIndex) {
        scrollIndex = selectIndex;
    }

    return ALIGNFLOOR(scrollIndex, step);
}

// Whether L/R can be used to switch the page.
_Bool can_switch_page(void) {
    CSPopup* popup = cs_get_current_popup();
    return ((popup == NULL) || popup->flags.allowPage);
}

// Check for a page switch input (L or R).
_Bool cs_check_switch_page_input(void) {
    enum CSPages prevPage = gCSPageID;

    u16 buttonDown = gCSCompositeController->buttonDown;
    if ((buttonDown & (L_TRIG | R_TRIG)) == (L_TRIG | R_TRIG)) {
        cs_open_popup(CS_POPUP_PAGES);
        return FALSE;
    }

    u16 buttonPressed = gCSCompositeController->buttonPressed;

    s8 change = 0;
    if (buttonPressed & L_TRIG) change = -1; // Previous Page.
    if (buttonPressed & R_TRIG) change = +1; // Next page.
    gCSPageID = WRAP(((s32)gCSPageID + change), FIRST_PAGE, (NUM_PAGES - 1));

    if (gCSPageID == prevPage) {
        return FALSE;
    }

    // Reset certain values when the page is changed.
    gCSSwitchedPage = TRUE;

    return TRUE;
}

#ifdef UNF
// Prints a page's data to the developer console.
void cs_os_print_page(CSPage* page) {
    if (page->printFunc != NULL) {
        debug_printf("---\n");
        const char* name = page->name;
        if (name != NULL) {
            debug_printf("%s:\n", page->name);
        }
        page->printFunc();
    } else {
        debug_printf("%s has no print function.\n", page->name);
    }
}
#endif // UNF

// Global crash screen input function.
void cs_update_input(void) {
    CSPage* page = cs_get_current_page();

    handle_input(&gActiveCSThreadInfo->mesg); //! TODO: Make controller switching not weird when the crash screen is open.

    bzero(&gCSCompositeControllers, sizeof(gCSCompositeControllers));

    for (int port = 0; port < ARRAY_COUNT(gControllers); port++) { //! TODO: < MAXCONTROLLERS when input PR is merged.
        struct Controller* controller = &gControllers[port];

        s16 rawStickX = controller->rawStickX;
        s16 rawStickY = controller->rawStickY;

        if (abss(gCSCompositeController->rawStickX) < abss(rawStickX)) {
            gCSCompositeController->rawStickX = rawStickX;
        }
        if (abss(gCSCompositeController->rawStickY) < abss(rawStickY)) {
            gCSCompositeController->rawStickY = rawStickY;
        }
        gCSCompositeController->buttonDown     |= controller->buttonDown;
        gCSCompositeController->buttonPressed  |= controller->buttonPressed;
        gCSCompositeController->buttonReleased |= controller->buttonReleased;
    }

    cs_update_direction_input();

#ifdef UNF
    if (
        (gCSCompositeController->buttonDown & Z_TRIG) &&
        (gCSCompositeController->buttonPressed & START_BUTTON)
    ) {
        gCSCompositeController->buttonPressed &= ~START_BUTTON;
        cs_os_print_page(page);
    }
#endif // UNF

    CSPopup* popup = cs_get_current_popup();

    if ((popup == NULL) && !gCSSwitchedPopup) {
        if (
            !(gCSCompositeController->buttonDown & Z_TRIG) &&
            (gCSCompositeController->buttonPressed & START_BUTTON)
        ) {
            cs_open_popup(CS_POPUP_CONTROLS);
        }
    }

    // Popup is open.
    if (popup != NULL) {
        if (gCSSwitchedPopup) {
            gCSSwitchedPopup = FALSE;
            if (popup->initFunc != NULL) {
                popup->initFunc();
            }
        } else {
            if (popup->inputFunc != NULL) {
                popup->inputFunc();
            }
        }

    }

    if ((can_switch_page() && cs_check_switch_page_input()) || gCSSwitchedPage) {
        page = cs_get_current_page(); // Page may have changed in cs_check_switch_page_input.

        if ((page->initFunc != NULL) && !page->flags.initialized) {
            page->initFunc();
            page->flags.initialized = TRUE;
        }
    }

    if (popup != NULL) {
        return;
    }

    // Run the page-specific input function.
    if ((page->inputFunc != NULL) && !page->flags.crashed) {
        page->inputFunc();
    }

    gCSSwitchedPage  = FALSE;
    gCSSwitchedPopup = FALSE;
}

// Page select popup box draw function.
void cs_popup_pages_draw(void) {
    cs_draw_dark_rect(
        (CRASH_SCREEN_X1 + (TEXT_WIDTH(1) / 2)), (CRASH_SCREEN_Y1 + (TEXT_HEIGHT(1) / 2)),
        (CRASH_SCREEN_W  -  TEXT_WIDTH(1)     ), (CRASH_SCREEN_H  -  TEXT_HEIGHT(1)     ),
        CS_DARKEN_SEVEN_EIGHTHS
    );

    CSPopup* currPopup = cs_get_current_popup();

    // "PAGE SELECT:"
    cs_print(TEXT_X(1), TEXT_Y(1), STR_COLOR_PREFIX"%s:", COLOR_RGBA32_CRASH_PAGE_NAME, currPopup->name);

    u32 line = 3;
    //! TODO: Scrollable if list is long enough.
    for (enum CSPages pageID = 0; pageID < NUM_PAGES; pageID++) {
        CSPage* page = gCSPages[pageID];

        if ((page == NULL) || (page->name == NULL)) {
            break;
        }

        if (pageID == gCSPageID) {
            cs_draw_row_selection_box(TEXT_Y(3 + pageID));
        }

        cs_draw_divider_translucent_popup(DIVIDER_Y(line));
        cs_print(TEXT_X(1), TEXT_Y(line), STR_COLOR_PREFIX"<%02d>: %s", COLOR_RGBA32_CRASH_PAGE_NAME, pageID, page->name);

        line++;
    }

    cs_draw_divider_translucent_popup(DIVIDER_Y(line));

    osWritebackDCacheAll();
}

void cs_popup_pages_input(void) {
    enum CSPages prevPage = gCSPageID;

    u16 buttonPressed = gCSCompositeController->buttonPressed;

    if (buttonPressed & (A_BUTTON | B_BUTTON | START_BUTTON)) {
        // Close the popup without jumping.
        cs_open_popup(CS_POPUP_NONE);
        return;
    }

    s32 change = 0;
    if (gCSDirectionFlags.pressed.up  ) change = -1; // Scroll up.
    if (gCSDirectionFlags.pressed.down) change = +1; // Scroll down.
    gCSPageID = WRAP(((s32)gCSPageID + change), FIRST_PAGE, (NUM_PAGES - 1)); //! TODO: combine with normal L/R functionality

    if (gCSPageID != prevPage) {
        // Reset certain values when the page is changed.
        gCSSwitchedPage = TRUE;
    }
}

struct CSPopup gCSPopup_pages = {
    .name      = "PAGE SELECT",
    .initFunc  = NULL,
    .drawFunc  = cs_popup_pages_draw,
    .inputFunc = cs_popup_pages_input,
    .flags = {
        .allowPage = TRUE,
    },
};

// Controls popup box draw function.
//! TODO: Allow changing page-specific settings from here.
void cs_popup_controls_draw(void) {
    cs_draw_dark_rect(
        (CRASH_SCREEN_X1 + (TEXT_WIDTH(1) / 2)), (CRASH_SCREEN_Y1 + (TEXT_HEIGHT(1) / 2)),
        (CRASH_SCREEN_W  -  TEXT_WIDTH(1)     ), (CRASH_SCREEN_H  -  TEXT_HEIGHT(1)     ),
        CS_DARKEN_SEVEN_EIGHTHS
    );
    CSPage* page = cs_get_current_page();

    // "[page name] PAGE CONTROLS"
    cs_print(TEXT_X(1), TEXT_Y(1), STR_COLOR_PREFIX"%s PAGE CONTROLS", COLOR_RGBA32_CRASH_PAGE_NAME, page->name);

    const enum ControlTypes* list = page->contList;

    if (list != NULL) {
        const ControlType* desc = NULL;

        u32 line = 3;

        while (*list != CONT_DESC_LIST_END) {
            desc = &gCSControlDescriptions[*list++];
            // [control]
            //   [description]
            cs_print(TEXT_X(2), TEXT_Y(line), "%s:\n "STR_COLOR_PREFIX"%s", desc->control, COLOR_RGBA32_CRASH_CONTROLS_DESCRIPTION, desc->description);
            line += 2;
        }
    }

    osWritebackDCacheAll();
}

void cs_popup_controls_input(void) { //! TODO: Scrolling if list is too long.
    u16 buttonPressed = gCSCompositeController->buttonPressed;

    if (buttonPressed & (A_BUTTON | B_BUTTON | START_BUTTON)) {
        // Close the popup without jumping.
        cs_open_popup(CS_POPUP_NONE);
    }
}

struct CSPopup gCSPopup_controls = {
    .name      = "CONTROLS",
    .initFunc  = NULL,
    .drawFunc  = cs_popup_controls_draw,
    .inputFunc = cs_popup_controls_input,
    .flags = {
        .allowPage = TRUE,
    },
};
