#include <stdio.h>
#include <stdlib.h>

int main (){
    
    
    int length = 5;
    char arr[5] = {'h', 'o', 'l', 'a', '\0'};
    char revertedArr[length];

    int writtingIndex = 0;
    for (int i = length-2; i >= 0; i--){
        revertedArr[writtingIndex] = arr[i];         
        writtingIndex++;
    }
    revertedArr[length-1] = '\0'; 
    
    for (int i = 0; i < length; i++){
        printf("%c", revertedArr[i]);          
    }


    return 0;
}


