#pragma once

/* Copyright © 2018-2019 N. Van Bossuyt.                                      */
/* This code is licensed under the MIT License.                               */
/* See: LICENSE.md                                                            */

#include <libmath/math.h>
#include <libgraphic/color.h>
#include <libgraphic/shape.h>

typedef enum
{
    BITMAP_FILTERING_NEAREST,
    BITMAP_FILTERING_LINEAR,
} BitmapFiltering;

typedef struct
{
    int width;
    int height;
    BitmapFiltering filtering;

    color_t pixels[];
} Bitmap;

Bitmap *bitmap_create(uint width, uint height);

void bitmap_destroy(Bitmap *this);

Bitmap *bitmap_load_from(const char *path);

int bitmap_save_to(Bitmap *bmp, const char *path);

void bitmap_set_pixel(Bitmap *bmp, point_t p, color_t color);

color_t bitmap_get_pixel(Bitmap *bmp, point_t p);

color_t bitmap_sample(Bitmap *bmp, rectangle_t src_rect, float x, float y);

void bitmap_blend_pixel(Bitmap *bmp, point_t p, color_t color);

rectangle_t bitmap_bound(Bitmap *bmp);