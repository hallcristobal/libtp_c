#ifndef LIB_TP_WARPING
#define LIB_TP_WARPING

#include <stdint.h>

struct Entrance {
    uint8_t stage[8];
    uint8_t _p0;
    uint8_t spawn;
    uint8_t room;
    uint8_t state;
};
static_assert(sizeof(Entrance) == 12);

struct Warp {
    Entrance entrance;
    uint8_t _p0[2];
    bool enabled;
};
static_assert(sizeof(Warp) == 15);

#endif  // LIB_TP_WARPING