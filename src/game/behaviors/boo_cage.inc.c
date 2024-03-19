
/**
 * Behavior for bhvBooCage.
 * This is the cage inside the big boo in the castle courtyard
 * that lets Mario enter BBH. It has its own special interaction type,
 * INTERACT_BBH_ENTRANCE.
 */

#define SPAWN_CASTLE_BOO_STAR_REQUIREMENT 3

/**
 * Boo cage hitbox. It's not tangible; this is the hitbox
 * Mario has to enter to enter BBH.
 */
static struct ObjectHitbox sBooCageHitbox = {
    /* interactType:      */ INTERACT_BBH_ENTRANCE,
    /* downOffset:        */ 0,
    /* damageOrCoinValue: */ 0,
    /* health:            */ 0,
    /* numLootCoins:      */ 0,
    /* radius:            */ 120,
    /* height:            */ 300,
    /* hurtboxRadius:     */ 0,
    /* hurtboxHeight:     */ 0,
};

/**
 * Update function for bhvBooCage.
 */
void bhv_boo_cage_loop(void) {
    obj_set_hitbox(o, &sBooCageHitbox);

    if (gHudDisplay.stars >= SPAWN_CASTLE_BOO_STAR_REQUIREMENT) {
        // Allow Mario to enter the cage once it's still on the ground.
        cur_obj_become_tangible();

        // Set the action to BOO_CAGE_ACT_MARIO_JUMPING_IN when Mario jumps in.
        if (obj_check_if_collided_with_object(o, gMarioObject)) {
            o->oAction = BOO_CAGE_ACT_MARIO_JUMPING_IN;
        }
    }// else {
    //    cur_obj_become_intangible();
    //}
}
