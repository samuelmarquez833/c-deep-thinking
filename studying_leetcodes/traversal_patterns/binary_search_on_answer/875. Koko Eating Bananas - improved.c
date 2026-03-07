#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
Aqui mejoramos el codigo, la logica, costumbres
pasamos de 11ms a 4ms
*/


int minEatingSpeed(int* piles, int pilesSize, int h) {
    int left = 1; 
    int right = 0;
    for (int i = 0; i < pilesSize; i++){
        if (*(piles+i) > right){
            right = *(piles+i);
        }
    }

    int kActualOelMedio = (int)ceil((double)right / 2);
    // horasQueHanDeSerMaximoOcho en caso de que sea un numero muy grande ha de poder soportarlo entonces deberia de ser
    // long long horas
    long long horas = 0;
    int ans = 0;
    
    while (left <= right){

        printf("left: %d\nright: %d\n\n", left, right);

        for (int i = 0; i < pilesSize; i++){
            printf("n1: %d\nn2: %d\ny por ende lo que le sumamos a horasAcumuladas: %d\n", (*(piles+i)), kActualOelMedio, (int)ceil((double)(*(piles+i)) / (double)kActualOelMedio));
            
            // sumar como abajo no tiene sentido, es mejor solo havcelo de manera matematica
            horas += (piles[i]+kActualOelMedio-1)/kActualOelMedio;
            //horas += (int)ceil((double)(*(piles+i)) / (double)kActualOelMedio);       
        
            // no sirve de nada que sigas sumando, ya es mas grande que lo que peudes llegar a tener, solo ve direcot a actualizar right 
            if (horas > h) break;
        
        }  
        printf("terminamos el ciclo y la suma dio: %lld\n\n", horas);
        
        if(horas <= h){
            right = kActualOelMedio-1;
        } else if (horas > h){
            left = kActualOelMedio+1;
        }

        kActualOelMedio = left + (right-left)/2;
        horas = 0;
        printf("\n\n");
    }

    // antes tenias esto dentro del while, no sirve de nada ahi
    ans = left;


    printf("left: %d\nright: %d\n\n", left, right);


    printf("output: %d\n", ans);
    return ans;
}




int main() {
    int pilesSize = 4;
    int piles[] = {3,6,7,11};
    int h = 8;

    minEatingSpeed(piles, pilesSize, h);
    return 0;
}
