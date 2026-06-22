#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>


struct Node{
    int i;
    int j;
    bool visited;
    struct Node* nodosaLosQueApunto;
    struct Node* prev;
};

struct Bosque{
    
    int cuantosNodosTengo;
    struct Node* todosLosNodosQueTengo;
    
    // lista que contiene las direcciones de memoria de cada nodo
    int cuantosRootsTengo;
    struct Node* roots;
};


struct Stack{
    struct Node* top;
};


struct Bosque* bosque;
struct Stack* stack;
int cuenta;

struct Node* crearYmeterNuevoNodo(int i, int j){



    // si en algun momento se coincide con la misma i y j entonces
    // es por que el arbol ya tiene esa coordenada
    for(int m = 0; m < bosque->cuantosNodosTengo; m++){
        struct Node esteNodoPodriaTenerLAcoordenada = *((bosque->todosLosNodosQueTengo)+m);
        if (esteNodoPodriaTenerLAcoordenada.i == i && esteNodoPodriaTenerLAcoordenada.j == j){
            // return, ni le hagas nada al bosqe ni al arbol, olvidate
            return NULL;
        } 
    }

    struct Node* nodo = malloc(sizeof(struct Node));

    nodo->i = i;
    nodo->j = j;
    nodo->visited = false;
    nodo->nodosaLosQueApunto = malloc(4 * sizeof(struct Node));


    bosque->cuantosNodosTengo += 1;

    bosque->todosLosNodosQueTengo = realloc(
        bosque->todosLosNodosQueTengo,
        bosque->cuantosNodosTengo * sizeof(struct Node)
    );

    *((bosque->todosLosNodosQueTengo)+((bosque->cuantosNodosTengo)-1)) = *nodo;

    return nodo;
}


// no uses else if, no mames
void validarCoordenadas(int *array, int i, int j, int iLimite, int jLimite){
    if ((i + 1) < iLimite){
        *(array+1) = 1;
        // si se peude abajo
    } 
    if ((i-1) >= 0){
        *(array+3) = 1;
        // si se puede arriba
    }
    
    
    if ((j + 1) < jLimite){
        *(array+0) = 1;
        // si se puede a la derecha
    } if ((j-1) >= 0){
        *(array+2) = 1;
        // si se puede a la izquierda
    }

}


void meterAlStack(struct Stack* stack, struct Node* node ){
    if (stack->top == NULL){
        node->prev = NULL;
        stack->top = node;
        return;
    }


    struct Node* nodoPrevio = stack->top;
    node->prev = nodoPrevio;

    stack->top = node;
}




void encontrarVecinos(struct Node* nodo, int i, int j, char** grid, int gridSize, int* gridColSize){

    printf("i: %d\n", i);
    printf("j: %d\n", j);

    int array[4] = {0,0,0,0};
    // gridSize: limite que i puede alcanzar
    // gridColSize
    validarCoordenadas(array, i, j, gridSize, *(gridColSize+i));





    if (array[0] == 1){
        struct Node* der = crearYmeterNuevoNodo(i, j+1);
        if(der != NULL){
            *((nodo->nodosaLosQueApunto)+0) = *der;
            if(grid[((nodo->nodosaLosQueApunto)+0)->i][((nodo->nodosaLosQueApunto)+0)->j] == '1'){
                meterAlStack(stack, der);
            }
        }
    } 



    
    if (array[1] == 1){
        struct Node* abajo = crearYmeterNuevoNodo(i+1, j);
        if(abajo != NULL){
            *((nodo->nodosaLosQueApunto)+1) = *abajo;
            if(grid[((nodo->nodosaLosQueApunto)+1)->i][((nodo->nodosaLosQueApunto)+1)->j] == '1'){
                meterAlStack(stack, abajo);
            }
        }
    } 

    if (array[2] == 1){
        struct Node* izq = crearYmeterNuevoNodo(i, j-1);
        if (izq != NULL){
            *((nodo->nodosaLosQueApunto)+2) = *izq;
            if(grid[((nodo->nodosaLosQueApunto)+2)->i][((nodo->nodosaLosQueApunto)+2)->j] == '1'){
                meterAlStack(stack, izq);
            }
        }
    } 

    if (array[3] == 1){
        struct Node* arriba = crearYmeterNuevoNodo(i-1, j);
        if(arriba != NULL){
            *((nodo->nodosaLosQueApunto)+3) = *arriba;        
            if(grid[((nodo->nodosaLosQueApunto)+3)->i][((nodo->nodosaLosQueApunto)+3)->j] == '1'){
                meterAlStack(stack, arriba);
            
            }
        }
        
    } 

    printf("\n\n");



    nodo->visited = true;


























    
    
    while(stack->top != NULL){

        struct Node* nodo = stack->top;
        int a = nodo->i;
        int b = nodo->j;
        printf("ELLLLLLLLLLLLLLLLLLLLLLLLLLLLLL PRIMOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO\n");
        printf("a: %d\n", a);
        printf("b: %d\n", b);
        printf("\n");


        stack->top = (stack->top)->prev;


        if(nodo->visited == false){

            int arrayDeCoordenadasValidasDentroDelBucle[4] = {0,0,0,0};
            // gridSize: limite que i puede alcanzar
            // gridColSize
            validarCoordenadas(arrayDeCoordenadasValidasDentroDelBucle, a, b, gridSize, *(gridColSize+a));

            if (arrayDeCoordenadasValidasDentroDelBucle[0] == 1){
                struct Node* der = crearYmeterNuevoNodo(a, b+1);
                
                if (der != NULL){
                    *((nodo->nodosaLosQueApunto)+0) = *der;
                    
                    if(grid[((nodo->nodosaLosQueApunto)+0)->i][((nodo->nodosaLosQueApunto)+0)->j] == '1' ){
                        printf("derecha\n");
                        printf("%c\n", grid[((nodo->nodosaLosQueApunto)+0)->i][((nodo->nodosaLosQueApunto)+0)->j]);
                        printf("Entro al stack\n\n");
                        meterAlStack(stack, der);
                    }
                }
            } 
            

            if (arrayDeCoordenadasValidasDentroDelBucle[1] == 1){
                struct Node* abajo = crearYmeterNuevoNodo(a+1, b);
                
                if (abajo != NULL){
                    *((nodo->nodosaLosQueApunto)+1) = *abajo;
                    if(grid[((nodo->nodosaLosQueApunto)+1)->i][((nodo->nodosaLosQueApunto)+1)->j] == '1'){
                        printf("abajo\n");
                        printf("%c\n", grid[((nodo->nodosaLosQueApunto)+1)->i][((nodo->nodosaLosQueApunto)+1)->j]);
                        printf("Entro al stack\n\n");
                        meterAlStack(stack, abajo);
                    }
                }
            } 






            if (arrayDeCoordenadasValidasDentroDelBucle[2] == 1){
                struct Node* izq = crearYmeterNuevoNodo(a, b-1);
                if (izq != NULL){
                    *((nodo->nodosaLosQueApunto)+2) = *izq;
                    if(grid[((nodo->nodosaLosQueApunto)+2)->i][((nodo->nodosaLosQueApunto)+2)->j] == '1' ){
                        printf("izq\n");
                        printf("%c\n", grid[((nodo->nodosaLosQueApunto)+2)->i][((nodo->nodosaLosQueApunto)+2)->j]);
                        printf("Entro al stack\n\n");
                        meterAlStack(stack, izq);
                    }
                }
            } 

            


            if (arrayDeCoordenadasValidasDentroDelBucle[3] == 1){
                struct Node* arriba = crearYmeterNuevoNodo(a-1, b);
                if(arriba != NULL){
                    *((nodo->nodosaLosQueApunto)+3) = *arriba;
                    if(grid[((nodo->nodosaLosQueApunto)+3)->i][((nodo->nodosaLosQueApunto)+3)->j] == '1' ){
                        printf("arriba\n");
                        printf("%c\n", grid[((nodo->nodosaLosQueApunto)+3)->i][((nodo->nodosaLosQueApunto)+3)->j]);
                        printf("Entro al stack\n\n");
                        meterAlStack(stack, arriba);
                    }
                }
            } 

            nodo->visited = true;
        }

        printf("sig nodo\n");
    }


    printf("hopla\n");
    cuenta += 1;
    printf("cuenta: %d\n", cuenta);
    

}


void proceso(int i, int j, char** grid, int gridSize, int* gridColSize){
    
    // saber si un nodo esta en el bosque en lo absoluto
    
    
    for(int m = 0; m < bosque->cuantosNodosTengo; m++){
        struct Node esteNodoPodriaTenerLAcoordenada = *((bosque->todosLosNodosQueTengo)+m);
        
        if (esteNodoPodriaTenerLAcoordenada.i == i && esteNodoPodriaTenerLAcoordenada.j == j){
            // return, ni le hagas nada al bosqe ni al arbol, olvidate
            return;
        } 



    }

    /*
    como el nodo no esta
    aniadelo al bosque
    es un arbol nuevo, por que sino, ya lo hubieras encontrado
    y lo hubieras metido al arbol y por ende al bosque
    */


    struct Node* nodoNuevo = crearYmeterNuevoNodo(i, j);

    nodoNuevo->visited = true;

    bosque->cuantosRootsTengo += 1;

    bosque->roots = realloc(
        bosque->roots,
        bosque->cuantosRootsTengo * sizeof(struct Node)
    );

    *((bosque->roots)+((bosque->cuantosRootsTengo)-1)) = *nodoNuevo;




    encontrarVecinos(nodoNuevo, i, j, grid, gridSize, gridColSize);






}


void numIslands(char** grid, int gridSize, int* gridColSize) {
    
    for(int i = 0; i < gridSize; i++){
        for(int j = 0; j < *(gridColSize+i); j++){
            if(grid[i][j] == '1'){
                proceso(i, j, grid, gridSize, gridColSize);
            }
        }
    }


   
}



void main(){

    stack = malloc(sizeof(struct Stack));
    stack->top = NULL;

    cuenta = 0;


    int count = 0;
    bosque = malloc(sizeof(struct Bosque));
    bosque->cuantosNodosTengo = 0;
    bosque->todosLosNodosQueTengo = malloc((bosque->cuantosNodosTengo)*sizeof(struct Node));

    // filas (cantidad de arrays)
    int m = 4;

    // columnas (array de cantidad de columnas)
    int n[4] = {5,5,5,5};

char array1[5] = {'1','0','0','0','1'};
char array2[5] = {'1','0','0','0','1'};
char array3[5] = {'1','1','1','1','1'};
char array4[5] = {'0','0','0','0','0'};

    char **grid = malloc(m * (sizeof(char *)));
    *(grid) = array1;
    *(grid+1) = array2;
    *(grid+2) = array3;
    *(grid+3) = array4;

    numIslands(grid, m, n);

     
     printf("cuenta: %d\n", cuenta);


}



