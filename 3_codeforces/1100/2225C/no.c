#include <stdio.h>
#include <stdlib.h>

struct Nodo{
    int row;
    int i;
    struct Nodo* next;
};

struct LinkedList{
    struct Nodo* front;
    struct Nodo* back;
};


void checkSides(int *sides, int n, int fila, int i){
    // filas
    if (fila == 0){
       sides[2] = 1;  
    } else{
        sides[0] = 1;
    }

    // i

    if(i > 0 && i < (n-1)){
        sides[1] = 1;
        sides[3] = 1;
    } else {
        if (i == 0){
            sides[1] = 1;  
        } else if (i == (n-1)){
            sides[3] = 1;
        }
    }
    

}


void function(int n, char *a, char *b){


    char **matrizEnSi = malloc(2 * sizeof(char*));
    *(matrizEnSi) = a;
    *(matrizEnSi+1) = b;

    struct Nodo *primero = malloc(sizeof(struct Nodo));
    primero->row = 0;
    primero->i = 0;    
    struct Nodo *actual = primero;

    struct LinkedList *lista = malloc(sizeof(struct LinkedList));
    lista->front = primero;
    lista->back = primero;  
    
    // matriz de matrices - DOBLE PUNTERO
    int **matrizDeEstados = malloc(2 * sizeof (int*));
    for (int i = 0; i < 2; i++){
        int *subMatriz = malloc(n * sizeof(int));
        int indiceDeLlenoEnSubamtriz = 0;
        while(indiceDeLlenoEnSubamtriz < n){
            *(subMatriz+indiceDeLlenoEnSubamtriz) = 0;
            indiceDeLlenoEnSubamtriz++;
        }
        *(matrizDeEstados+i) = subMatriz; 
    }


    int count = 0;


    int variable = 0;
    int iteracion = 0;


    while(variable == 0){

        iteracion++;

        *((*(matrizDeEstados+(actual->row)))+(actual->i)) = 1;

        variable = 1;
        // arriba derecha abajo izquierda 
        int sides[4] = {0,0,0,0};
        checkSides(sides, n, actual->row, actual->i);

        int state = 0;


        if (sides[0] == 1){
            struct Nodo *vecinoArriba = malloc(sizeof(struct Nodo));
            vecinoArriba->row = (actual->row)-1;
            vecinoArriba->i = actual->i;   
            if (*((*(matrizDeEstados+(vecinoArriba->row)))+(vecinoArriba->i)) == 1){
                printf("1 no hagas nada, ha sido visitado\n");
            } else{
                char letraVecina = *((*(matrizEnSi+(vecinoArriba->row)))+(vecinoArriba->i));
                char letraActual = *((*(matrizEnSi+(actual->row)))+(actual->i));
                
                if (state == 0){
                    if(letraActual == letraVecina){
                        printf("1 letra: %c, %c\n", letraVecina, letraActual);  
                        *((*(matrizDeEstados+(vecinoArriba->row)))+(vecinoArriba->i)) = 1;                  
                    } else if(letraActual != letraVecina && state == 0){
                        *((*(matrizDeEstados+(vecinoArriba->row)))+(vecinoArriba->i)) = 1;                  
                        printf("1 cambiemos\n");
                        count++;
                        state = 1;
                        printf("1 son diferentes letra: %c, %c\n", letraVecina, letraActual);                    
                    
                    }
                } else if (state == 1){
                    variable = 0;
                    actual = vecinoArriba;
                    continue;
                }
            }
        }

        
        if (sides[2] == 1){
            struct Nodo *vecinoAbajo = malloc(sizeof(struct Nodo));
            vecinoAbajo->row = (actual->row)+1;
            vecinoAbajo->i = actual->i;   
            if (*((*(matrizDeEstados+(vecinoAbajo->row)))+(vecinoAbajo->i)) == 1){
                printf("2 no hagas nada, ha sido visitado\n");
            } else{
                char letraVecina = *((*(matrizEnSi+(vecinoAbajo->row)))+(vecinoAbajo->i));
                char letraActual = *((*(matrizEnSi+(actual->row)))+(actual->i));
                
                if (state == 0){
                    if(letraActual == letraVecina){
                        printf("2 letra: %c, %c\n", letraVecina, letraActual);  
                        *((*(matrizDeEstados+(vecinoAbajo->row)))+(vecinoAbajo->i)) = 1;                  
                    } else if(letraActual != letraVecina && state == 0){
                        *((*(matrizDeEstados+(vecinoAbajo->row)))+(vecinoAbajo->i)) = 1;                  
                        printf("2 cambiemos\n");
                        count++;
                        state = 1;
                        printf("2 son diferentes letra: %c, %c\n", letraVecina, letraActual);
                    }
                } else if (state == 1){
                    variable = 0;
                    actual = vecinoAbajo;
                    continue;
                }
            }
        }

        
        if (sides[1] == 1){
            struct Nodo *vecinoDerecha = malloc(sizeof(struct Nodo));
            vecinoDerecha->row = (actual->row);
            vecinoDerecha->i = (actual->i)+1;   
            if (*((*(matrizDeEstados+(vecinoDerecha->row)))+(vecinoDerecha->i)) == 1){
                printf("3 no hagas nada, ha sido visitado\n");
            } else{
                char letraVecina = *((*(matrizEnSi+(vecinoDerecha->row)))+(vecinoDerecha->i));
                char letraActual = *((*(matrizEnSi+(actual->row)))+(actual->i));
                
                if (state == 0){
                    if(letraActual == letraVecina){
                        printf("3 letra: %c, %c\n", letraVecina, letraActual);  
                        *((*(matrizDeEstados+(vecinoDerecha->row)))+(vecinoDerecha->i)) = 1;                  
                    } else if(letraActual != letraVecina && state == 0){
                        *((*(matrizDeEstados+(vecinoDerecha->row)))+(vecinoDerecha->i)) = 1;   
                        printf("3 cambiemos\n");
                        count++;
                        state = 1;
                        printf("3 son diferentes letra: %c, %c\n", letraVecina, letraActual);
                    }
                } else if (state == 1){
                    variable = 0;
                    actual = vecinoDerecha;
                    continue;
                }
            }
        }


        
        if (sides[3] == 1){
            struct Nodo *vecinoIzquierda = malloc(sizeof(struct Nodo));
            vecinoIzquierda->row = (actual->row);
            vecinoIzquierda->i = (actual->i)-1;   
            if (*((*(matrizDeEstados+(vecinoIzquierda->row)))+(vecinoIzquierda->i)) == 1){
                printf("4 no hagas nada, ha sido visitado\n");
            } else{
                char letraVecina = *((*(matrizEnSi+(vecinoIzquierda->row)))+(vecinoIzquierda->i));
                char letraActual = *((*(matrizEnSi+(actual->row)))+(actual->i));
                
                if (state == 0){
                    if(letraActual == letraVecina){
                        printf("4 letra: %c, %c\n", letraVecina, letraActual);  
                        *((*(matrizDeEstados+(vecinoIzquierda->row)))+(vecinoIzquierda->i)) = 1;                  
                    } else if(letraActual != letraVecina && state == 0){
                        *((*(matrizDeEstados+(vecinoIzquierda->row)))+(vecinoIzquierda->i)) = 1;   
                        printf("4 cambiemos\n");
                        count++;
                        state = 1;
                        printf("4 son diferentes letra: %c, %c\n", letraVecina, letraActual);
                    }
                } else if (state == 1){
                    variable = 0;
                    actual = vecinoIzquierda;
                    continue;
                }
            }
        }


        if(variable == 1){
            for(int i = 0; i < 2; i++){
                for(int j = 0; j < n; j++){
                    if (matrizDeEstados[i][j] == 0){
                        struct Nodo *aja = malloc(sizeof(struct Nodo));
                        primero->row = i;
                        primero->i = j;    
                        actual = aja;
                        variable = 0;
                        continue;
                    }   

                }
            }
        }


    }

    printf("\nactual->row: %d\n", actual->row);
    printf("actual->i: %d\n", actual->i);

    printf("\n");
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < n; j++){
            printf("%d ", matrizDeEstados[i][j]);
        }
        printf("\n");
    }

    printf("count: %d\n", count);
    printf("fin");
     

}




void main (){
    int n = 5;
    char a[5] = {'R','B','R','B','R'};
    char b[5] = {'B','B','B','R','B'};
    function(n, a, b);

}