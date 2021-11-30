#include "matmul.hpp"

using namespace std;


int main()
{


	float C[n][n];
	float A[n][n] ={
            {1, 1,3},
            {2, 2,3},
			{2, 2,3}
        };
	float B[n][n]={
            {1, 1,3},
            {2, 2,3},
			{2, 2,3}
        };





   int stage=0;


	matmul(A,B,C);




   for (int i = 0; i < n ; i++){
	   for (int j = 0; j < n ; j++){
   cout << C[i][j]<<" " ;
          		 	    	        }
          		 cout<<"\n";


   }
}
