/*
Aqui en vez de usar las posiciones para asi calcular largos, o para saber hasta caundo hacer for

solamente, me baso en una lista que lleva registro de cuantas veces ha aparecido la leta

-1 es que ha aparecido 0 veces
0 es una vez 
1 ya son dos veces

(lo voy a cambiar en la gran limpia)


*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>


int lengthOfLongestSubstring(char* string) {

    if (string[0] == '\0') return 0;

    int last[256];
    memset(last, -1, sizeof(last));

    int idxI = 0;
    char idxILetra = string[idxI];
    last[(unsigned char)idxILetra]++;

    int largoActual = 1;
    int largoMasGrande = 1;

    int idxF = idxI + 1;

    while (string[idxF] != '\0') {
        char idxFLetra = string[idxF];
        last[(unsigned char)idxFLetra]++;

        if (last[(unsigned char)idxFLetra] == 1) {
            if (largoActual > largoMasGrande) {
                largoMasGrande = largoActual;
            }

            while (string[idxI] != idxFLetra) {
                char idxILetra = string[idxI];
                last[(unsigned char)idxILetra]--;
                largoActual--;
                idxI++;
            }

            last[(unsigned char)string[idxI]]--;
            idxI++;
            largoActual--;
        }

        largoActual++;


        idxF++;
    }


    if (largoActual > largoMasGrande) {
        largoMasGrande = largoActual;
    }

    printf("%d", largoMasGrande);
    return 0;
}







int main (){
    char string[] = "pwwkew";
    int output = lengthOfLongestSubstring(string);
    return 0;
}



