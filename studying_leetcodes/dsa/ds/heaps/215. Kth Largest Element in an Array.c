

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>



void swap(int *array, int idxA, int idxB){
    int bufferA = *(array+idxA);
    *(array+idxA) = *(array+idxB);
    *(array+idxB) = bufferA; 
}

void chooseAndSwap (int *nums, int prota, int protaIdx, int maxIdx){

    // un ciclo por cada vez qeu no cumpla

    int idxA = (2*protaIdx)+1;
    int idxB = (2*protaIdx)+2;
    int a = *(nums+idxA);
    int b = *(nums+idxB);

    while ((a > prota || b > prota) && idxA <= maxIdx && idxB <= maxIdx){        
        if (a >= b){
            swap(nums, protaIdx, idxA);
            protaIdx = idxA;
        }else { // b > a
            swap(nums, protaIdx, idxB);
            protaIdx = idxB;
        }
        idxA = (2*protaIdx)+1;
        idxB = (2*protaIdx)+2;
        a = (idxA <= maxIdx) ? *(nums+idxA) : 0;
        b = (idxB <= maxIdx) ? *(nums+idxB) : 0;
    }
}


void firstPart (int* nums, int numsSize){


    if(numsSize <= 1) return;
    
    int maxIdx = numsSize-1;
    int i = (numsSize/2)-1;

    int idxA = (2*i)+1;
    int idxB = (2*i)+2;

    //CLARO, AQUI NECESITO UN NUMEOR GRANDE PAR AUQE NO DE TRUE LA CONIDCION, PEOR CUAL PONGO????
    int a = (idxA <= maxIdx) ? *(nums+idxA) : 0;
    int b = (idxB <= maxIdx) ? *(nums+idxB) : 0;

    if (idxA > maxIdx){
        i--;
    } if(2*i+2 == numsSize){
        
        if(*(nums+((2*i)+1)) > *(nums+i)){
            swap(nums, (2*i)+1, i);
        }
    } else{
    
        if(a >= b ){
            if(a > *(nums+i)){
                swap(nums, (2*i)+1, i);
            }
        } else{
            if(b > *(nums+i)){
                swap(nums, (2*i)+2, i);
            }
        }
    }


    i--;

    while(i >= 0){
        chooseAndSwap(nums, *(nums+i), i, maxIdx);
        i--;
    }



}












void secondPart (int* nums, int numsSize){

    if(numsSize <= 1) return;
    
    int maxIdx = numsSize-1;

    int protaIdx = 0;
    int prota = nums[protaIdx];
    printf("El prota es: %d\n", prota);
    
    int idxA = (2*protaIdx)+1;
    int idxB = (2*protaIdx)+2;
    int a = *(nums+idxA);
    int b = *(nums+idxB);

    while ((a > prota || b > prota) && idxA <= maxIdx && idxB <= maxIdx){        
        if (a >= b){
            swap(nums, protaIdx, idxA);
            protaIdx = idxA;
        }else { // b > a
            swap(nums, protaIdx, idxB);
            protaIdx = idxB;
        }
        idxA = (2*protaIdx)+1;
        idxB = (2*protaIdx)+2;
        a = (idxA <= maxIdx) ? *(nums+idxA) : 0;
        b = (idxB <= maxIdx) ? *(nums+idxB) : 0;
    }

}







int findKthLargest(int* nums, int numsSize, int k) {


    if (k == numsSize){
        int numeroMasPequenio = nums[0];
        for (int i = 0; i < numsSize; i++){
            if (nums[i] < numeroMasPequenio){
                numeroMasPequenio = nums[i];
            }
        } 
        return numeroMasPequenio;
    }

    firstPart(nums, numsSize);

    while(k > 1){
        nums[0] = nums[(numsSize-1)];
    
        numsSize -= 1;
        secondPart(nums, numsSize);
        k--;
    }

    
    printf("final: %d\n", nums[0]);

    return nums[0];
}




void main (){

    int k = 2;
     int numsSize = 6;
    int nums[6] = {3,2,1,5,6,4};

    int out = findKthLargest(nums, numsSize, k);

}





















