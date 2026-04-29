#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <math.h>


/*



poner en el primer if
un continue si no es mayor
poner en el if bound > largo
for de recorrido para evaluar  -> if target return
salir del for
return


*/


void exponential(int * nums, int target, int largo){

    int bound = 1;

    int prev = 0;
    while(bound <= largo){

        if(*(nums+bound) >= target){
            for (int i = prev; i <= bound; i++){
                if (*(nums+i) == target){
                    printf("idx: %d\n", i);
                    if (bound >= largo-1){
                        printf("out\n");
                    } // this last thing is not necesary at all, but... idk
                    return;
                }
            }
            
            printf("nothing \n");
            return;
        }

        prev = bound+1;
        bound *= 2;

        if(bound > largo){
            bound = largo-1;
        }

    }



}


void main(){
    int largo = 11;
    int array[11] = {1,2,3,4,5,6,7,8,9,10,11};
    
    exponential(array, 9, largo);
    // índice correcto: 8
}