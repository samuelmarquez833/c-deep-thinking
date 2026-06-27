
#include <stdio.h>
#include <stdlib.h>




int twoSum(int* nums, int numsSize, int target) {

    for (int i = 0; i < numsSize; i++){
        for (int j = i; j < numsSize; j++){
            if (nums[i] + nums[j] == target){
                printf("nums[%d], nums[%d] ", i, j);
                return 0;
            }
        }
    }
    
}

int main (){

    int length = 4;
    int arr[4] = {2, 7, 11, 15};
    int target = 9;
    int aja = twoSum(arr, length, target);

    return 0;
}
