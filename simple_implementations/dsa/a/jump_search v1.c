#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <math.h>


void jump(int *nums, int target, int largo){
    int step = sqrt(largo);

    int i = -1;
    while (i < largo){

        int prev = i;
        i += step;

        /*printf("i: %d\n", i);
        printf("final: %d\n\n", *(nums+i));
        
        if(i >= largo){
            i-=step;
            printf("nuevos\n");
            printf("i: %d\n", i);
            printf("final: %d\n\n", *(nums+i));
        
            for(int j = i+1; j < largo; j++){
                printf("pasado: %d\n", *(nums+j));
                if(*(nums+j) == target){
                    return;
                }
            }
            return;
        }*/

        if(i >= largo){
            //i = i - step + 1
            // solo haz que i sea  equivalente al indice del ultimo elemento
            i = largo - 1; 
        }

        // con eso no encesitas logica diferente ni extra para el caso extra
        // o sea todo queda e un mismo for
        // pero esto es para i o sea para el final
        // ---------------- 
        // para el inicio lo ideal ps es usar el anteruior y ya



        if(*(nums+i) >= target){
            for(int j = prev+1; j <= i; j++){
                printf("nigger: %d\n", *(nums+j));
                if(*(nums+j) == target){
                    return;
                }
            }
            return;
        } 
        
        
    }
    
}





void main(){
    int largo = 11;
    int array[11] = {1,2,3, 4,5,6,  7,8,9, 10,11};
    
    jump(array, 10, largo);
    // índice correcto: 8
}