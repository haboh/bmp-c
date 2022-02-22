#ifndef HW_01_BMP_H
#define HW_01_BMP_H

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

typedef struct __bmp bmp_t;

typedef struct {
    int32_t x, y;
} bmp_pos_t;

typedef struct {
    uint32_t width, height;
} bmp_size_t;

typedef struct {
    bmp_pos_t pos;
    bmp_size_t size;
} bmp_rect_t;

typedef struct {
    uint8_t b, g, r;
} __attribute__((packed)) rgb_triple_t;

typedef enum {
    BMP_OK,
    BMP_ERR_MEM_ALLOC,
    BMP_ERR_FILE_READ,
    BMP_ERR_FILE_WRITE,
    BMP_ERR_ILLEGAL_ARGS
} bmp_err_t;

typedef enum {
    BMP_ROT_NONE,
    BMP_ROT_CLOCKWISE_90
} bmp_rot_t;

bmp_err_t load_bmp(bmp_t **bmp, FILE *in_file);
bmp_err_t save_bmp(const bmp_t *bmp, FILE *out_file);
bmp_err_t crop_bmp(bmp_t **dst, const bmp_t *src, bmp_rect_t region);
bmp_err_t clone_image(bmp_t **dst, const bmp_t *src);
bmp_err_t rotate_bmp(bmp_t **dst, const bmp_t *src, bmp_rot_t rot);

bmp_err_t get_pixel_in_bmp(const bmp_t *bmp, bmp_pos_t pos, rgb_triple_t **pxl);

void free_bmp(bmp_t *bmp);

#endif //HW_01_BMP_H