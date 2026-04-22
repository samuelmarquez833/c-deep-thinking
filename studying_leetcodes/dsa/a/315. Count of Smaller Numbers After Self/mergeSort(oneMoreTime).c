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
        printf("Numeros mitad izquierda: %d\n", *(nums+i));
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
        printf("Numeros mitad derecha: %d\n", *(nums+i));
    }

    //printf("llegamos a un final\n");

    int a = start;
    int b = startDos;
    /*printf("a: %d\n", a);
    printf("b: %d\n", b);
    printf("end: %d\n", end);
    printf("a: %d - b: %d\n", *(nums+a), *(nums+b));*/


    //while(a <= b && b <= end ){
    while (a <= finalUno && b <= end){
        /*
        if(*(nums+a) > *(nums+b)){
            //printf("swap a>%d b>%d\n", *(nums+a), *(nums+b));
            int buffer = *(nums+a);
            *(nums+a) = *(nums+b);
            *(nums+b) = buffer;
            b++;
        } else {
            a++;
        }*/
            if (nums[a] <= nums[b]) {
        a++;
    } else {
        int val = nums[b];
        int k = b;

        // desplazar a la derecha
        while (k > a) {
            nums[k] = nums[k - 1];
            k--;
        }

        nums[a] = val;

        // actualizar punteros
        a++;
        b++;
        finalUno++;
    }
    }


 




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