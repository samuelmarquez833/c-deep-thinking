#include <stdio.h>
#include <stdlib.h>

/*
que es esto?
para que sirve en la vida real?


*/



int prefix_sum(int *nums, int largo, int k){
    

    
    int *prefixes = malloc (largo * sizeof(int));
    int acumulador = 0;

    for (int i = 0; i < largo; i++){
        acumulador += nums[i] ;
        *(prefixes+i) = acumulador;

    } 



    int freq[20001] = {0};
    int offset = 10000;
    int cuentaDeCoincidencias = 0;
    freq[offset]++;

    for (int i = 0; i < largo; i++){

        int prefix = *(prefixes+i);

        int need = prefix - k;


        int idx_need = offset + need;
        cuentaDeCoincidencias += freq[idx_need];
    
        int idx_prefix = offset + prefix;
        freq[idx_prefix]++;
    
    }


    free(prefixes);

    return cuentaDeCoincidencias;
}








// lo mismo pero ahora creo el array adentro (hay un solo for) - bueno ni hay array 


int prefix_sum_two(int *nums, int largo, int k){
    

    

    int freq[20001] = {0};
    int offset = 10000;
    int cuentaDeCoincidencias = 0;
    freq[offset]++;

    int acumulador = 0;
    for (int i = 0; i < largo; i++){

        acumulador += nums[i];


        int prefix = acumulador;

        int need = prefix - k;


        int idx_need = offset + need;
        cuentaDeCoincidencias += freq[idx_need];
    
        int idx_prefix = offset + prefix;
        freq[idx_prefix]++;
    
    }



    return cuentaDeCoincidencias;
}






int main () {
    int largo = 6;
    int nums[] = {2, -1, 3, 1, -2, 4};
    int output = prefix_sum_two(nums, largo, 3);
    printf("%d\n", output);
    return 0;
}
