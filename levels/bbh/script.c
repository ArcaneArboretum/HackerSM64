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
		OBJECT(MODEL_BOO, 4354, 9655, 5051, 0, -34, 0, 0x00000000, bhvBoo),
		OBJECT(MODEL_BOO, 2841, 8994, 1907, 0, 130, 0, 0x00000000, bhvBoo),
		OBJECT(MODEL_BOO, -3403, 7333, 2125, 0, 108, 0, 0x00000000, bhvBoo),
		OBJECT(MODEL_BOO, -602, 6794, 4709, 0, 4, 0, 0x00000000, bhvBoo),
		OBJECT(MODEL_BOO, 3179, 6195, 3515, 0, -78, 0, 0x00000000, bhvBoo),
		OBJECT(MODEL_BOO, 4534, 5166, -1986, 0, -89, 0, 0x00000000, bhvBoo),
		OBJECT(MODEL_BOO, 3147, 4449, -5358, 0, 43, 0, 0x00000000, bhvBoo),
		OBJECT(MODEL_BOO, 1237, 4044, -6978, 0, 138, 0, 0x00000000, bhvBoo),
		OBJECT(MODEL_BOO, -5273, 2389, -6409, 0, -138, 0, 0x00000000, bhvBoo),
		OBJECT(MODEL_BOO, -4216, 924, -532, 0, -138, 0, 0x00000000, bhvBoo),
		OBJECT(MODEL_BOO, -6150, 1333, -1763, 0, -159, 0, 0x00000000, bhvBoo),
		OBJECT(MODEL_BOO, -6608, 998, 507, 0, 168, 0, 0x00000000, bhvBoo),
		OBJECT(MODEL_BOO, -8, -1432, 5613, 0, -118, 0, 0x00000000, bhvBoo),
		OBJECT(MODEL_BOO, 1153, -2484, 1204, 0, -95, 0, 0x00000000, bhvBoo),
		OBJECT(MODEL_BOO, -432, -3675, -3637, 0, -57, 0, 0x00000000, bhvBoo),
		OBJECT(MODEL_BOO, 1120, -4476, -6004, 0, -173, 0, 0x00000000, bhvBoo),
		OBJECT(MODEL_BOO, 2338, -5011, -4440, 0, 96, 0, 0x00000000, bhvBoo),
		OBJECT(MODEL_BOO, 2741, -5090, -2019, 0, -135, 0, 0x00000000, bhvBoo),
		OBJECT(MODEL_BOO, 2396, -5010, 1891, 0, -135, 0, 0x00000000, bhvBoo),
		OBJECT(MODEL_BOO, -2097, -5826, 4094, 0, 158, 0, 0x00000000, bhvBoo),
		OBJECT(MODEL_BOO, -5027, -6635, 1380, 0, 95, 0, 0x00000000, bhvBoo),
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
		MARIO_POS(0x01, -90, 7718, 10040, 6158),
		OBJECT(MODEL_NONE, 7718, 10040, 6158, 0, -90, 0, 0x000A0000, bhvSpinAirborneWarp),
		TERRAIN(bbh_area_1_collision),
		MACRO_OBJECTS(bbh_area_1_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_LEVEL_SPOOKY),
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
