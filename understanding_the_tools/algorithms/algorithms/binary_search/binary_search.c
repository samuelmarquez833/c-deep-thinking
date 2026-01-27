#include <stdlib.h>
#include <stdio.h>



/*  busqueda binaria iterativa */
int binary_search_iter(int *arr, int n, int target) {    
    int low = 0;
    int high = n-1;

    int mid = 0;
    for(int i = 0; i < n; i++){
        mid = low + (high-low) / 2;
        if(arr[mid] == target){
            return mid;
        } else if (arr[mid] > target){
            binary_search_iter()
            low = mid + 1;
        } else{
            high = mid - 1;
        }
    }
    return -1;
}

/*

ya para hacerla recursiva
los indices se vuelven parametros
alv

*/

int main() {
    int a1[] = {7, 2, 9, 5, 3};          // desordenado
    int a2[] = {1, 3, 5, 7, 9, 11, 15};  // ordenado

    printf("linear (5): %d\n", linear_search(a1, 5, 5));   // espera índice
    printf("linear (8): %d\n", linear_search(a1, 5, 8));   // -1

    printf("bin iter (7): %d\n", binary_search_iter(a2, 7, 7));
    printf("bin iter (8): %d\n", binary_search_iter(a2, 7, 8));

    printf("bin rec (15): %d\n", binary_search_rec(a2, 7, 15));
    printf("bin rec (0): %d\n", binary_search_rec(a2, 7, 0));

    return 0;
}