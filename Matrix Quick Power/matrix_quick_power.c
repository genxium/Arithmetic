#include <stdio.h>
#include <string.h>
#include "matrix_quick_power.h"

const long MAXN=351;
const long MOD=1000000007;

void multiply(int* obj_1, int* obj_2,  int sz, int* ret){
	int i,j,k; long long tmp;
	memset(ret, 0, sz*sz*sizeof(int));
	for(i=0;i<sz;i++)
		for(j=0;j<sz;j++){
			for(k=0;k<sz;k++){
				tmp=(long long)ret[i*sz+j]+((long long)obj_1[i*sz+k]*(long long)obj_2[k*sz+j])%MOD;
				ret[i*sz+j]=(int)(tmp%MOD);
			}
		}
}

void mat_pow(int* M, int sz, long r, int* ret){
    int* tmp_mat=(int*)malloc(sz*sz*sizeof(int));
	memset(ret, 0, sz*sz*sizeof(int));
	for(int i=0;i<sz;i++) ret[i*sz+i]=1;
	while(r){
		if(r&1){ 
			memcpy(tmp_mat, ret, sz*sz*sizeof(int));
			multiply(tmp_mat, M, sz, ret); 
		}
		multiply(M, M, sz, tmp_mat);
		memcpy(M, tmp_mat, sz*sz*sizeof(int));
		r>>=1;
	}
    free(tmp_mat);
}

void disp(int* mat, int sz){
	for(int i=0;i<sz;i++,puts("")){
		for(int j=0;j<sz;j++){
			printf("%d\t", mat[i*sz+j]);
		}
	}
}
