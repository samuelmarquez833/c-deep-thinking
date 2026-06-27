#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>


int** sort(int** intervals, int intervalsSize) {    
    for (int i = 1; i < intervalsSize; i++){
        int n = i;
        for (int j = 1; j <= i; j++){
            if (intervals[n][0] < intervals[i-j][0]){
                //printf("Hay cambio \n");
                int *tmp = intervals[n];
                intervals[n] = intervals[i-j];
                intervals[i-j] = tmp;
                n--;
            } else{
                break;
            }
        }
    }

    return intervals;
}




void eraseOverlapIntervals(int** intervals, int intervalsSize, int* intervalsColSize) {

    intervals = sort(intervals, intervalsSize);   
    
    int start = intervals[0][0];
    int end = intervals[0][1];
    //printf("start: %d \nend: %d\n", start, end);

    int count = 0;
    for(int i = 0; i < intervalsSize-1; i++){
        printf("n\n");
        printf("start: %d \nend: %d\n", start, end);
        printf("n+1\n");
        printf("start: %d \nend: %d\n", intervals[i+1][0], intervals[i+1][1]);
        

        if(end > intervals[i+1][0]){
            if(end > intervals[i+1][1]){
                printf("caso 1\n\n");
                start = intervals[i+1][0];
                end = intervals[i+1][1];
                count++;
            }else{
                printf("caso 2\n\n");
                start = start;
                end = end;
                count++;

            }
        } else{
            printf("caso 3\n\n");
            start = intervals[i+1][0];
            end = intervals[i+1][1];
        }
    }

    printf("count: %d\n", count);
}




int main(){

    int intervalsSize = 4;

    // como me gustaria poner intervalsSize donde puse el 4
    int i1[2] = {1,2};
    int i2[2] = {2,3};
    int i3[2] = {3,4};
    int i4[2] = {1,3};

    int *intervals[4] = {i1,i2,i3,i4}; 
    int intervalsColSize = 2;

    eraseOverlapIntervals(intervals, intervalsSize, &intervalsColSize);

    return  0;
}

