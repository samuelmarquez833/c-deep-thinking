#include <stdio.h>
#include <stdlib.h>

/*
que es esto?
para que sirve en la vida real?


*/


// no entiendo la puta madre del cero de que si condigo un cero caundo voy restando encontes ya esta
// pq la chingadera de que el primero es cero y ya esta impliciot - que verga?


void prefix_sum(int *nums, int largo, int k){
    

    
    // ya se que no tengo que hacer prefixes, pero lo voy a hacer, me vale verga
    int *prefixes = malloc (largo * sizeof(int));
    int acumulador = 0;

    for (int i = 0; i < largo; i++){
        acumulador += nums[i] ;
        *(prefixes+i) = acumulador;
        printf("%d\n", *(prefixes+i)-3);

    } 

    int freq[20001] = {0};
    int offset = 10000;
    int cuentaDeCoincidencias = 0;
    // esto lo hago solo para que el cero ya este incluido
    freq[offset] = 1;


    return count;

}

















int main () {
    int largo = 6;
    int nums[] = {2, -1, 3, 1, -2, 4};

    prefix_sum(nums, largo, 3);



    return 0;
}

















