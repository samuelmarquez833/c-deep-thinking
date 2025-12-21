/*
PUNTEROS  A FUNCION 
*/

#include <stdio.h>
#include <stdlib.h>


int add(int  a, int b){ return a+b; }
int substract(int  a, int b){return a-b;}
int times(int  a, int b){ return a*b; }
int divide(int  a, int b){ return a/b; }


// las funciones regresan un int
// (*ptr[]) >>> esto es un arreglo, lo llamo por su direcion a memoria como a cualquier array, largo indefinido
// cada funcion recibe dos ints
int (*ptr[])(int, int) = { add, substract, times, divide };

int main () {
    
    int op;
    // scanf necesita una direccion de memoria donde escrbir lo que le meta
    printf("opcion que escoges: ");
    scanf("%d", &op);    
    
    if (op > 4 || op < 1){
        printf("opcion invalida");
    }

    int a = 10;
    int b = 5;

    int result = ptr[op-1](a, b);
    printf("%d", result);

    return 0;
}