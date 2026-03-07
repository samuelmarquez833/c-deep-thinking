/*
mejora 1 - hacemos que lago actual no sea a mano sino que dependa de los indices
mejora 2 - la logica del while era  inecesariamente larga y complicada
*/


#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int lengthOfLongestSubstring(char* string) {

    if (string[0] == '\0') return 0;

    int count[256];
    memset(count, 0, sizeof(count));

    int idxI = 0;
    char idxILetra = string[idxI];
    count[(unsigned char)idxILetra]++;

    int largoActual = 1;
    int largoMasGrande = 0;

    int idxF = idxI + 1;

    while (string[idxF] != '\0') {
        char idxFLetra = string[idxF];
        count[(unsigned char)idxFLetra]++;

        while (count[(unsigned char)idxFLetra] > 1){
            count[(unsigned char)string[idxI]]--;
            idxI++;
        }

        largoActual = idxF - idxI + 1;


        if (largoActual > largoMasGrande) {
            largoMasGrande = largoActual;
        }
        idxF++;
    }


    return largoMasGrande; 
}

int main() {
    char string[] = "dvdf";
    int output = lengthOfLongestSubstring(string);
    printf("%d", output);
    return 0;
}
