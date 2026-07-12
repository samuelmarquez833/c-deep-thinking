#include<stdlib.h>
#include<stdio.h>

void funcion(int n){
    int largo = n/2;
    while(largo > 0){
        printf("%d ", n);
        printf("%d ", n-1);
        n -= 2;
        largo--;
    }
}

/*
int main (){
    funcion(4);
    return 0;
}*/


int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        int n;
        scanf("%d", &n);
        
        funcion(n);
    }
}
