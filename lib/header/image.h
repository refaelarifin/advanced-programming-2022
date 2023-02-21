#ifndef image
#define image

#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include "error.h"

#define DATA_PIXELS_INTENSITY 255
#define BG_PIXELS_INTENSITY 0

typedef struct Image_ {
  uint8_t* img;
  int nx; 
  int ny;
} Image;

typedef Image* IMAGE;

// Read Image Data sent from python. Image is a serial of bits instead of matrix
IMAGE python_read_image(uint8_t* data, int nx, int ny);

// read serial image using matrix row and colm pos (i and j)
uint8_t image_read_serial(uint8_t* img, int nx, int i, int j);

// write serial image using matrix row and colm pos (i and j)
void image_write_serial(uint8_t* img, int nx, int i, int j, uint8_t new_pixel_value);

// Change image in matrix form to serial form
uint8_t* image_to_serial(uint8_t** img, int nx, int ny);

// change image from serial to matrix
uint8_t** serial_to_image(uint8_t* img, int nx, int ny);

/* 
  copy images to new frames
  dest must have dimension greater or equal to src
*/
uint8_t** image_copy(uint8_t** dest, uint8_t** src, int nx, int ny);
#endif

