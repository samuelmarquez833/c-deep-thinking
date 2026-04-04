/*
v0
1. el algoritmo de sort es una pesado, podria aptimizarlo... espera, aunque lo optimices 
por la logica que tiene, sigue siendo pesado.... mejo usamos quicksort y ya 

2. el algotimo greedy es optimizable? la verdad... asi ocmo lo tengo, no lo es.... pero por que?

3. hay que hacer sort por end no por start.... lo se, antes pensaba que no 
importaba y es que no importa, de ambas formas se puede lograr. 
pero mira esto. tu te quedas con el intervalo que acaba antes (esa es la meta), 
si ordenas por start, no sabes caul acaba antes, si ordenas por end, 
ya esta implicito y reduce muchas pasos que aplicas en greedy como tal
*/


#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>


void quicksort(int** intervals, int inicio, int fin){    

    if (inicio >= fin){
        return;
    }
    
    int i = inicio-1;
    int pivote = intervals[fin][1];
    for (int j = inicio; j < fin; j++){
        if (intervals[j][1] <= pivote && i != j){
            i++;
            int *tmp = intervals[i];
            intervals[i] = intervals[j];
            intervals[j] = tmp;
    
        }
    }

    int *tmp = intervals[fin];
    intervals[fin] = intervals[i+1];
    intervals[i+1] = tmp;

    quicksort(intervals, inicio, i);
    quicksort(intervals, i+2, fin);
}




void eraseOverlapIntervals(int** intervals, int intervalsSize, int* intervalsColSize) {

    quicksort(intervals, 0, intervalsSize-1);   

    int end = intervals[0][1];

    printf("\n\n\n");

    int count = 0;
    for(int i = 0; i < intervalsSize-1; i++){

        if(end > intervals[i+1][0]){
            // como esta ordenado por el final, no tienenes que decidir cual tiene el end mas grande - solo te quedas con el primero
            count++;
        } else{
            end = intervals[i+1][1];
        }
    }

    printf("count: %d\n", count);
}







int main(){
    int intervalsSize = 4;

    int i1[2] = {1,2};
    int i2[2] = {2,3};
    int i3[2] = {3,4};
    int i4[2] = {1,3};

    int *intervals[4] = {i1, i2, i3, i4}; 
    int intervalsColSize = 2;


    eraseOverlapIntervals(intervals, intervalsSize, &intervalsColSize);

    return  0;
    
}

