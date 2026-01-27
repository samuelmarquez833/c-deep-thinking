#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>


void bubble (int arr[], int length){    

    int contador = 0;
    while(true){
        contador = 0;
        for(int i = 0; i < length-1; i++){
            if(arr[i] > arr[i+1]){
                int buffer = arr[i];
                arr[i] = arr[i+1];
                arr[i+1] = buffer;
                contador++;
            }
        }
        if (contador == 0) break;
    }


    for (int i = 0; i < length; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");


}


int main (){

    int length = 4;
    int arr[4] = {7,3,5,2};
    
    for(int i = 0; i < length; i++){
        printf("%d", arr[i]);
    }
    
    printf("\n");
    bubble(arr, length);

    
    return 0;
}
