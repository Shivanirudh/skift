#pragma once

/* Copyright © 2018-2019 N. Van Bossuyt.                                      */
/* This code is licensed under the MIT License.                               */
/* See: LICENSE.md                                                            */

#define NULL ((void *)0)

#define bool _Bool
#define true 1
#define false 0

typedef unsigned int size_t;

typedef void s0;
typedef char s8;
typedef short s16;
typedef long s32;
typedef long long s64;

typedef void u0;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long u32;
typedef unsigned long long u64;

typedef char byte;
typedef unsigned char ubyte;
typedef unsigned char uchar;
typedef unsigned short wchar;
typedef unsigned short ushort;
typedef unsigned int uint;

typedef signed char int8_t;
typedef short int16_t;
typedef long int32_t;
typedef long long int64_t;

typedef unsigned char uint8_t;
typedef unsigned short uint16_t;
typedef unsigned long uint32_t;
typedef unsigned long long uint64_t;

typedef long intptr_t;
typedef unsigned long uintptr_t;

#ifndef __PACKAGE__
#define __PACKAGE__ "(NULL)"
#endif

#ifndef __FILENAME__
#define __FILENAME__ "(NULL)"
#endif

#ifndef __COMMIT__
#define __COMMIT__ "(NULL)"
#endif

#define PACKED(x) x __attribute__((packed))
#define ALIGNED(x, align) x __attribute__((aligned(align)))

#define UNUSED(x) (void)(x)
#define MALLOC(type) ((type *)malloc(sizeof(type)))

#define ARRAY_SIZE(array) (sizeof(array) / sizeof(array[0]))
#define FLAG(__i) (1 << (__i))

#define offsetof(st, m) ((size_t) & (((st *)0)->m))


typedef void *va_list;

#define _INTSIZEOF(n) ((sizeof(n) + sizeof(int) - 1) & ~(sizeof(int) - 1))

#define va_start(ap, v) (ap = (va_list)&v + _INTSIZEOF(v))
#define va_arg(ap, t) (*(t *)((ap += _INTSIZEOF(t)) - _INTSIZEOF(t)))
#define va_end(ap) (ap = (va_list)0)

void *malloc(size_t size);
void *realloc(void *p, size_t size);
void *calloc(size_t, size_t);
void free(void *);