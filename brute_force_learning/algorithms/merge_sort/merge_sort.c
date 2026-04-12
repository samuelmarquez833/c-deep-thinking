#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>





int* sort(int* arrUno, int largoUno, int* arrDos, int largoDos ){
    
    int i = 0;
    int j = 0;


    int *arr = malloc ((largoUno+largoDos) * sizeof(int));
    for(int k = 0; k < (largoUno+largoDos); k++){
        // error 1: seguir incluso cuando i o j ya estaban fuera de rango
        // error 2, chat gpt te dijo qeu tenias el erro 1 y aun asi fuiste y lo hiciste tratnado de rebobinar indices
        if(i == largoUno){
            *(arr+k) = *(arrDos+j);
            // se te olvido incremetar el indice
            j++;

            continue;
        }
        if (j == largoDos){
            *(arr+k) = *(arrUno+i);
            // se te olvido incremetar el indice
            i++;
            continue;
        }
        
        if (*(arrUno+i) < *(arrDos+j)){
            *(arr+k) = *(arrUno+i);
            i++;
        } else if(*(arrDos+j) < *(arrUno+i)) {
            *(arr+k) = *(arrDos+j);
            j++;
        }


    }

    return arr;    
}





int* mergeSort(int* arr, int largo){


    if (largo == 1){
        printf("llegamos a un elemento unico\n");
        return arr;   
    }

    int mitad = largo/2;
    int largoUno = mitad;
    int largoDos = mitad;
    
    if (largo % 2 == 1){
        largoUno++;    
    }

    int *arrUno = malloc(largoUno * sizeof(int));
    int *arrDos = malloc(largoDos * sizeof(int));

    int j = 0;
    for(int i = 0; i < largo; i++){
        if (i < (largo-mitad)){
            // error 4: habias hecho un array global con todos los numeros y de ahi qeurias sacar para llenar esot en cada llamada a la funcion - nmms - ni se por que se me ocurrio hacer eso
            *(arrUno+i) = *(arr+i); 
        } 
        else{
            // error 4: habias hecho un array global con todos los numeros y de ahi qeurias sacar para llenar esot en cada llamada a la funcion - nmms - ni se por que se me ocurrio hacer eso
            *(arrDos+j) = *(arr+i);
            j++;
        }
    }




    printf("array 1\n");
    for(int i = 0; i < largoUno; i++){
        printf("%d\n", *(arrUno+i));
    }
    


    arrUno = mergeSort(arrUno, largoUno);


    printf("array 2\n");
    for(int i = 0; i < largoDos; i++){
        printf("%d\n", *(arrDos+i));
    }

    arrDos = mergeSort(arrDos, largoDos);
    

    printf("llamamos a sort\n\n");
    arr = sort(arrUno, largoUno, arrDos, largoDos);    
    return arr;

}





void main(){

    int largo = 5;
    int arr[5] = {3,7,2,9,5};
    int *aja = malloc(largo * sizeof(int)); 
    aja = mergeSort(arr, largo);

    for(int i = 0; i < largo; i++){
        printf("idx [%d]: %d\n", i, *(aja+i));
    }

}

