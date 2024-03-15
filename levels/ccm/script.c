#include <ultra64.h>
#include "sm64.h"
#include "behavior_data.h"
#include "model_ids.h"
#include "seq_ids.h"
#include "dialog_ids.h"
#include "segment_symbols.h"
#include "level_commands.h"

#include "game/level_update.h"

#include "levels/scripts.h"

#include "actors/common1.h"

/* Fast64 begin persistent block [includes] */
/* Fast64 end persistent block [includes] */

#include "make_const_nonconst.h"
#include "levels/ccm/header.h"

/* Fast64 begin persistent block [scripts] */
/* Fast64 end persistent block [scripts] */

const LevelScript level_ccm_entry[] = {
	INIT_LEVEL(),
	LOAD_YAY0(0x07, _ccm_segment_7SegmentRomStart, _ccm_segment_7SegmentRomEnd), 
	LOAD_YAY0_TEXTURE(0x09, _snow_yay0SegmentRomStart, _snow_yay0SegmentRomEnd), 
	LOAD_YAY0(0x0B, _effect_yay0SegmentRomStart, _effect_yay0SegmentRomEnd), 
	LOAD_YAY0(0x0A, _water_skybox_yay0SegmentRomStart, _water_skybox_yay0SegmentRomEnd), 
	LOAD_YAY0(0x05, _group7_yay0SegmentRomStart, _group7_yay0SegmentRomEnd), 
	LOAD_RAW(0x0C, _group7_geoSegmentRomStart, _group7_geoSegmentRomEnd), 
	LOAD_YAY0(0x06, _group16_yay0SegmentRomStart, _group16_yay0SegmentRomEnd), 
	LOAD_RAW(0x0D, _group16_geoSegmentRomStart, _group16_geoSegmentRomEnd), 
	LOAD_YAY0(0x08, _common0_yay0SegmentRomStart, _common0_yay0SegmentRomEnd), 
	LOAD_RAW(0x0F, _common0_geoSegmentRomStart, _common0_geoSegmentRomEnd), 
	ALLOC_LEVEL_POOL(),
	MARIO(MODEL_MARIO, 0x00000001, bhvMario), 
	JUMP_LINK(script_func_global_1), 
	JUMP_LINK(script_func_global_8), 
	JUMP_LINK(script_func_global_17), 
	LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_03, ccm_geo_00042C), 
	LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_04, ccm_geo_00045C), 
	LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_05, ccm_geo_000494), 
	LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_06, ccm_geo_0004BC), 
	LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_07, ccm_geo_0004E4), 
	LOAD_MODEL_FROM_GEO(MODEL_CCM_CABIN_DOOR, cabin_door_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_CCM_SNOW_TREE, snow_tree_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_CCM_ROPEWAY_LIFT, ccm_geo_0003D0), 
	LOAD_MODEL_FROM_GEO(MODEL_CCM_SNOWMAN_BASE, ccm_geo_0003F0), 
	LOAD_MODEL_FROM_GEO(MODEL_CCM_SNOWMAN_HEAD, ccm_geo_00040C), 

	/* Fast64 begin persistent block [level commands] */
	/* Fast64 end persistent block [level commands] */

	AREA(1, ccm_area_1),
		WARP_NODE(0x0A, LEVEL_CCM, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF0, LEVEL_CCM, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF1, LEVEL_CCM, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0x0D, LEVEL_CASTLE_GROUNDS, 0x01, 0x0C, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_1UP, -5627, 7527, 5492, 0, 0, 0, 0x00000000, bhv1Up),
		OBJECT(MODEL_RED_COIN, 6180, 7874, 4346, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, -5430, 6281, 7381, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_SPINDRIFT, -1194, 5319, 4829, 0, 0, 0, 0x00000000, bhvSpindrift),
		OBJECT(MODEL_SPINDRIFT, -2392, 5679, 3730, 0, 0, 0, 0x00000000, bhvSpindrift),
		OBJECT(MODEL_SPINDRIFT, -3712, 5890, 4697, 0, 0, 0, 0x00000000, bhvSpindrift),
		OBJECT(MODEL_SPINDRIFT, -4839, 6070, 5945, 0, 0, 0, 0x00000000, bhvSpindrift),
		OBJECT(MODEL_CASTLE_WOODEN_DOOR, 8084, 10562, 0, 0, 90, 0, (0x0D << 16), bhvDoorWarp),
		MARIO_POS(0x01, -180, 7751, 10646, 0),
		OBJECT(MODEL_RED_COIN, 7064, 10360, 866, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_WOODEN_SIGNPOST, 6894, 10573, -649, 0, 41, 0, (DIALOG_007 << 16), bhvMessagePanel),
		OBJECT(MODEL_NONE, 7751, 10646, 0, 0, -90, 0, 0x000A0000, bhvSpinAirborneWarp),
		OBJECT(MODEL_BREAKABLE_BOX, 1121, 5015, 7015, 0, -90, 0, 0x00000000, bhvBreakableBox),
		OBJECT(MODEL_BREAKABLE_BOX, 1121, 5223, 7015, 0, -90, 0, 0x00000000, bhvBreakableBox),
		OBJECT(MODEL_BREAKABLE_BOX, 1121, 5419, 7015, 0, -90, 0, 0x00000000, bhvBreakableBox),
		OBJECT(MODEL_RED_COIN, 1121, 5015, 7015, 0, -90, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, -740, 5769, 7413, 0, -90, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_WOODEN_SIGNPOST, 1312, 5286, 7155, 0, 48, 0, (DIALOG_008 << 16), bhvMessagePanel),
		OBJECT(MODEL_1UP, -7728, 4961, 7428, 0, 0, 0, 0x00000000, bhv1Up),
		OBJECT(MODEL_1UP, -7728, 4961, 7166, 0, 0, 0, 0x00000000, bhv1Up),
		OBJECT(MODEL_1UP, -7728, 4961, 7721, 0, 0, 0, 0x00000000, bhv1Up),
		OBJECT(MODEL_NONE, -7602, 5237, 8163, 0, -90, 0, 0x00000000, bhvBreakableBoxSmall),
		OBJECT(MODEL_NONE, -7628, 1921, 8231, 0, -180, 0, 0x00000000, bhvFireSpitter),
		OBJECT(MODEL_NONE, -7703, 1803, 6582, 0, 0, 0, 0x00000000, bhvFireSpitter),
		OBJECT(MODEL_NONE, -6104, 2489, 6670, 0, 0, 0, 0x00000000, bhvFireSpitter),
		OBJECT(MODEL_NONE, -7647, 3089, 8207, 0, -180, 0, 0x00000000, bhvFireSpitter),
		OBJECT(MODEL_NONE, -5863, 3078, 8196, 0, -90, 0, 0x00000000, bhvFlamethrower),
		OBJECT(MODEL_RED_COIN, -6113, 3095, 8188, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_WOODEN_SIGNPOST, -6987, 946, 8170, 0, 132, 0, (DIALOG_011 << 16), bhvMessagePanel),
		OBJECT(MODEL_WOODEN_SIGNPOST, -7602, 4954, 8166, 0, 132, 0, (DIALOG_010 << 16), bhvMessagePanel),
		OBJECT(MODEL_WOODEN_SIGNPOST, -7639, 4954, 6629, 0, 48, 0, (DIALOG_009 << 16), bhvMessagePanel),
		TERRAIN(ccm_area_1_collision),
		MACRO_OBJECTS(ccm_area_1_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_LEVEL_SLIDE),
		SHOW_DIALOG(0x00, DIALOG_006),
		TERRAIN_TYPE(TERRAIN_SLIDE),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),

	FREE_LEVEL_POOL(),
	MARIO_POS(0x01, -180, 7751, 10646, 0),
	CALL(0, lvl_init_or_update),
	CALL_LOOP(1, lvl_init_or_update),
	CLEAR_LEVEL(),
	SLEEP_BEFORE_EXIT(1),
	EXIT(),
};
