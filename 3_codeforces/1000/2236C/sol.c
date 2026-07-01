#include <stdio.h>
#include <stdlib.h>

int function (int a, int b, int x){

    int *listA = malloc(sizeof(int) * 31);
    int *listB = malloc(sizeof(int) * 31);
    
    int c = a;
    int sizeA = 0;
    while(c >= 0){
        *(listA+sizeA) = c;
        sizeA++; 
        c = c / x;
        if(c == 0){
           *(listA+sizeA) = 0;
            sizeA++;
            break;
        }
    }

    int d = b;
    int sizeB = 0;
    while(d >= 0){
        *(listB+sizeB) = d;
        sizeB++;
        d = d / x;
        if(d == 0){
           *(listB+sizeB) = 0;
            sizeB++;
            break;
        }
    }


    int mayor = 0;
    int menor = 0;
    
    if (a >= b){
        mayor = a;
        menor = b;
    } else {
        menor = a;
        mayor = b;
    }
    
    int cuenta = mayor - menor;
    
    
    for (int i = 0; i < sizeA; i++){
        for (int j = 0; j < sizeB; j++){
            
            if (*(listA+i) >= *(listB+j)){
                mayor = *(listA+i);
                menor = *(listB+j);
            } else {
                menor = *(listA+i);
                mayor = *(listB+j);
            }

            if ( ((i + j) + (mayor-menor)) < cuenta){
                cuenta = ((i + j) + (mayor-menor));
            }
        }   
    }


    printf("%d\n", cuenta);


}


int main (){
    
    
    int t;
    scanf("%d", &t);
    while(t--){
        int a, b, x;
        scanf("%d %d %d", &a, &b, &x);

        function(a, b, x);
    }

    return 0;
}
