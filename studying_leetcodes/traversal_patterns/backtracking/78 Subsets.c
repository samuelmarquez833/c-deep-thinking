#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>



int *out[] = {};
int indiceActualDelOutput = 0;


void backtrack(int* nums, int numsSize, int* state, int idx){

    *(out+indiceActualDelOutput) = state;

    for (int i = idx+1; i < numsSize; i++){
        *(state+i) = nums[i];
        backtrack(nums, numsSize, state, i);
        *(state+i) = 0;
    }
    return;

}


int** subsets(int* nums, int numsSize/*, int* returnSize, int** returnColumnSizes*/) {

    int state[numsSize] = {};
    int initialIdx = -1;
    backtrack(nums, numsSize, state, initialIdx);

    for (int i = 0; i < 10; i++){
        printf("i: %d\n", *(out+i));
    }

    return out;

}




void main(){

    int options[] = {1,2,3};
    int options_length = 3;
    //int returnSize = ?
    //int returnColumnSizes = ?

    subsets(options, options_length/*, returnSize, returnColumnSizes*/);

}