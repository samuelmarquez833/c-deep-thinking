#include <stdio.h>

void swap(int *n1, int *n2){
    int buffer = *n1;
    *n1 = *n2;
    *n2 = buffer;
}


int main(){

    int x = 3;
    int *p1 = &x;
    int y = 6;
    int *p2 = &y;

    printf("n1: %d\n", *p1);
    printf("n2: %d\n", *p2);
    
    swap(p1, p2);

    printf("n1: %d\n", *p1);
    printf("n2: %d\n", *p2);

    return 0;
}