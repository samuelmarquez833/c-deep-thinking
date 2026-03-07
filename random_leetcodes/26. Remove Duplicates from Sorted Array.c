#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


void imprimirArray(int* array, int length){
    for (int i = 0; i < length; i++){
        printf("%d", array[i]);
    }
}

bool contains(int* array, int val, int length){
    for (int i = 0; i < length; i++){
        if(array[i] == val){
            return true;
        }
    }
    return false;
}


int removeDuplicates(int* nums, int numsSize) {
    
    int pollon[numsSize];
    
    // OOOOJOOOOO estuvo demas llenar pollon inicalmente con valores, podrias dejarlo arriba con ese largo y ya esta, solo escrbies en los que vas a usar abajo y listo, no lo borro para recordadr el error
    // para llenar a pollon con -1
    for (int i = 0; i < numsSize; i++) {
       pollon[i] = -1;
    }
    
    /*
    ahora pollon es una lista que se ve asi
     {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1}
    */
    
    
    /* para aniadir solo los elementos unicos a pollon 
    (fijate que el if lo que hace es mandar a la 
    verga un elemento ya usado)
    por que dice si pollon no contiene el valor actual de nums (nums[k]) aniadelo
    es todo
    */
    int writeIndex  = 0;
    for(int k = 0; k < numsSize; k++){
        // OOOOJOOOO:
        // como tercer parametro deberia de ser writteIndex para que
        // contains no vea todo lo que hay dentro de pollon sino hasta 
        // donde le incumbe. deje numsize para que veas el error
        // de este modo, como ya contains solo ve a 
        if(!contains(pollon, nums[k], numsSize)){
            pollon[writeIndex] = nums[k];
            writeIndex++;    
        }
    }

    imprimirArray(pollon, numsSize);
    
    return 0;
}





int main()
{

    int arr[10] = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    int length = 10;
    
    removeDuplicates(arr, length);

    return 0;
}


