#include <stdlib.h>
#include <stdio.h>






int partition (int arr[], int low, int high){

    int peabody = arr[high];
    int low = -1;

    // la clave de partition esta en el indice que indica
    //donde esta el elemento mas pequenio

    for (int j = 0; j <  high; j++){
        if(arr[j] < peabody){
            low++;
            int buffer = arr[low];
            arr[low] = arr[j];
            arr[j] = buffer;
        }
    }

    int buffer = arr[high-1];
    arr[high-1] = arr[low+1];
    arr[low+1] = buffer;
    int p = low+1;

    return p;

}


void quicksort(int arr[], int low, int high){
    if (low >= high) return;

    int p = partition(arr, low, high);

    quicksort(arr, low, p - 1);
    quicksort(arr, p + 1, high);
}



int main (){
    int arr[5] = {9,10,2,6,7};
    int low = 0;
    int high = 4;
    
    quicksort(arr, low, high);

    return 0;
}