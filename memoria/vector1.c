#include <stdio.h>
#include <stdlib.h>


int *alargar(int *arr, int newLength){
    int *nuevoArr = realloc(arr, newLength * sizeof(int));
    return nuevoArr;
}

int *acortar(int *arr, int shortLength){

    int *nuevoArr = malloc(shortLength * sizeof(int));
    for(int i = 0; i < shortLength; i++){
        *(nuevoArr+i) = *(arr+i);  
    }

    free(arr);

    return nuevoArr;
}


int main (){

    int length = 10;
    int *arr = malloc(length * sizeof(int));
    printf("normalitos: ");
    for (int i = 0; i < length; i++){
        *(arr+i) = i;
        printf("%d\n", *(arr+i));
    }

    int longLength = 20;

    arr = alargar(arr, longLength);
    length = longLength;
    printf("alrgamos: ");
    for (int i = 0; i < length; i++){
        printf("%d\n", *(arr+i));
    }

    int shortLength = 5;
    arr = acortar(arr, shortLength);
    length = shortLength;
    printf("acortamos: ");
    for (int i = 0; i < length; i++){

        printf("%d\n", *(arr+i));
    }

    return 0;

}