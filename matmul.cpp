#include "matmul.hpp"

void axis2Mat(axis_t *src, T A[N]) {

  union {
    float ival;
    T oval;
  } converter;

  for (int i = 0; i < N; i++) {

      converter.ival = src[i].data;
      A[i] = converter.oval;

  }
}


void Mat2axis(T buff[out_len], axis_t *dst) {


  union {
    float oval;
    T ival;
  } converter;

  int tmp = 0;
  for (int i = 0; i < out_len; i++) {



      if (i == out_len-1) {
        tmp = 1;
      }

      dst[i].last = tmp;
      converter.ival = buff[i];
      dst[i].data = converter.oval;
    }

}

void matmul(T a[n][n], T b[n][n], T out[n][n]) {

  for (int i = 0; i < n; ++i)

    for (int j = 0; j < n; ++j) {
      T sum = 0;

      for (int k = 0; k < n; ++k)
        sum += a[i][k] * b[k][j];
      out[i][j] = sum;
    }

  return;

}

void smul(axis_t *INPUT, axis_t *OUTPUT,int length){

#pragma HLS INTERFACE s_axilite port=length bundle=CTRL
#pragma HLS INTERFACE axis depth=50 port=OUTPUT
#pragma HLS INTERFACE axis depth=50 port=INPUT

//	T A[N];
	T buff[out_len];
	T AB[N];
	T mat_A[n][n];
	T mat_B[n][n];
	T C[n][n];

	axis2Mat(INPUT, AB);

	int sA = 0;
	  for (int i = 0; i < n; i++) {
		  for (int j = 0; j < n; j++){

			  mat_A[i][j]=AB[sA];

			  sA+=1;
		  }

	  }

	  int sB = out_len;
	    for (int i = 0; i < n; i++) {
	  	  for (int j = 0; j < n; j++){

	  		  mat_B[i][j]=AB[sB];
	  		  sB+=1;
	  	  }

	    }

	    matmul(mat_A,mat_B,C);

	int sout = 0;

	  for (int i = 0; i < n; i++) {
	  	  for (int j = 0; j < n; j++){

	  		buff[sout]=C[i][j];
	  		sout+=1;
	  	  }
	    }

	Mat2axis(buff, OUTPUT);



}
