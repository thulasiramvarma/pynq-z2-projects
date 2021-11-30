#ifndef __STREAMMUL_HPP
#define __STREAMMUL_HPP

#include "ap_int.h"

#define N 18
#define out_len 9
#define n 3

typedef float T;
struct axis_t{
	T data;
	ap_int<1> last;
};

//void matmul(T a[n][n], T b[n][n], T out[n][n]);
void smul(axis_t *INPUT, axis_t *OUTPUT,  int length);

#endif
