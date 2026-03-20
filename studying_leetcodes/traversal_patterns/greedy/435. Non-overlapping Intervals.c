#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>



void eraseOverlapIntervals(int** intervals, int intervalsSize, int* intervalsColSize) {
    
    for (int i = 0; i < intervalsSize; i++){
        for (int j = 0; j < *intervalsColSize; j++){
            printf("%d\n", intervals[i][j]);
        }   
    }
}

int main(){

    int intervalsSize = 4;

    // como me gustaria poner intervalsSize donde puse el 4
    int **intervals[4] = {{1,2},{2,3},{3,4},{1,3}}; 
    int intervalsColSize = 2;

    intervalsColSize(intervals, intervalsSize, &intervalsColSize);

    return  0;
}

