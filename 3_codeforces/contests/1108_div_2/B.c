#include <stdlib.h>
#include <stdio.h>


long long int fastPower (int potencia){

    long long int acumulado = 2;
    long long int mierda = 1;  

    if (potencia == 0) return 3;
    while (potencia > 1){
        if (potencia % 2 == 0){
            acumulado = acumulado * acumulado;
            potencia /= 2;
        } else{
            mierda *= acumulado;
            potencia--;
        }
    }
    acumulado = 3 * acumulado * mierda;
    return acumulado;


}


void funcion (int n){

    if (n == 1 ){
        printf("1 ");
    } else if (n == 2 ){
        printf("-1 ");
    
    } else {
        printf("1 ");
        printf("2 ");
        n -= 2;
        int potencia = 0;
        while (n > 0){
            long long int ai = fastPower(potencia);
            printf("%lld ", ai);
            potencia++;
            n--;
        }
    }
}


/*
int main (){ 
    int n = 10;
    funcion(n);
    return 0;
}
*/



int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        int n;
        scanf("%d", &n);
        
        funcion(n);
        printf("\n");
    }
}
