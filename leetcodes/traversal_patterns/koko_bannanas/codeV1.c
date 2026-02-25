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

    

    int kActualOelMedio = (int)ceil((double)right / 2);
    int horasQueHanDeSerMaximoOcho = 0;
    int ans = 0;
    

    // dejamos la condicion como left <= right  
    // por que caundo left == right significa solo queda un candidato posible en el rango
    // entonces igual se tiene qeu evaluar
    // por mi linea de pensamiento, la solucion se encunetra una vez se cruzan los indices
    while (left <= right){

        printf("left: %d\nright: %d\n\n", left, right);

        for (int i = 0; i < pilesSize; i++){
            printf("n1: %d\nn2: %d\ny por ende lo que le sumamos a horasAcumuladas: %d\n", (*(piles+i)), kActualOelMedio, (int)ceil((double)(*(piles+i)) / (double)kActualOelMedio));
            horasQueHanDeSerMaximoOcho = horasQueHanDeSerMaximoOcho + (int)ceil((double)(*(piles+i)) / (double)kActualOelMedio);       
        }  
        printf("terminamos el ciclo y la suma dio: %d\n\n", horasQueHanDeSerMaximoOcho);
        
        
        // y es qeu esa es la cosa
        // linea de pensamiento original> lo voy haceindo y si un medio es igual a eso, pues devuelvo el medio, se qeu no queria hacer eso, pero es lo que estoy haciendo
        // linea de pensamiento nueva> los indices se han de cruzar, y ahi, left trae la respuesta
        // no puedes detenerte cuando son iguales por que ouede haber uno a la izquierda que es menor peor igual cumple 
        if(horasQueHanDeSerMaximoOcho <= h){
            right = kActualOelMedio-1;
        } else if (horasQueHanDeSerMaximoOcho > h){
            left = kActualOelMedio+1;
        }
        ans = left;

        kActualOelMedio = left + (int)floor((right-left)/2);
        horasQueHanDeSerMaximoOcho = 0;
        printf("\n\n");
    }

    printf("left: %d\nright: %d\n\n", left, right);


    printf("output: %d\n", ans);
    return ans;
    

}




int main() {
    int pilesSize = 1;
    int piles[] = {312884470};
    int h = 312884469;

    minEatingSpeed(piles, pilesSize, h);
    return 0;
}
