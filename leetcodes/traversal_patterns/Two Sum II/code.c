#include <stdio.h>
#include <stdlib.h>

int* twoSum(int* numbers, int numbersSize, int target, int* returnSize){
    int* positions = malloc(2 * sizeof(int));
    int left = 0; 
    int right = numbersSize-1;
    int sumaActual = 0;
    while (left < right){
        sumaActual = *(numbers+left) + *(numbers+right); 
        if (sumaActual == target){
            positions[0] = left + 1;
            positions[1] = right + 1;
            *returnSize = 2;             
            return positions;
        } else if(sumaActual > target){
            right--;
        } else if(sumaActual < target){
            left++;
        }
    }
    free(positions);
    return NULL;
}

int main() {

    int numbersSize = 5;
    int target = 8;
    int numbers[] = {-7,-3,2,5,11};
    // Expected: [2,5]
    int returnSize = 0;   
    
    int *output = twoSum(numbersSize, numbers, target, &returnSize);

    for (int i = 0; i < 2; i++){
        printf("%d\n", output[i]);
    }

    return 0;
}
