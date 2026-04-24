#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>


int *out;
int *tracks;
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
    
    
    merge(nums, startDos, end); 
    



    int a = start;
    int b = startDos;



    

    

    while (a < b && b <= end){
        printf("a:%d\n", a);
        printf("b:%d\n", b);


        if(*(nums+a) > *(nums+b)){

            int val = *(nums+b);
            int valTrack = *(tracks+b);
            int bIdx = b;

            

            while(bIdx > a && val < *(nums+(bIdx-1))){

                *(out+(*(tracks+(bIdx-1)))) += 1;
                *(tracks+bIdx) = *(tracks+(bIdx-1));
        
                *(nums+bIdx) = *(nums+(bIdx-1));
                bIdx--;
            }   


            *(tracks+a) = valTrack;
            *(nums+a) = val; 



            a++;
            b++;
            finalUno++;


        }   

        else if(*(nums+a) < *(nums+b)){
            printf("no cambio\n");
            a++;
        }

        printf("------\n");

    }







}


int* countSmaller(int* nums, int numsSize) {
    
    out = malloc(numsSize * sizeof(int));
    for (int i = 0; i < numsSize; i++){
        *(out+i) = 0;
    }

    tracks = malloc(numsSize * sizeof(int));
    for (int i = 0; i < numsSize; i++){
        *(tracks+i) = i;
    }



    int end = numsSize-1;
    merge(nums, 0, end);

    for (int i = 0; i < numsSize; i++){
        printf("%d\n", *(nums+i));
    }
    printf("\n\n\n");
    for (int i = 0; i < numsSize; i++){
        printf("%d\n", *(out+i));
    }

}

void main(){

    int largo = 4;
    int nums[4] = {5,2,6,1};

    int *aja = malloc(largo * sizeof(int));
    aja = countSmaller(nums, largo);
    

}