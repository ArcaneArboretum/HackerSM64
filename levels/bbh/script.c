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
#include "levels/bbh/header.h"

/* Fast64 begin persistent block [scripts] */
/* Fast64 end persistent block [scripts] */

const LevelScript level_bbh_entry[] = {
	INIT_LEVEL(),
	LOAD_YAY0(0x07, _bbh_segment_7SegmentRomStart, _bbh_segment_7SegmentRomEnd), 
	LOAD_YAY0(0x0A, _bits_skybox_yay0SegmentRomStart, _bits_skybox_yay0SegmentRomEnd), 
	LOAD_YAY0_TEXTURE(0x09, _spooky_yay0SegmentRomStart, _spooky_yay0SegmentRomEnd), 
	LOAD_YAY0(0x05, _group9_yay0SegmentRomStart, _group9_yay0SegmentRomEnd), 
	LOAD_RAW(0x0C, _group9_geoSegmentRomStart, _group9_geoSegmentRomEnd), 
	LOAD_YAY0(0x06, _group17_yay0SegmentRomStart, _group17_yay0SegmentRomEnd), 
	LOAD_RAW(0x0D, _group17_geoSegmentRomStart, _group17_geoSegmentRomEnd), 
	LOAD_YAY0(0x08, _common0_yay0SegmentRomStart, _common0_yay0SegmentRomEnd), 
	LOAD_RAW(0x0F, _common0_geoSegmentRomStart, _common0_geoSegmentRomEnd), 
	ALLOC_LEVEL_POOL(),
	MARIO(MODEL_MARIO, 0x00000001, bhvMario), 
	JUMP_LINK(script_func_global_1), 
	JUMP_LINK(script_func_global_10), 
	JUMP_LINK(script_func_global_18), 
	LOAD_MODEL_FROM_GEO(MODEL_BBH_HAUNTED_DOOR, haunted_door_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_BBH_STAIRCASE_STEP, geo_bbh_0005B0), 
	LOAD_MODEL_FROM_GEO(MODEL_BBH_TILTING_FLOOR_PLATFORM, geo_bbh_0005C8), 
	LOAD_MODEL_FROM_GEO(MODEL_BBH_TUMBLING_PLATFORM, geo_bbh_0005E0), 
	LOAD_MODEL_FROM_GEO(MODEL_BBH_TUMBLING_PLATFORM_PART, geo_bbh_0005F8), 
	LOAD_MODEL_FROM_GEO(MODEL_BBH_MOVING_BOOKSHELF, geo_bbh_000610), 
	LOAD_MODEL_FROM_GEO(MODEL_BBH_MESH_ELEVATOR, geo_bbh_000628), 
	LOAD_MODEL_FROM_GEO(MODEL_BBH_MERRY_GO_ROUND, geo_bbh_000640), 
	LOAD_MODEL_FROM_GEO(MODEL_BBH_WOODEN_TOMB, geo_bbh_000658), 

	/* Fast64 begin persistent block [level commands] */
	/* Fast64 end persistent block [level commands] */

	AREA(1, bbh_area_1),
		WARP_NODE(0x0A, LEVEL_BBH, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF0, LEVEL_CASTLE_GROUNDS, 0x01, 0x1E, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF1, LEVEL_CASTLE_GROUNDS, 0x01, 0x1D, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_BOO, 7487, 10002, 7064, 0, -178, 0, 0x00000000, bhvBoo),
		OBJECT(MODEL_BOO, 7073, 10002, 7064, 0, -178, 0, 0x00000000, bhvBoo),
		OBJECT(MODEL_BOO, 6628, 10002, 6916, 0, 144, 0, 0x00000000, bhvBoo),
		OBJECT(MODEL_BOO, 6628, 10002, 5432, 0, 54, 0, 0x00000000, bhvBoo),
		OBJECT(MODEL_BOO, 7037, 10002, 5285, 0, 1, 0, 0x00000000, bhvBoo),
		OBJECT(MODEL_BOO, 7460, 10002, 5285, 0, 1, 0, 0x00000000, bhvBoo),
		OBJECT(MODEL_BOO, 6417, 10350, 7702, 0, 139, 0, 0x00000000, bhvBoo),
		OBJECT(MODEL_BOO, 6399, 10350, 4607, 0, 53, 0, 0x00000000, bhvBoo),
		OBJECT(MODEL_BOO, 4412, 9531, 5109, 0, 19, 0, 0x00000000, bhvBoo),
		OBJECT(MODEL_BOO, 3043, 8948, 1763, 0, 48, 0, 0x00000000, bhvBoo),
		OBJECT(MODEL_BOO, -3310, 7131, 2125, 0, 156, 0, 0x00000000, bhvBoo),
		OBJECT(MODEL_BOO, -679, 6410, 4564, 0, -62, 0, 0x00000000, bhvBoo),
		OBJECT(MODEL_BOO, 2803, 6195, 3129, 0, -41, 0, 0x00000000, bhvBoo),
		OBJECT(MODEL_BOO, 4701, 4946, -1958, 0, -18, 0, 0x00000000, bhvBoo),
		OBJECT(MODEL_BOO, 2980, 4149, -5274, 0, 10, 0, 0x00000000, bhvBoo),
		OBJECT(MODEL_BOO, 1210, 3751, -7242, 0, 72, 0, 0x00000000, bhvBoo),
		OBJECT(MODEL_BOO, -5273, 2123, -6409, 0, 179, 0, 0x00000000, bhvBoo),
		OBJECT(MODEL_BOO, -4216, 831, -532, 0, -125, 0, 0x00000000, bhvBoo),
		OBJECT(MODEL_BOO, -6150, 1116, -1985, 0, -161, 0, 0x00000000, bhvBoo),
		OBJECT(MODEL_BOO, -6525, 729, 562, 0, 170, 0, 0x00000000, bhvBoo),
		OBJECT(MODEL_BOO, -188, -1554, 5544, 0, -118, 0, 0x00000000, bhvBoo),
		OBJECT(MODEL_BOO, 1001, -2764, 1218, 0, -62, 0, 0x00000000, bhvBoo),
		OBJECT(MODEL_BOO, -765, -3753, -3471, 0, -35, 0, 0x00000000, bhvBoo),
		OBJECT(MODEL_BOO, 1162, -4682, -6282, 0, -110, 0, 0x00000000, bhvBoo),
		OBJECT(MODEL_BOO, 2991, -5230, -4496, 0, -117, 0, 0x00000000, bhvBoo),
		OBJECT(MODEL_BOO, 2311, -5219, -2047, 0, -170, 0, 0x00000000, bhvBoo),
		OBJECT(MODEL_BOO, 2396, -5290, 1891, 0, 174, 0, 0x00000000, bhvBoo),
		OBJECT(MODEL_BOO, -1914, -6300, 3519, 0, 80, 0, 0x00000000, bhvBoo),
		OBJECT(MODEL_BOO, -4217, -6907, 1068, 0, 20, 0, 0x00000000, bhvBoo),
		OBJECT(MODEL_BOO, -3801, -6731, 994, 0, -65, 0, 0x00000000, bhvBoo),
		OBJECT(MODEL_BOO, -3383, -8359, -351, 0, -65, 0, 0x00000000, bhvBoo),
		OBJECT(MODEL_BOO, -2711, -8384, -1348, 0, -65, 0, 0x00000000, bhvBoo),
		OBJECT(MODEL_BOO, -3126, -8344, -2904, 0, -65, 0, 0x00000000, bhvBoo),
		OBJECT(MODEL_BOO, -3667, -8344, -2275, 0, -25, 0, 0x00000000, bhvBoo),
		OBJECT(MODEL_BOO, -3833, -8344, -1475, 0, -25, 0, 0x00000000, bhvBoo),
		OBJECT(MODEL_BOO, -4700, -8344, -1655, 0, 20, 0, 0x00000000, bhvBoo),
		OBJECT(MODEL_BOO, -5666, -8356, -1251, 0, 55, 0, 0x00000000, bhvBoo),
		OBJECT(MODEL_BOO, -6276, -8351, -1788, 0, 51, 0, 0x00000000, bhvBoo),
		OBJECT(MODEL_BOO, -5796, -8368, -2888, 0, 18, 0, 0x00000000, bhvBoo),
		OBJECT(MODEL_BOO, -4903, -8429, -2969, 0, 1, 0, 0x00000000, bhvBoo),
		OBJECT(MODEL_BOO, -4123, -8379, -3190, 0, -19, 0, 0x00000000, bhvBoo),
		OBJECT(MODEL_BOO, -4602, -8429, -2728, 0, 1, 0, 0x00000000, bhvBalconyBigBoo),
		OBJECT(MODEL_NONE, 4920, 9773, 5992, 0, 65, 0, (COIN_FORMATION_BP_SHAPE_HORIZONTAL_LINE << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, 3681, 9270, 3149, 0, 0, 0, (COIN_FORMATION_BP_SHAPE_HORIZONTAL_LINE << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, 508, 8567, 468, 0, 87, 0, (COIN_FORMATION_BP_SHAPE_HORIZONTAL_LINE << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, 1031, 6380, 4715, 0, 106, 0, (COIN_FORMATION_BP_SHAPE_HORIZONTAL_LINE << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, 2423, 5175, -2028, 0, 179, 0, (COIN_FORMATION_BP_SHAPE_HORIZONTAL_LINE << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, 2510, 5489, -695, 0, -173, 0, (COIN_FORMATION_BP_SHAPE_HORIZONTAL_LINE << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, 2554, 4854, -3477, 0, 166, 0, (COIN_FORMATION_BP_SHAPE_HORIZONTAL_LINE << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, 1867, 4263, -6974, 0, -115, 0, (COIN_FORMATION_BP_SHAPE_HORIZONTAL_LINE << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, -5713, 2366, -6643, 0, -40, 0, (COIN_FORMATION_BP_SHAPE_HORIZONTAL_LINE << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, -6597, 1352, -1932, 0, -13, 0, (COIN_FORMATION_BP_SHAPE_HORIZONTAL_LINE << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, -6090, 823, 773, 0, 22, 0, (COIN_FORMATION_BP_SHAPE_HORIZONTAL_LINE << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, -4746, 295, 3035, 0, 50, 0, (COIN_FORMATION_BP_SHAPE_HORIZONTAL_LINE << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, -2491, -385, 5113, 0, 64, 0, (COIN_FORMATION_BP_SHAPE_HORIZONTAL_LINE << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, 537, -2614, 1513, 0, -180, 0, (COIN_FORMATION_BP_SHAPE_HORIZONTAL_LINE << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, 2248, -5221, -2026, 0, -180, 0, (COIN_FORMATION_BP_SHAPE_HORIZONTAL_LINE << 16), bhvCoinFormation),
		OBJECT(MODEL_RED_COIN, 6415, 10835, 6155, 0, 92, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, -3115, 6966, 2382, 0, 92, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, 4297, 4837, -2247, 0, 92, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, -1942, 3377, -7273, 0, 92, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, -4331, 632, 76, 0, -162, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, -168, -1642, 5625, 0, -140, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, 1144, -4686, -6137, 0, -123, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, -2870, -6448, 3449, 0, -123, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_STAR, -4848, -8183, -4535, 0, 1, 0, (STAR_BP_ACT_1 << 24), bhvStar),
		OBJECT(MODEL_NONE, -4296, -8183, -4535, 0, 1, 0, (STAR_BP_ACT_2 << 24) | (6 << 16), bhvHiddenRedCoinStar),
		MARIO_POS(0x01, -90, 7718, 10040, 6158),
		OBJECT(MODEL_NONE, 7718, 10040, 6158, 0, -90, 0, 0x000A0000, bhvSpinAirborneWarp),
		TERRAIN(bbh_area_1_collision),
		MACRO_OBJECTS(bbh_area_1_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_EVENT_MERRY_GO_ROUND),
		SHOW_DIALOG(0x00, DIALOG_031),
		TERRAIN_TYPE(TERRAIN_SLIDE),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),

	FREE_LEVEL_POOL(),
	MARIO_POS(0x01, -90, 7718, 10040, 6158),
	CALL(0, lvl_init_or_update),
	CALL_LOOP(1, lvl_init_or_update),
	CLEAR_LEVEL(),
	SLEEP_BEFORE_EXIT(1),
	EXIT(),
};
