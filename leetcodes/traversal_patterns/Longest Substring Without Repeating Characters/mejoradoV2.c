
/*

no deberia de borrar con for - sino moviendo idxI

y por ende ahora la condicion de saber si esta repetido es solo ver si el indice del
ultimo caracter es mayor al indice del primer elemento 

*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>




int lengthOfLongestSubstring(char* string) {


    int idxs[256];
    memset(idxs, -1, sizeof(idxs));

    int largoActual = 0;
    int largoMasGrande = 0;
    

    int idxI = 0;
    char idxILetter = string[idxI];
    idxs[idxILetter] = idxI;
    largoActual++;

    int idxF = idxI + 1;
    
    if (string[idxI] == '\0'){
        return 0;
    }

    while(string[idxF] != '\0'){
        char idxFLetter = string[idxF];
        if (idxs[idxFLetter] >= idxI) {
            if (largoActual > largoMasGrande) {
                largoMasGrande = largoActual;
            }
            idxI = idxs[idxFLetter] + 1;
        }
        idxs[idxFLetter] = idxF;
        idxF++;
        largoActual = idxF - idxI;
    }
    
    if (largoActual > largoMasGrande){
        largoMasGrande = largoActual;
    }

    printf("\n\n%d\n\n", largoMasGrande);
    return largoMasGrande;

}







int main (){
    char string[] = "abcabcbb";
    int output = lengthOfLongestSubstring(string);

    return 0;
}
