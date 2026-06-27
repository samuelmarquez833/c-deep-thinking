/*
Si no sale solo, todavía no está entendido
(aunque el código “funcione”).
*/





































#include <stdio.h>
#include <stdlib.h>


// mi algoritmo 1
void slidingWindowV1(int *vector, int largo, int k){
    int vecesQueVamosAIniciar = (largo - k) + 1;
    int indice = 0;

    int sumaDelMomento = 0;
    int sumaEscogida = 0;

    int *vectorSeleccionado = malloc(k * sizeof(int));

    for (int i = 0; i < vecesQueVamosAIniciar; i++){
        sumaDelMomento = 0;

        for(int j = 0; j < k; j++){
            indice = i+j;        
            //printf("%d", *(vector+indice));
            sumaDelMomento = sumaDelMomento + *(vector+indice);
        }
        if(sumaDelMomento > sumaEscogida){
            sumaEscogida = sumaDelMomento;
            for(int j = 0; j < k; j++){        
                indice = i+j;        
                *(vectorSeleccionado+j) = *(vector+indice);
            }   
        }
        //printf("\n\n");
    }

    for(int j = 0; j < k; j++){        
        printf("%d", *(vectorSeleccionado+j));
    } 
}

/*
ESTO ESTA MAL
crei que 
“probar todas las ventanas contiguas de tamaño k”

realmente use fuerza bruta por ventanas
repeti trabajo
recalculé elementos que ya había sumado en la ventana anterior

comoplejidad de tiempo
O(n^2)

complejidad espacial
O(n)
*/












// Lo que tuve que haber hecho

int slidingWindowV2(int *vector, int largo, int k){

    int indiceDelElementoADetenernos = largo-k;

    int sumaActual = 0;
    int sumaMasGrande = 0;

    int indiceInicialActual = 0;
    int indiceFinalActual = k-1;

    for (int i = 0; i < k; i++){
        sumaActual += *(vector+i);
        sumaMasGrande += *(vector+i);
    }

    printf("%d\n", sumaActual);

    while (indiceInicialActual != indiceDelElementoADetenernos){
        sumaActual -= *(vector+indiceInicialActual);

        indiceInicialActual++;
        indiceFinalActual++;
        
        sumaActual += *(vector+indiceFinalActual);
        printf("%d\n", sumaActual);

        if(sumaActual > sumaMasGrande){
            sumaMasGrande = sumaActual; 
        }
    }



    return  sumaMasGrande;
}


// Optimizacion del algoritmo correcto
// como tal no se puede hacer MEJOR - no se puede hacer menos Big-O
// solo lo hacemos mas claro o mas robutso, menots estado mneos I/O y a veces un poco mas rapido por constantes


// lo hacemos reduciendo la cantidad de variables que hay, o sea como que dos variables se pueden expresar con una sola, pq tiene una relacion matematica
// si algo es igual desde un inicio, se pueden remplazar
//dejar cirstlina la logica sin movimientos inicesarios basicamente

int slidingWindowOptimized(int *vector, int largo, int k){

    int sumaActual = 0;
    int sumaMasGrande = 0;


    for (int i = 0; i < k; i++){
        sumaActual += *(vector+i);
        sumaMasGrande += *(vector+i);
    }

    int entra = 0;
    int sale = 0;

    for (int start = 1; start <= largo-k; start++){
        entra = start+k-1;
        sale = start-1;
        sumaActual += *(vector+entra) - *(vector+sale);
        if(sumaActual > sumaMasGrande){
            sumaMasGrande = sumaActual; 
        }
    }
    return  sumaMasGrande;
}





















int main (){
    int largo = 8;
    int *vector = malloc(largo * sizeof(int));
    int k = 4;

    for (int i = 0; i < largo; i++){
        *(vector+i) = i;
    }

    int sumaMasGrande = slidingWindowOptimized(vector, largo, k);
    printf("%d", sumaMasGrande);

    free(vector);

    return 0;

}



