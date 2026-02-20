#include <stdio.h>
#include <stdlib.h>
#include <math.h>



int minEatingSpeed(int* piles, int pilesSize, int h) {
    int left = 1; 
    int right = 0;
    for (int i = 0; i < pilesSize; i++){
        if (*(piles+i) > right){
            right = *(piles+i);
        }
    }

    //printf("right: %d\n", right);
    

    //chat dice que asi es como funciona...
    // int kActualOelMedio = left + (right - left) / 2;
    int kActualOelMedio = (int)ceil((double)right / 2);
    //printf("kActualOelMedio: %d\n", kActualOelMedio);
    int horasQueHanDeSerMaximoOcho = 0;
    
    while (left <= right){
        for (int i = 0; i < pilesSize; i++){
            printf("n1: %d\nn2: %d\ny por ende lo que le sumamos a horasAcumuladas: %d\n", (*(piles+i)), kActualOelMedio, (int)ceil((double)(*(piles+i)) / (double)kActualOelMedio));
            horasQueHanDeSerMaximoOcho = horasQueHanDeSerMaximoOcho + (int)ceil((double)(*(piles+i)) / (double)kActualOelMedio);       
            printf("terminamos el ciclo y la suma dio: %d\n", horasQueHanDeSerMaximoOcho);
        }  
        
        
        if(horasQueHanDeSerMaximoOcho == h){
            printf("\n\n\nsu puta madre alv imprime esto me lleva a la verga\n\n\n");
            printf("\n\nencontramos el numero output que seria: %d", left);
            return 0;
        } else if (horasQueHanDeSerMaximoOcho < h){
            right = kActualOelMedio-1;
        } else if (horasQueHanDeSerMaximoOcho > h){
            left = kActualOelMedio+1;
        }
        kActualOelMedio = left + (int)floor((right-left)/2);
        horasQueHanDeSerMaximoOcho = 0;
        printf("\n\n\n\n\n\n");
    }
    return 0;

}




int main() {
    int pilesSize = 5;
    int piles[] = {30,11,23,4,20};
    int h = 6;
    minEatingSpeed(piles, pilesSize, h);
    return 0;
}
