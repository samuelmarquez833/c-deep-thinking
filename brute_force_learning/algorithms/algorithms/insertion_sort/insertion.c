#include <stdio.h>

int main() {
    
    int length = 13;
    int arr[13] = {11, 1, 6, 2, 13, 3, 4, 12, 8, 9, 5, 7, 10};
    
    int a = 0;
    for(int i = 1; i < length; i++){
        int actual = arr[i];
        a = 0;
        for(int j=i-1; j >= 0; j--){
            if(actual < arr[j]){
                arr[i-a] = arr[j];
                arr[j] = actual;
                a++;
            } else if(actual > arr[j] || actual == arr[j]){
                // solo quiero qeu se salga y qeu i crezca en uno
                break;
            } 
        }
    }

    for (int i = 0; i < length; i++){
        printf("Elemento: %d: %d \n", i+1, arr[i]);
    }
    
    return 0;
}