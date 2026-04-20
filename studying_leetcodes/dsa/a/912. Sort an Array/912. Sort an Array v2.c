#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>




int* quickSort(int* nums, int start, int end) {


    


    int size = end - start + 1;
    if (size <= 1){
        return nums;
    }


    int mid = start + (end - start)/2;

    int temp = nums[mid];
    nums[mid] = nums[end];
    nums[end] = temp;

    int pivot = nums[end];

    int i = start;
    int j = end-1;

    while(i <= j){
        while (i <= j && nums[i] < pivot) {
            i++;
        }

        while (i <= j && nums[j] > pivot) {
            j--;
        }


        if (i <= j){    
            int buffer = *(nums+i);
            *(nums+i) = *(nums+j);
            *(nums+j) = buffer;
            i++;
            j--;
        }
    }

    *(nums+end) = *(nums+i);
    *(nums+i) = pivot;


    
    //int *arrUno = malloc(largoUno * sizeof(int));
    //int *arrDos = malloc(largoDos * sizeof(int));

    /*
    for(int k = 0; k < largoUno; k++){
        *(arrUno+k) = *(nums+k);
    }

    for(int k = 0; k < largoDos; k++){
        *(arrDos+k) = *(nums+v);
        v++;
    }*/

    // hago esto por una cosa de leetcode
    nums = quickSort(nums, start, i-1);
    nums = quickSort(nums, i+1, end);
    
    //int b = 0;
    /* ya no  necesito esto pq era para escribir
    for(int k = 0; k < numsSize; k++){
        if(k < i){
            *(nums+k) = *(arrUno+k);
        } else if(k == i){
            continue;
        } else if(k > i){
            *(nums+k) = *(arrDos+b);
            b++;
        }
    }*/

    /* para que hice esto? que pedo, bueno no importa, si queires dime
    int h = 0;
    while (h < numsSize){
        h++;
    }*/

    return nums;

}



int* sortArray(int* nums, int numsSize, int* returnSize) {

    
    *returnSize = numsSize;

    int end = numsSize - 1; 
    nums = quickSort(nums, 0, end);

    return nums;

}





void main(){

    int returnSize = 6;
    int largo = 6;
    int nums[6] = {5,1,1,2,0,0};
    int *sorted = malloc(largo * sizeof(int));
    sorted = sortArray(nums, largo, &returnSize);

    int i = 0;
    while (i < largo){
        printf("%d\n", *(sorted+i));
        i++;
    }
    

}

