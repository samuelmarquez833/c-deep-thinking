#include <stdlib.h>
#include <stdio.h>



int push(int **data, int *capacity, int *length, int val){

    if (*data == NULL){
        return 1;
    } 


    if (*capacity > *length){
        *(*data+*(length)) = val;
        (*length)++;
        return 0;
    } else if (*capacity <= *length){
        int newCap  = (*capacity) * 2;
        int *tmp = realloc(*data, newCap * sizeof(int));
        if (tmp == NULL){
            return 1;
        } else {
            *capacity *= 2;
            *data = tmp;
            *(*data+*(length)) = val;
            (*length)++;
            return 0;
        }
    }

    return 0;
}



int pop(int **data, int *capacity, int *length, int *out) {
    // No hay vector
    if (*data == NULL) {
        return 1;
    }

    // Stack vacío
    if (*length == 0) {
        return 1;
    }

    // Obtener el último elemento (opcional)
    if (out != NULL) {
        *out = *(*data + (*length - 1));
    }

    // “Eliminar” el último elemento
    (*length)--;

    return 0;
}





int main (){

    int capacity = 9;
    int length = 0 ;
    int *data = malloc(capacity * sizeof(int));
 
    if (data == NULL){
        return 1;
    }

    for (int i = 0; i < 4; i++){
        *(data+i) = i;
        length++;
    }

    int aja = push(&data, &capacity, &length, 5);
    if (aja != 0){
        return 1;
    }




    free(data);
    return 0;
}