#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>



int **out;
int indiceActualDelOutput = 0;

// for leetcode 
int *sizes;


void backtrack(int* nums, int numsSize, int* state, int idx, int size){

    
    out[indiceActualDelOutput] = malloc(size * sizeof(int));
    for (int i = 0; i < size; i++){ 
        out[indiceActualDelOutput][i] = state[i];;
    }
    // for leetcode
    sizes[indiceActualDelOutput] = size;
    
    indiceActualDelOutput++;
    

    for (int i = idx+1; i < numsSize; i++){
        *(state+size) = nums[i];
        backtrack(nums, numsSize, state, i, size+1);
        // No need to "pop" the state since `size` controls the effective length
        // of the current subset. Future writes overwrite previous values.
        //*(state+i) = 0;
    }
    return;
}



int** subsets(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {

    // for leetcode - so that i can return it afterwards
    indiceActualDelOutput = 0;

    // we must mandatory define its length, over here
    int total = 1 << numsSize;
    out = malloc(total * sizeof(int*));

    // for prerequisiteleetcode
    sizes = malloc(total * sizeof(int));
    
    int state[numsSize] = {};
    int initialIdx = -1;
    int size = 0;
    backtrack(nums, numsSize, state, initialIdx, size);


    // for leetcode
    *returnSize = indiceActualDelOutput;
    *returnColumnSizes = sizes;
    return out;
}

//// Note: In LeetCode, this function may be called multiple times.
// If global or static variables are not properly reset between calls,
// it can lead to incorrect behavior or runtime errors.
// Therefore, it is important to reinitialize any shared state
// (e.g., counters, arrays, or pointers) before each execution.
// Plus the fuction firm in leetcode is different but it works still with a simplier firm (that i used when i solved the problem)



void main(){

    int options[] = {1,2,3};
    int options_length = 3;

    int total = 1 << numsSize;
    int *sizes = malloc(total * sizeof(int));

    subsets(options, options_length, total, sizes);

}