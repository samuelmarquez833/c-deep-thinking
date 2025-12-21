
/*
basicamente hay una funcion para crear un vector
luego una para aniadir elementos en la ultima posicon del vector
y una para borrarlo
pero sin usar realloc y suando aritemetica de punteros
*/

/*
Sí. Un vector dinámico es un arreglo cuyo tamaño puede crecer (o incluso reducirse) durante la ejecución.
Un array normal NO puede cambiar su tamaño.
*/

/*
Voy a explicar lo aprendidoe en la funcion de pushback

*/

#include <stdio.h>
#include <stdlib.h>

int *createVector(int length){
    int *vector = malloc(length * sizeof(int));
    return vector;
}

/*
primero que nada es int *pushBack, esta ahi por que lo que devuevle la func es un * 

lo que el paso a los parametros son direcciones de memeoria
por que de esa forma cuando en la funcion se cambie algo de esa direccion, en el main se va a ver igual

el *variable - signfica, ve a la direccion qeu tiene variable y dame lo que tiene 

cuando dices algo como
*(vector + *usados) = valor;
lo que significa es, ve a la direccion de vector, pero sumale lo que haya en la direccion de usados, 
entonces
posicionate en 
en la direccion actual de vector mas lo que tiene la direccion de usados




*/

int *pushBack(int *vector, int *length, int *usados, int valor){

    if (*usados < *length){
        *(vector + *usados) = valor;
        *usados += 1;  
        return vector; 
    } else if (*usados >= *length){
        int *nuevoBloque = malloc(*length * 2 * sizeof(int));;
        *length = (*length) * 2;
            for(int i = 0; i < *length; i++){
                *(nuevoBloque+i) = *(vector + i); 
            }
            *(nuevoBloque + *usados) = valor;
            *usados = *usados + 1;
            free(vector);
            return nuevoBloque;
    }
}

void deleteVector(int *vector){
    free(vector);
}

/*******************************************************************************************************/

int main() {
    int n = 10;
    int usados = 0;    
    int *vector = createVector(n); 
    printf("metemos los elementos: \n");
    for (int i = 0; i < n; i++){
        *(vector+i) = i;
        usados++;
        printf("%d\n", *(vector+i));
    }
    printf("antes de hacer el pushback, solo aniadiendo: \n");

    vector = pushBack(vector, &n, &usados, 10);
    vector = pushBack(vector, &n, &usados, 120);
    vector = pushBack(vector, &n, &usados, 92);

    printf("ya con el pushback: \n");

    for (int i = 0; i < usados; i++){
        printf("%d\n", *(vector+i));
    }

    deleteVector(vector);

    return 0;
}