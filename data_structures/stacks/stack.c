/*

/*
Objetivo del diseño:

Recibimos un stack (vector dinámico) y construimos uno nuevo
con las características deseadas (por ejemplo, con un elemento “pusheado”).

El stack original deja de ser útil una vez creado el nuevo,
por lo que su memoria debe liberarse.

Problema a resolver:

El stack en main es una variable que guarda una dirección.
Si dentro de la función se crea un nuevo vector y se libera el viejo,
esa variable debe actualizarse para que apunte al nuevo bloque.
De lo contrario, quedaría apuntando a memoria liberada
(puntero colgante).

Solución:

Se pasa la dirección del puntero al stack (int **),
para poder modificar desde la función la dirección que guarda
la variable del caller y hacerla apuntar al nuevo vector.

Por eso se usa **:
no para modificar los datos del vector,
sino para modificar la dirección del puntero que lo referencia.


ahora asi entiendes pq aqui usamos el **
pq sino de la otra forma estariamos creando un nuevo puntero por cada un cambio y el otro queda colgando
*/






#include <stdlib.h>
#include <stdio.h>

/**/
void push(int **stack, int *length, int val){


    /*

    CONTEXTO DE TIPOS (C puro):

    En main:
      - stack es una variable de tipo int* que guarda la dirección del arreglo en heap.

    En esta función:
      - stack (parámetro) es int** porque recibimos la DIRECCIÓN del puntero.
        Eso nos permite cambiar el puntero original (hacer que apunte a otro bloque).

    Lectura rápida:
        stack > direccion de la direccion 
      - *stack   : el puntero real al arreglo (int*)
    */
    
    

    (*length)++;


    int *newStack = malloc((*length) * sizeof(int));

    int i = 0;
    while(i < (*length)-1){
        /*
        Acceso a elementos:

        - (*stack + i)  es la DIRECCIÓN del elemento i (porque *stack es el inicio del arreglo).
        - *(*stack + i) es el VALOR almacenado en ese elemento (desreferencia).

        Es exactamente el mismo patrón que en main con:
          *(stack + i)
        solo que aquí primero bajamos un nivel con *stack porque stack es int**.
        */
        *(newStack+i) = *(*stack+i);
        i++;
    }

    // la i ya creo ne el ultimo, no?
    *(newStack+i) = val;

    // no entendi lo del orden
    *stack = newStack;

    free(*stack);
}


//solo por curiosidad
void printVector (int *vector){
    for (int i = 0; i < 5; i++){
        
    }
}




int main(){

    int length = 5;

    int *stack = malloc(length * sizeof(int));

    for (int i = 0; i < length; i++){
        *(stack+i) = i;
    }

    push(&stack, &length, 5);


}