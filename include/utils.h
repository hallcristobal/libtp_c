#ifndef LIB_TP_UTIL
#define LIB_TP_UTIL

struct Vec2 {
    float x, y;
};
static_assert(sizeof(Vec2) == 0x8);

struct Vec3 {
    float x, y, z;
};
static_assert(sizeof(Vec3) == 0xC);

struct CameraMatrix {
    Vec3 target;
    Vec3 pos;
};
static_assert(sizeof(CameraMatrix) == 0x18);

#endif  // LIB_TP_UTIL