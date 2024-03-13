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
#include "levels/bob/header.h"

/* Fast64 begin persistent block [scripts] */
/* Fast64 end persistent block [scripts] */

const LevelScript level_bob_entry[] = {
	INIT_LEVEL(),
	LOAD_YAY0(0x07, _bob_segment_7SegmentRomStart, _bob_segment_7SegmentRomEnd), 
	LOAD_YAY0_TEXTURE(0x09, _generic_yay0SegmentRomStart, _generic_yay0SegmentRomEnd), 
	LOAD_YAY0(0x0A, _water_skybox_yay0SegmentRomStart, _water_skybox_yay0SegmentRomEnd), 
	LOAD_YAY0(0x05, _group3_yay0SegmentRomStart, _group3_yay0SegmentRomEnd), 
	LOAD_RAW(0x0C, _group3_geoSegmentRomStart, _group3_geoSegmentRomEnd), 
	LOAD_YAY0(0x06, _group14_yay0SegmentRomStart, _group14_yay0SegmentRomEnd), 
	LOAD_RAW(0x0D, _group14_geoSegmentRomStart, _group14_geoSegmentRomEnd), 
	LOAD_YAY0(0x08, _common0_yay0SegmentRomStart, _common0_yay0SegmentRomEnd), 
	LOAD_RAW(0x0F, _common0_geoSegmentRomStart, _common0_geoSegmentRomEnd), 
	ALLOC_LEVEL_POOL(),
	MARIO(MODEL_MARIO, 0x00000001, bhvMario), 
	JUMP_LINK(script_func_global_1), 
	JUMP_LINK(script_func_global_4), 
	JUMP_LINK(script_func_global_15), 
	LOAD_MODEL_FROM_GEO(MODEL_BOB_BUBBLY_TREE, bubbly_tree_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_BOB_CHAIN_CHOMP_GATE, bob_geo_000440), 
	LOAD_MODEL_FROM_GEO(MODEL_BOB_SEESAW_PLATFORM, bob_geo_000458), 
	LOAD_MODEL_FROM_GEO(MODEL_BOB_BARS_GRILLS, bob_geo_000470), 
	LOAD_MODEL_FROM_GEO(MODEL_CASTLE_WOODEN_DOOR, wooden_door_geo), 

	/* Fast64 begin persistent block [level commands] */
	/* Fast64 end persistent block [level commands] */

	AREA(1, bob_area_1),
		WARP_NODE(0x0A, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF0, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF1, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0x0D, LEVEL_CASTLE_GROUNDS, 0x01, 0x0C, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_RED_COIN, 6180, 7874, 4346, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_SPINDRIFT, -1194, 5269, 4829, 0, 0, 0, 0x00000000, bhvSpindrift),
		OBJECT(MODEL_SPINDRIFT, -2430, 5731, 3722, 0, 0, 0, 0x00000000, bhvSpindrift),
		OBJECT(MODEL_SPINDRIFT, -4023, 5881, 4392, 0, 0, 0, 0x00000000, bhvSpindrift),
		OBJECT(MODEL_SPINDRIFT, -4646, 6076, 5808, 0, 0, 0, 0x00000000, bhvSpindrift),
		OBJECT(MODEL_CASTLE_WOODEN_DOOR, 8084, 10562, 0, 0, 90, 0, (0x0D << 16), bhvDoorWarp),
		MARIO_POS(0x01, 90, 7796, 10646, 0),
		OBJECT(MODEL_RED_COIN, 7064, 10360, 866, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_WOODEN_SIGNPOST, 6894, 10573, -649, 0, 41, 0, (DIALOG_007 << 16), bhvMessagePanel),
		OBJECT(MODEL_NONE, 7796, 10646, 0, 0, -180, 0, 0x000A0000, bhvSpinAirborneWarp),
		OBJECT(MODEL_BREAKABLE_BOX, 1121, 5015, 7015, 0, -90, 0, 0x00000000, bhvBreakableBox),
		OBJECT(MODEL_BREAKABLE_BOX, 1121, 5223, 7015, 0, -90, 0, 0x00000000, bhvBreakableBox),
		OBJECT(MODEL_BREAKABLE_BOX, 1121, 5419, 7015, 0, -90, 0, 0x00000000, bhvBreakableBox),
		OBJECT(MODEL_RED_COIN, 1121, 5015, 7015, 0, -90, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, -740, 5769, 7413, 0, -90, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, -4645, 6437, 7449, 0, -90, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_WOODEN_SIGNPOST, 1391, 5290, 7115, 0, -12, 0, (DIALOG_008 << 16), bhvMessagePanel),
		TERRAIN(bob_area_1_collision),
		MACRO_OBJECTS(bob_area_1_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_LEVEL_GRASS),
		SHOW_DIALOG(0x00, DIALOG_006),
		TERRAIN_TYPE(TERRAIN_STONE),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),

	FREE_LEVEL_POOL(),
	MARIO_POS(0x01, 90, 7796, 10646, 0),
	CALL(0, lvl_init_or_update),
	CALL_LOOP(1, lvl_init_or_update),
	CLEAR_LEVEL(),
	SLEEP_BEFORE_EXIT(1),
	EXIT(),
};
