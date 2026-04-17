#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>




int* sortArray(int* nums, int numsSize, int* returnSize) {

    *returnSize = numsSize;



    //a ver, para poder llegar a qeu el largo sea cero primeor el largo tuvo que haber sido uno
    // si lo corto en 1, 
    // por que habria de evaluar si es 0 tambien?
    // para un array de 4 y 3, no pasa nada, lo puedo medir bien todavia
    // un array de 2, que verga pasa? o sea no hya i no hay j, es una sola comparaicon literal, enotnces es solo poner pivote en su lugar correcto y retornarl
    // entonces no puedo lleagr a un largo de uno, a menos que, digamos, el array lo separo y el pivote me queda en la poscion 1, enontces  pasar como arr lo que esta a la izq o sea un solo numero
    //peor lo retonra y claro.... (ahora todo tiene sentido), si pusieras el pivote  en poscion cero, ps fijate que cando lo pases no hay nada que evaluar para el orden asi justo como en el caso del uno
    if (numsSize <= 1){
        return nums;
    }

    int pivotIdx = numsSize-1;
    int pivot = *(nums+pivotIdx); 
    int i = 0;
    int j = pivotIdx-1;

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

    *(nums+pivotIdx) = *(nums+i);
    *(nums+i) = pivot;

    int largoUno = i;
    int v = i+1;
    int largoDos = numsSize-v;

    int *arrUno = malloc(largoUno * sizeof(int));
    int *arrDos = malloc(largoDos * sizeof(int));

    for(int k = 0; k < largoUno; k++){
        *(arrUno+k) = *(nums+k);
    }

    for(int k = 0; k < largoDos; k++){
        *(arrDos+k) = *(nums+v);
        v++;
    }

    // hago esto por una cosa de leetcode
    int tmp1, tmp2;
    arrUno = sortArray(arrUno, largoUno, &tmp1);
    arrDos = sortArray(arrDos, largoDos, &tmp2);
    int b = 0;
    
    for(int k = 0; k < numsSize; k++){
        if(k < i){
            *(nums+k) = *(arrUno+k);
        } else if(k == i){
            continue;
        } else if(k > i){
            *(nums+k) = *(arrDos+b);
            b++;
        }
    }

    int h = 0;
    while (h < numsSize){
        h++;
    }

    return nums;

}




void main(){

    int returnSize = 4;
    int largo = 4;
    int nums[4] = {5,2,3,1};
    int *sorted = malloc(largo * sizeof(int));
    sorted = sortArray(nums, largo, &returnSize);

    int i = 0;
    while (i < largo){
        printf("%d\n", *(sorted+i));
        i++;
    }
    

}

