#ifndef MY_PLATFORM_TYPES_H_
#define MY_PLATFORM_TYPES_H_

#include <stdint.h>

#define CPU_TYPE            CPU_TYPE_32
#define CPU_BIT_ORDER       MSB_FIRST
#define CPU_BYTE_ORDER      HIGH_BYTE_FIRST

#ifndef FALSE
#define FALSE (unsigned char)0 // 0 -> Indicate to false
#endif

#ifndef TRUE
#define TRUE (unsigned char)1 // 1 -> Indicate to true
#endif


typedef unsigned char boolean;

typedef unsigned char uint8_t;
typedef signed char   sint8_t;

typedef unsigned short int uint16_t;
typedef signed short int   sint16_t;

typedef unsigned int uint32_t;
typedef signed int   sint32_t;

typedef unsigned long long uint64_t;
typedef signed long long   sint64_t;

typedef float  float32;
typedef double float64;

typedef volatile unsigned char vboolean;

typedef volatile unsigned char vuint8_t;
typedef volatile signed char   vsint8_t;

typedef volatile unsigned short int vuint16_t;
typedef volatile signed short int   vsint16_t;

typedef volatile unsigned int vuint32_t;
typedef volatile signed int   vsint32_t;

typedef volatile unsigned long long vuint64_t;
typedef volatile signed long long   vsint64_t;

typedef volatile float  vfloat32;
typedef volatile double vfloat64;

#endif