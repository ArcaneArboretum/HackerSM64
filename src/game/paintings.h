#ifndef PAINTINGS_H
#define PAINTINGS_H

#include <PR/ultratypes.h>
#include <PR/gbi.h>

#include "macros.h"
#include "types.h"

/// Use to properly set a GraphNodeGenerated's parameter to point to the right painting
#define PAINTING_ID(id, grp) (id | (grp << 8))

/// The default painting side length
#define PAINTING_SIZE 614.0f

enum HMCPaintingIDs {
    /*0x0*/ PAINTING_ID_HMC_COTMC,
};

enum CastlePaintingIDs {
    /*0x0*/ PAINTING_ID_CASTLE_BOB,
    /*0x1*/ PAINTING_ID_CASTLE_CCM,
    /*0x2*/ PAINTING_ID_CASTLE_WF,
    /*0x3*/ PAINTING_ID_CASTLE_JRB,
    /*0x4*/ PAINTING_ID_CASTLE_LLL,
    /*0x5*/ PAINTING_ID_CASTLE_SSL,
    /*0x6*/ PAINTING_ID_CASTLE_HMC,
    /*0x7*/ PAINTING_ID_CASTLE_DDD,
    /*0x8*/ PAINTING_ID_CASTLE_WDW,
    /*0x9*/ PAINTING_ID_CASTLE_THI_TINY,
    /*0xA*/ PAINTING_ID_CASTLE_TTM,
    /*0xB*/ PAINTING_ID_CASTLE_TTC,
    /*0xC*/ PAINTING_ID_CASTLE_SL,
    /*0xD*/ PAINTING_ID_CASTLE_THI_HUGE,
    /*0xE*/ PAINTING_ID_CASTLE_RR,
};

#define PAINTING_ID_DDD PAINTING_ID_CASTLE_DDD

enum TTMPaintingIDs {
    /*0x0*/ PAINTING_ID_TTM_SLIDE,
};

#define PAINTING_ID_NULL -1

enum PaintingGroups {
    PAINTING_GROUP_HMC,
    PAINTING_GROUP_INSIDE_CASTLE,
    PAINTING_GROUP_TTM,
    PAINTING_NUM_GROUPS,
    PAINTING_GROUP_NULL = -1,
};

enum DDDPaintingFlags {
    DDD_FLAGS_NONE              = (0 << 0), // 0x0
    DDD_FLAG_BACK               = (1 << 0), // 0x1
    DDD_FLAG_BOWSERS_SUB_BEATEN = (1 << 1), // 0x2
};

enum PaintingState {
    PAINTING_IDLE,
    PAINTING_RIPPLE,
    PAINTING_ENTERED,
};

enum RippleTriggers {
    RIPPLE_TRIGGER_PROXIMITY,
    RIPPLE_TRIGGER_CONTINUOUS,
};

enum PaintingRippleFlags {
    // Not rippling.
    RIPPLE_FLAGS_NONE  = (0 << 0), // 0x00
    // Triggers an entry ripple.
    RIPPLE_FLAG_ENTER  = (1 << 0), // 0x01
    // Triggers a passive ripple.
    RIPPLE_FLAG_RIPPLE = (1 << 1), // 0x02
};

enum PaintingXSources {
    /// Use the 1/4th part of the painting that is nearest to Mario's current floor.
    NEAREST_4TH,
    /// Use Mario's relative x position. @see painting_mario_x
    MARIO_X,
    /// Use the x center of the painting.
    MIDDLE_X,
};

enum PaintingYSources {
    /// Use Mario's relative y position. @see painting_mario_y
    MARIO_Y,
    /// Use Mario's relative z position. @see painting_mario_z
    MARIO_Z,
    /// Use the y center of the painting.
    MIDDLE_Y,
};

enum PaintingType {
    /// Painting that uses 1 or more images as a texture
    PAINTING_IMAGE,
    /// Painting that has one texture used for an environment map effect
    PAINTING_ENV_MAP
};

struct Painting {
    PaintingData id;
    /// How many images should be drawn when the painting is rippling.
    s8 imageCount;
    /// Either PAINTING_IMAGE or PAINTING_ENV_MAP
    s8 textureType;

    /// The floor Mario was on last frame
    s8 lastFloor;
    /// The floor Mario is currently on
    s8 currFloor;
    /// The floor Mario just entered
    s8 floorEntered;

    /// The painting's state, see top of paintings.c
    s8 state;

    /// The painting's rotation
    f32 pitch;
    f32 yaw;

    /// The painting's position
    Vec3f pos;

    /// Controls how high the peaks of the ripple are.
    f32 currRippleMag;
    f32 passiveRippleMag;
    f32 entryRippleMag;

    /// Multiplier that controls how fast the ripple regresses to the IDLE state.
    f32 rippleDecay;
    f32 passiveRippleDecay;
    f32 entryRippleDecay;

    /// Controls the ripple's frequency
    f32 currRippleRate;
    f32 passiveRippleRate;
    f32 entryRippleRate;

    /// The rate at which the magnitude of the ripple decreases as you move farther from the central
    /// point of the ripple
    f32 dispersionFactor;
    f32 passiveDispersionFactor;
    f32 entryDispersionFactor;

    /// How far the ripple has spread
    f32 rippleTimer;

    /// The x and y origin of the ripple
    f32 rippleX;
    f32 rippleY;

    /// Display list used when the painting is normal.
    const Gfx *normalDisplayList;
    /// Data used to map the texture to the mesh
    const s16 *const *textureMaps;

    // Texture data
    const Texture *const *textureArray;
    s16 textureWidth;
    s16 textureHeight;

    /// Display list used when the painting is rippling.
    const Gfx *rippleDisplayList;
    /// Controls when a passive ripple starts. RIPPLE_TRIGGER_CONTINUOUS or RIPPLE_TRIGGER_PROXIMITY.
    s8 rippleTrigger;

    /// The painting's transparency. Determines what layer the painting is in.
    Alpha alpha;

    /// True if Mario was under the painting's y coordinate last frame
    u8 marioWasUnder : 1;
    /// True if Mario is currently under the painting's y coordinate
    u8 marioIsUnder : 1;
    /// True if Mario just went under the painting's y coordinate on this frame
    u8 marioWentUnder : 1;

    /// Uniformly scales the painting to a multiple of PAINTING_SIZE.
    /// By default a painting is 614.0f x 614.0f
    f32 size;
};

/**
 * Contains the position and normal of a vertex in the painting's generated mesh.
 */
struct PaintingMeshVertex {
    /*0x00*/ Vec3s pos;
    /*0x06*/ Vec3c norm;
};

extern struct PaintingMeshVertex *gPaintingMesh;
extern Vec3f *gPaintingTriNorms;
extern struct Painting *gRipplingPainting;
extern s8 gDddPaintingStatus;

Gfx *geo_painting_draw(s32 callContext, struct GraphNode *node, UNUSED void *context);
Gfx *geo_painting_update(s32 callContext, UNUSED struct GraphNode *node, UNUSED Mat4 mtx);

#endif // PAINTINGS_H
