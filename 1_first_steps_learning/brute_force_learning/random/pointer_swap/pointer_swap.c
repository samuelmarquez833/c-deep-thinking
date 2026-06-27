#include <stdio.h>

void swap(int **pp1, int **pp2){
    int *buffer = *pp1;
    // *pp1 apunta a lo que guarda p1 
    //soooo, al cambiar el valor de *pp1 afectamos a p1
    *pp1 = *pp2;
    *pp2 = buffer;
}

int main(){

    int x = 3;
    int y = 6;
    int *p1 = &x;
    int *p2 = &y;
    int **pp1 = &p1;
    int **pp2 = &p2;
    
    printf("p1: %p\n", p1);
    printf("p2: %p\n", p2);
    printf("pp1: %p\n", pp1);
    printf("pp2: %p\n", pp2);

    swap(pp1, pp2);

    printf("p1: %p\n", p1);
    printf("p2: %p\n", p2);
    printf("pp1: %p\n", pp1);
    printf("pp2: %p\n", pp2);



    return 0;
}