#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <math.h>



void exponential(int * nums, int target, int largo){

    int bound = 1;

    int prev = 0;
    int state = 0;
    /*
    bound < largo sin el =
    El <= no está “mal por estilo”, está mal porque permite un caso inválido (bound == largo).
    Aunque tu if lo evite en práctica, dependes del flujo interno y del input.
    Mejor garantizarlo desde la condición: no permitir nunca ese estado.
    */
    while(bound < largo /*&& state < 2*/){

        if(*(nums+bound) >= target){
            for (int i = prev; i <= bound; i++){
                if (*(nums+i) == target){
                    printf("idx: %d\n", i);
                    if (bound >= largo-1){
                        printf("out\n");
                    } 
                    printf("number not found");
                    return;
                }
            }
            
            printf("nothing \n");
            return;
        }

        prev = bound+1;
        bound *= 2;


        /*
        puse en el while la condicion de que si una variable state es menor a algo - siga ejecutando el codigo
        si llegmaos al if de aqui abajo - esa variable incrementaba
        de modo que nos deja recorrer el codiog una vez mas, y lueog volvia a incrementar y ya no nos dejaba correr el codigo ninguna vez mas
        
        pero esto era un parche, si lo solucionaba pero no estaba limpio
        entonces
        si simplemnete en este if de abajo - corriges a bound a su valor final correcto - 
        y evaluas si target es mayor que *(nums+bound)
        si si es verdad pues no esta el target, haces return
        si es falso (el *(nums+bound) es mayor a target), puede estar en ese rango de prev a bound
        entonces regresas al codigo de arriba y si esta hacer return y si no igual haces return
        
        */
        if(bound > largo){
            bound = largo-1;
            if (target > *(nums+bound)){
                printf("No esta\n");
                return;
            }
            //state++;
        }
    }

    printf("The number is not in the array\n");

}


void main(){
    int largo = 11;
    int array[11] = {1,2,3,4,5,6,7,8,9,10,11};
    
    exponential(array, 9, largo);
    // índice correcto: 8
}


