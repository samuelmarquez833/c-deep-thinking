#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int searchInsert(int *nums, int numsSize, int target) {
    int left = 0;
    numsSize = numsSize - 1; 
    int right = numsSize;
    int medio = (int)floor(numsSize/2);
    
    while (left <= right){
        
        if (target == nums[medio]){
            //printf("encontramos el indice: %d\n", medio);
            return medio;
        } else if(target > nums[medio]){
            left = medio+1;
        } else if(target < nums[medio]){
            right = medio-1;
        }
        medio = left + (int)floor((right-left)/2);
    }

    //printf("left quedo en: %d\n", left);
    //printf("right quedo en: %d\n", right);
    //printf("este wey deberia de ir en el lugar: %d\n", left);
    return left;
}


// ESTE CODIGO ES SOLO PARA ENCONTRAR Y DECIR SI ESTA O NO EN EL ARRAY
int main() {
    int numsSize = 4;
    int nums[] = {1,3,5,6};
    int target = 2;
    searchInsert(nums, numsSize, target);
    return 0;
}
