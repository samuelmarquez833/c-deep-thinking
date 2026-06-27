#include <stdlib.h>
#include <stdio.h>

/* habia un detalle del indice de inserccion, anterior que la caga
int main(){
    int length = 5;
    int arr[5] = {3, 8, 2, 6, 7};
    int pivote = 7;
    int low = 0;
    int high = 4;
    for (int i = 0; i < length; i++){
        printf("%d", arr[i]);
    }
    printf("\n");
    int i = 0;
    for (int j = 0; j < length-1; j++){
        if (arr[j] < pivote){
            int buffer = arr[j-1];
            arr[j-1] = arr[j];
            arr[j] = buffer;
            i++;
        } 
    }
    int buffer = arr[i];
    arr[i] = arr[high];
    arr[high] = buffer;

    for (int i = 0; i < length; i++){
        printf("%d", arr[i]);
    }
    return 0;
}
    */




// corregido
// se trata del ultimo elemento menor, 

#include <stdio.h>

int main() {

    int arr[5] = {9, 10, 2, 6, 7};
    int length = 5;

    int low = 0;
    int high = 4;
    int pivote = arr[high];

    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivote) {
            i++;

            int buffer = arr[i];
            arr[i] = arr[j];
            arr[j] = buffer;
        }
    }

    // colocar pivote
    int buffer = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = buffer;

    // imprimir resultado
    for (int k = 0; k < length; k++) {
        printf("%d ", arr[k]);
    }

    return 0;
}
