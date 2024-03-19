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
#include "levels/castle_grounds/header.h"

/* Fast64 begin persistent block [scripts] */
/* Fast64 end persistent block [scripts] */

const LevelScript level_castle_grounds_entry[] = {
	INIT_LEVEL(),
	LOAD_YAY0(0x07, _castle_grounds_segment_7SegmentRomStart, _castle_grounds_segment_7SegmentRomEnd), 
	LOAD_YAY0(0x0A, _bbh_skybox_yay0SegmentRomStart, _bbh_skybox_yay0SegmentRomEnd), 
	LOAD_YAY0_TEXTURE(0x09, _outside_yay0SegmentRomStart, _outside_yay0SegmentRomEnd), 
	LOAD_YAY0(0x05, _group10_yay0SegmentRomStart, _group10_yay0SegmentRomEnd), 
	LOAD_RAW(0x0C, _group10_geoSegmentRomStart, _group10_geoSegmentRomEnd), 
	LOAD_YAY0(0x06, _group15_yay0SegmentRomStart, _group15_yay0SegmentRomEnd), 
	LOAD_RAW(0x0D, _group15_geoSegmentRomStart, _group15_geoSegmentRomEnd), 
	LOAD_YAY0(0x08, _common0_yay0SegmentRomStart, _common0_yay0SegmentRomEnd), 
	LOAD_RAW(0x0F, _common0_geoSegmentRomStart, _common0_geoSegmentRomEnd), 
	ALLOC_LEVEL_POOL(),
	MARIO(MODEL_MARIO, 0x00000001, bhvMario), 
	JUMP_LINK(script_func_global_1), 
	JUMP_LINK(script_func_global_11), 
	JUMP_LINK(script_func_global_16), 
	LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_03, castle_grounds_geo_0006F4), 
	LOAD_MODEL_FROM_GEO(MODEL_CASTLE_WOODEN_DOOR, wooden_door_geo), 

	/* Fast64 begin persistent block [level commands] */
	/* Fast64 end persistent block [level commands] */

	AREA(1, castle_grounds_area_1),
		WARP_NODE(0x0A, LEVEL_CASTLE_GROUNDS, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF0, LEVEL_CASTLE_GROUNDS, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF1, LEVEL_CASTLE_GROUNDS, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0x0C, LEVEL_CCM, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0x0D, LEVEL_CASTLE_GROUNDS, 0x01, 0x0D, WARP_NO_CHECKPOINT),
		WARP_NODE(0x0E, LEVEL_CASTLE_GROUNDS, 0x01, 0x0E, WARP_NO_CHECKPOINT),
		WARP_NODE(0x1A, LEVEL_BBH, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0x1B, LEVEL_BBH, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0x1D, LEVEL_CASTLE_GROUNDS, 0x01, 0x1D, WARP_NO_CHECKPOINT),
		WARP_NODE(0x1E, LEVEL_CASTLE_GROUNDS, 0x01, 0x1E, WARP_NO_CHECKPOINT),
		WARP_NODE(0x2A, LEVEL_ENDING, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_1UP, -601, 3889, -4399, 0, 0, 0, 0x00000000, bhv1Up),
		OBJECT(MODEL_1UP, 826, 3889, -4399, 0, 0, 0, 0x00000000, bhv1Up),
		OBJECT(MODEL_BLUE_COIN, -464, 739, -1009, 0, 0, 0, 0x00000000, bhvHiddenBlueCoin),
		OBJECT(MODEL_BLUE_COIN, 764, 761, -1220, 0, 0, 0, 0x00000000, bhvHiddenBlueCoin),
		OBJECT(MODEL_BLUE_COIN, 1640, 614, -1507, 0, 0, 0, 0x00000000, bhvHiddenBlueCoin),
		OBJECT(MODEL_BLUE_COIN, 635, 1209, -1653, 0, 0, 0, 0x00000000, bhvHiddenBlueCoin),
		OBJECT(MODEL_BLUE_COIN, 907, 1293, -2054, 0, 0, 0, 0x00000000, bhvHiddenBlueCoin),
		OBJECT(MODEL_BLUE_COIN, -681, 1063, -1477, 0, 0, 0, 0x00000000, bhvHiddenBlueCoin),
		OBJECT(MODEL_BLUE_COIN, -987, 1216, -1817, 0, 0, 0, 0x00000000, bhvHiddenBlueCoin),
		OBJECT(MODEL_BLUE_COIN, -1308, 890, -1266, 0, 0, 0, 0x00000000, bhvHiddenBlueCoin),
		OBJECT(MODEL_BLUE_COIN_SWITCH, -1059, 1122, -2610, 0, 0, 0, 0x00000000, bhvBlueCoinSwitch),
		OBJECT(MODEL_NONE, 1862, 2167, -3869, 0, 0, 0, (COIN_FORMATION_BP_SHAPE_HORIZONTAL_LINE << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, 343, 141, 2537, 0, 0, 0, (COIN_FORMATION_BP_SHAPE_HORIZONTAL_LINE << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, 1479, 3799, -3869, 0, 90, 0, (COIN_FORMATION_BP_SHAPE_HORIZONTAL_LINE << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, -106, 141, 4413, 0, 15, 0, (COIN_FORMATION_BP_SHAPE_HORIZONTAL_LINE << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, 55, 882, -1131, 0, 22, 0, (COIN_FORMATION_BP_SHAPE_HORIZONTAL_LINE << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, -4397, 297, 621, 0, 0, 0, (COIN_FORMATION_BP_SHAPE_HORIZONTAL_RING << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, 2751, 297, 2354, 0, 0, 0, (COIN_FORMATION_BP_SHAPE_HORIZONTAL_RING << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, 100, 3789, -3538, 0, 0, 0, (COIN_FORMATION_BP_SHAPE_HORIZONTAL_RING << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, -2830, 1180, -3726, 0, 0, 0, (COIN_FORMATION_BP_SHAPE_HORIZONTAL_RING << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, 2049, 299, -604, 0, 0, 0, (COIN_FORMATION_BP_SHAPE_HORIZONTAL_RING << 16), bhvCoinFormation),
		OBJECT(MODEL_YELLOW_COIN, 1295, 2124, -2649, 0, 90, 0, 0x00000000, bhvYellowCoin),
		OBJECT(MODEL_YELLOW_COIN, 899, 3288, -2528, 0, 90, 0, 0x00000000, bhvYellowCoin),
		OBJECT(MODEL_YELLOW_COIN, 105, 3288, -2528, 0, 90, 0, 0x00000000, bhvYellowCoin),
		OBJECT(MODEL_YELLOW_COIN, -745, 3288, -2613, 0, 90, 0, 0x00000000, bhvYellowCoin),
		OBJECT(MODEL_YELLOW_COIN, 68, 1879, -2599, 0, 90, 0, 0x00000000, bhvYellowCoin),
		OBJECT(MODEL_BLUE_FLAME, 573, 662, 386, 0, 0, 0, 0x00000000, bhvFlame),
		OBJECT(MODEL_BLUE_FLAME, -550, 670, 386, 0, 0, 0, 0x00000000, bhvFlame),
		OBJECT(MODEL_NONE, -474, 539, -941, 0, -29, 0, (DIALOG_013 << 16), bhvMessagePanel),
		OBJECT(MODEL_NONE, -1192, 682, -1206, 0, 44, 0, (DIALOG_014 << 16), bhvMessagePanel),
		OBJECT(MODEL_NONE, -650, 867, -1373, 0, -9, 0, (DIALOG_015 << 16), bhvMessagePanel),
		OBJECT(MODEL_NONE, -1046, 1035, -1702, 0, -28, 0, (DIALOG_016 << 16), bhvMessagePanel),
		OBJECT(MODEL_NONE, 525, 998, -1682, 0, -86, 0, (DIALOG_017 << 16), bhvMessagePanel),
		OBJECT(MODEL_NONE, 979, 1094, -2010, 0, 24, 0, (DIALOG_018 << 16), bhvMessagePanel),
		OBJECT(MODEL_NONE, 705, 561, -1172, 0, -15, 0, (DIALOG_019 << 16), bhvMessagePanel),
		OBJECT(MODEL_NONE, 1573, 452, -1469, 0, -39, 0, (DIALOG_030 << 16), bhvMessagePanel),
		MARIO_POS(0x01, -180, 0, 200, 5368),
		OBJECT(MODEL_BOBOMB_BUDDY, -250, 91, 2367, 0, -140, 0, (DIALOG_001 << 16), bhvBobombBuddy),
		OBJECT(MODEL_WOODEN_SIGNPOST, -429, 112, 4716, 0, 36, 0, (DIALOG_000 << 16), bhvMessagePanel),
		OBJECT(MODEL_WOODEN_SIGNPOST, -49, 3701, -4010, 0, 30, 0, (DIALOG_032 << 16), bhvMessagePanel),
		OBJECT(MODEL_WOODEN_SIGNPOST, -508, 14, 613, 0, 20, 0, (DIALOG_002 << 16), bhvMessagePanel),
		OBJECT(MODEL_WOODEN_SIGNPOST, 230, 68, 4068, 0, -24, 0, (DIALOG_005 << 16), bhvMessagePanel),
		OBJECT(MODEL_NONE, 0, 200, 5368, 0, -180, 0, 0x000A0000, bhvSpinAirborneWarp),
		OBJECT(MODEL_CASTLE_WOODEN_DOOR, -728, 159, 2596, 0, 88, 0, (0x0C << 16), bhvDoorWarp),
		OBJECT(MODEL_CASTLE_WOODEN_DOOR, 120, 1416, -2735, 0, 178, 0, (0x1A << 16), bhvDoorWarp),
		OBJECT(MODEL_CASTLE_WOODEN_DOOR, -31, 1416, -2735, 0, -2, 0, (0x1B << 16), bhvDoorWarp),
		OBJECT(MODEL_NONE, 103, 3701, -4207, 0, 0, 0, (0x2A << 16), bhvDoorWarp),
		OBJECT(MODEL_NONE, -498, 431, 2596, 0, -92, 0, (0x0E << 16), bhvAirborneStarCollectWarp),
		OBJECT(MODEL_NONE, -496, 179, 2596, 0, 88, 0, (0x0D << 16), bhvDeathWarp),
		OBJECT(MODEL_NONE, 44, 1581, -2561, 0, 178, 0, (0x1E << 16), bhvAirborneStarCollectWarp),
		OBJECT(MODEL_NONE, 41, 1448, -2564, 0, -2, 0, (0x1D << 16), bhvDeathWarp),
		TERRAIN(castle_grounds_area_1_collision),
		MACRO_OBJECTS(castle_grounds_area_1_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_LEVEL_SPOOKY),
		TERRAIN_TYPE(TERRAIN_SPOOKY),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),

	FREE_LEVEL_POOL(),
	MARIO_POS(0x01, -180, 0, 200, 5368),
	CALL(0, lvl_init_or_update),
	CALL_LOOP(1, lvl_init_or_update),
	CLEAR_LEVEL(),
	SLEEP_BEFORE_EXIT(1),
	EXIT(),
};
