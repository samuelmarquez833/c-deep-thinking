#include <stdio.h>





void dfs(int ancho, int largo, int matrix[ancho][largo], int x, int y){
    


    
    int value_looked_for = 0;
    for(int i = 0; i < ancho; i++){
        for (int j = 0; j < largo; j++){
            if (i == y && j == x){
                value_looked_for = matrix[i][j];
            }
        }
    }

    int conteo = 0;

    
    // columnas
    // si la columan esta pegada a la izquierda, ahi dejalo
    if(x != 0){
        if (matriz[y][x-1] == value_looked_for){
            conteo++;
        }
    // si la columan esta pegada a la derecha
    }else if (x != ancho-1) {
        if (matriz[y][x+1] == value_looked_for){
            conteo++;
        }
    } 

    if (y != 0){
        if (matriz[y-1][x] == value_looked_for){
            conteo++;
        }
    }else if (y != largo-1) {
        if (matriz[y+1][x] == value_looked_for){
            conteo++;
        }
    } 



}


int main (){
    

    int ancho = 3;
    int largo = 3;
    int matrix[3][3] =  {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    // invierte los valores a la hora de decirlo
    // y los valores se ponene como si fuera un array
    // empieza en 0
    // igual,  o sea mira como se crean la smatrices para entender como poner una correndada
    //primero va la y y lueog la x, primero escoger la fila y luego la columna
    int x = 2;
    int y = 1;

    dfs(ancho, largo, matrix, x, y);


    return 0;
}