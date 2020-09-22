#ifndef LIB_TP_SYSTEM
#define LIB_TP_SYSTEM

#include <stdint.h>
#include <stdio.h>
#include "addrs.h"
#include "tp.h"

typedef void (*tp_memset_t)(void *addr, int value, uint32_t size);
typedef void *(*tp_memalign_t)(int32_t align, uint32_t size);
typedef void *(*tp_memcpy_t)(void *dest,void *src,size_t size);
typedef void (*tp_free_t)(void *addr);
typedef int (*tp_getLayerNo_t)(const char *stageName, int roomId, int layerOverride);
//typedef uint32_t (*tp_strlen_t)(const char *string);
typedef void (*tp_osReport_t)(const char *string, ...);
typedef void (*tp_getSave_t)(TP::GameInfo *gameinfo, int32_t areaID);
typedef void (*tp_putSave_t)(TP::GameInfo *gameinfo, int32_t areaID);


#define tp_memset ((tp_memset_t)tp_memset_addr)
#define tp_memalign ((tp_memalign_t)tp_memalign_addr)
#define tp_memcpy ((tp_memcpy_t)tp_memcpy_addr)
#define tp_free ((tp_free_t)tp_free_addr)
#define tp_getLayerNo ((tp_getLayerNo_t)tp_getLayerNo_addr)
#define tp_getSave ((tp_getSave_t)tp_getSave_addr)
#define tp_putSave ((tp_putSave_t)tp_putSave_addr)

//#define tp_strlen ((tp_strlen_t)tp_strlen_addr)

#define malloc(x) tp_memalign(-4, x)
#define free tp_free
//#define strlen tp_strlen

#define tp_osReport ((tp_osReport_t)tp_osReport_addr)

#endif  // LIB_TP_SYSTEM