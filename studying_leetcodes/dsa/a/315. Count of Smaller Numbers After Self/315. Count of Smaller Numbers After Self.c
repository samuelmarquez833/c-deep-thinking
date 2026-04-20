#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>


int *out;
int* merge (int *nums, int start, int end){

    int size = end-start+1;
    if (size <= 1){
        return nums;
    }

    int mitad = size / 2;
    int finalUno = (start+mitad)-1;
    int startDos = finalUno+1;

    int* arrayUno = merge(nums, start, finalUno); 
    for (int i = 0; i < size; i++){
        printf("Numeros mitad derecha: %d\n", *(arrayUno+i));
    }
    
    int* arrayDos = merge(nums, startDos, end); 
    for (int i = 0; i < size; i++){
        printf("Numeros mitad izquierda: %d\n", *(arrayDos+i));
    }



}


int* countSmaller(int* nums, int numsSize) {
    
    out = malloc(numsSize * sizeof(int));
    for (int i = 0; i < numsSize; i++){
        *(out+i) = 0;
    }

    int end = numsSize-1;
    merge(nums, 0, end);

}

void main(){

    int largo = 4;
    int nums[4] = {5,2,6,1};

    int *aja = malloc(largo * sizeof(int));
    aja = countSmaller(nums, largo);

}