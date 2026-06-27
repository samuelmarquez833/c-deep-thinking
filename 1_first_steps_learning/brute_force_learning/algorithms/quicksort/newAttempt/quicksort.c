#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>








int* quickSort(int* arr, int largo){
    

    int pivotIdx = largo-1;
    int pivot = *(arr+pivotIdx);
    
    // no manejabnas cual es igual a 0, lo cual peude pasar perfectamente
    if (largo <= 1){
        return arr;
    }


    
    int i = 0;
    int j = pivotIdx-1;
    while (j >= i){
        /*if (*(arr+i) < pivot){
            i++;
        }
        if (*(arr+j) > pivot ){
            j--;
        }

        if(*(arr+i) > pivot && *(arr+j) < pivot ){
            int buffer = *(arr+i);
            *(arr+i) = *(arr+j);
            *(arr+j) = buffer;
            i++;
            j--;
        }*/
        //#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>








int* quickSort(int* arr, int largo){
    

    int pivotIdx = largo-1;
    int pivot = *(arr+pivotIdx);
    
    // no manejabnas cual es igual a 0, lo cual peude pasar perfectamente
    if (largo <= 1){
        return arr;
    }


    
    int i = 0;
    int j = pivotIdx-1;
    while (j >= i){
        // Error principal
        // 
        /*if (*(arr+i) < pivot){
            i++;
        }
        if (*(arr+j) > pivot ){
            j--;
        }

        if(*(arr+i) > pivot && *(arr+j) < pivot ){
            int buffer = *(arr+i);
            *(arr+i) = *(arr+j);
            *(arr+j) = buffer;
            i++;
            j--;
        }*/
        
        while (arr[i] < pivot) {
            i++;
        }
        while (arr[j] > pivot) {
            j--;
        }
        if (i <= j) {
            int buffer = *(arr+i);
            *(arr+i) = *(arr+j);
            *(arr+j) = buffer;
            i++;
            j--;
        }
    }

    *(arr+pivotIdx) = *(arr+i);
    *(arr+i) = pivot;
    



    int largoUno = i;
    int *arrUno = malloc(largoUno * sizeof(int));
    for (int k = 0; k < largoUno; k++){
        *(arrUno+k) = *(arr+k); 
    }

    arrUno = quickSort(arrUno, largoUno);

    /*mi problema
    confiar en j después de la partición*/
    
    int largoDos = (largo - i)-1;
    int *arrDos = malloc(largoDos * sizeof(int));
    int start = i + 1;
    for (int k = 0; k < largoDos; k++){
        arrDos[k] = arr[start + k];
    }

    // habias hecho la recursion del lado derecho excatmante igual que la del lado izquierdo
    arrDos = quickSort(arrDos, largoDos);

    int a = 0; 
    int b = 0;
    for (int k = 0; k < largo; k++){
        if (k < i){
            *(arr+k) = *(arrUno+a);
            a++;
        } else if (k > i){
            *(arr+k) = *(arrDos+b);
            b++;
        }
    }

    // se te olvido poner esto
    return arr;


}





void main(){

    int largo = 5;
    int *aja = malloc(largo * sizeof(int)); 
    int arr[5] = {3,7,2,9,5};
    aja = quickSort(arr, largo);

    for (int i = 0; i < largo; i++){
        printf("%d\n", *(aja+i));
    }

    


}


        while (arr[i] < pivot) {
            i++;
        }
        while (arr[j] > pivot) {
            j--;
        }
        if (i <= j) {
            int buffer = *(arr+i);
            *(arr+i) = *(arr+j);
            *(arr+j) = buffer;
            i++;
            j--;
        }
    }

    *(arr+pivotIdx) = *(arr+i);
    *(arr+i) = pivot;
    



    int largoUno = i;
    int *arrUno = malloc(largoUno * sizeof(int));
    for (int k = 0; k < largoUno; k++){
        *(arrUno+k) = *(arr+k); 
    }

    arrUno = quickSort(arrUno, largoUno);

    /*mi problema
    confiar en j después de la partición*/
    
    int largoDos = (largo - i)-1;
    int *arrDos = malloc(largoDos * sizeof(int));
    int start = i + 1;
    for (int k = 0; k < largoDos; k++){
        arrDos[k] = arr[start + k];
    }

    // habias hecho la recursion del lado derecho excatmante igual que la del lado izquierdo
    arrDos = quickSort(arrDos, largoDos);

    int a = 0; 
    int b = 0;
    for (int k = 0; k < largo; k++){
        if (k < i){
            *(arr+k) = *(arrUno+a);
            a++;
        } else if (k > i){
            *(arr+k) = *(arrDos+b);
            b++;
        }
    }

    // se te olvido poner esto
    return arr;


}





void main(){

    int largo = 5;
    int *aja = malloc(largo * sizeof(int)); 
    int arr[5] = {3,7,2,9,5};
    aja = quickSort(arr, largo);

    for (int i = 0; i < largo; i++){
        printf("%d\n", *(aja+i));
    }

    


}

