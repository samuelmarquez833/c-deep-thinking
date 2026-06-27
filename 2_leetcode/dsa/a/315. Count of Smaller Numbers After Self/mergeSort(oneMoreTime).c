#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>


int *out;
int k = 0;
int* merge (int *nums, int start, int end){

    int size = end-start+1;
    if (size <= 1){
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


        if(*(nums+a) > *(nums+b)){
            printf("cambio\n");
            int val = *(nums+b);
            int bIdx = b;

            // evaluar esto: bIdx > a
            // si o si es necesario, por que
            // de esta forma te detienes, dejas de hacer retroceder al pobre val caundo sigue siendo menor que el elemenot a comparar 
            // mira tu array 2 5 1 6
            // si comienzas a retroceder a 1, sin parar, no importa, va a seguir haciendolo aunque ya haya comparado con el dos
            // va a comparar con la basrua de atras
            while(bIdx > a && val < *(nums+(bIdx-1))){
                *(nums+bIdx) = *(nums+(bIdx-1));
                bIdx--;
            }   

            *(nums+a) = val; 

            a++;
            b++;
            finalUno++;
        }   

        else if(*(nums+a) < *(nums+b)){
            printf("no cambio\n");
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

    int largo = 6;
    int nums[6] = {12,45,1,7,34,6};

    int *aja = malloc(largo * sizeof(int));
    aja = countSmaller(nums, largo);

}