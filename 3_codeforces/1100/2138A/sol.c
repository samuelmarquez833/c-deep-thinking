#include <stdlib.h>
#include <stdio.h>

long long int fastPower(int power){
    if (power == 0){
        return 1;
    }
    long long int acumulated = 2;
    long long int end = 1;
    while(power > 1){
        if(power % 2 == 0){
            acumulated = acumulated * acumulated;
            power = power / 2;
        } else{
            end = end * acumulated;
            power = power - 1;
        }
    }
    acumulated = acumulated * end;
    return acumulated;
}

void solucion(int k, long long int x){
    long long int a =  x;
    long long int b = fastPower(k+1) - x;
    int *registro = malloc(120 * sizeof(int));
    int idx = 0;
    while (a != b){
        long long int candidatoUnoA = a * 2;
        long long int candidatoUnoB = b - a;
        long long int candidatoDosA = a - b;
        long long int candidatoDosB = b * 2;
        if(candidatoUnoA > 0 && candidatoUnoB > 0){
            a = candidatoUnoA;
            b = candidatoUnoB;
            *(registro+idx) = 1;
        } else{
            a = candidatoDosA;
            b = candidatoDosB;
            *(registro+idx) = 2;
        }
        idx++;
    }
    printf("%d\n", idx);
    idx--;
    for (idx; idx >= 0; idx--){
        printf("%d ", *(registro+idx));
    }
    free(registro);
}


/*
int main(){
    solucion(2, 4);
    return 0;
}
*/




int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        int k;
        long long int x;
        scanf("%d", &k);
        scanf("%lld", &x);
        
        solucion(k, x);
    }
}
