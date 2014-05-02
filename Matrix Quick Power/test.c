#include <stdlib.h>
#include <math.h>
#include "matrix_quick_power.h"

int main(int argc, char *argv[]){
    int m1[]={1,1,0,1};
    int m2[]={2,2,0,2};
    int tot=sizeof(m1)/sizeof(int);
    int sz=(int)sqrt((double)tot);
    int *ret=malloc(tot*sizeof(int));
    multiply(m1, m2, sz, ret);
    disp(ret, sz);
    free(ret);
    return 0;    
}

