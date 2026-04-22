#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>


int *out;
int k = 0;
int* merge (int *nums, int start, int end){

    int size = end-start+1;
    if (size <= 1){
        // aqui tengo qeu hacer algo de modo que compare e incremente en base a indice en el array de out
        return nums;
    }


    int mitad = size / 2;
    int finalUno = (start+mitad)-1;
    int startDos = finalUno+1;

    merge(nums, start, finalUno); 
    /*printf("inicio\n");
    printf("k> %d\n", k);
    k++;
    printf("size> %d\n", size);
    printf("mitad> %d\n", mitad);
    printf("start> %d\n", start);
    printf("finalUno> %d\n", finalUno);
    printf("startDos> %d\n", startDos);
    printf("end> %d\n", end);*/


    for (int i = start; i <= finalUno; i++){
        //printf("Numeros mitad izquierda: %d\n", *(nums+i));
    }
    
    merge(nums, startDos, end); 
    /*printf("inicio\n");
    printf("k> %d\n", k);
    k++;
    printf("size> %d\n", size);
    printf("mitad> %d\n", mitad);
    printf("start> %d\n", start);
    printf("finalUno> %d\n", finalUno);
    printf("startDos> %d\n", startDos);
    printf("end> %d\n", end);*/

    for (int i = startDos; i <= end; i++){
        //printf("Numeros mitad derecha: %d\n", *(nums+i));
    }




    int a = start;
    int b = startDos;



    while (a < b && b <= end){

    printf("a: %d\n", a);
    printf("b: %d\n", b);
    printf("end: %d\n", end);
    
    printf("--------------------\n");
    printf("a: %d\n", *(nums+a));
    printf("b: %d\n", *(nums+b));
    printf("--------------------\n\n\n");


        if(*(nums+a) > *(nums+b)){
            printf("(necesitamos un cambio)\n");
            int val = *(nums+b);
            int bIdx = b;

            if( && val < *(nums+(bIdx-1))){
                *(nums+bIdx) = *(nums+(bIdx-1));
                bIdx--;
            }
            *(nums+a) = val; 

            b++;
            a++;
            finalUno++;
        }   
        else if(*(nums+a) < *(nums+b)){
            printf("(no necesitamos un cambio)\n");
            a++;

        }
    }



    /*while (a < b && b <= end){

    }*/




}


int* countSmaller(int* nums, int numsSize) {
    
    out = malloc(numsSize * sizeof(int));
    for (int i = 0; i < numsSize; i++){
        *(out+i) = 0;
    }

    int end = numsSize-1;
    merge(nums, 0, end);

    for (int i = 0; i < numsSize; i++){
        printf("%d\n", *(nums+i));
    }

}

void main(){

    int largo = 4;
    int nums[4] = {5,2,6,1};

    int *aja = malloc(largo * sizeof(int));
    aja = countSmaller(nums, largo);

}