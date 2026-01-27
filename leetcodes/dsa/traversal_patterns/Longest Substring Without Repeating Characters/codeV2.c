#include <stdlib.h>
#include <stdio.h>
#include <string.h>



void lengthOfLongestSubstring(char* string) {


    int idxs[256];
    memset(idxs, -1, sizeof(idxs));

    int largoActual = 0;
    int largoMasGrande = 0;
    

    int idxI = 0;
    char idxILetter = string[idxI];
    idxs[idxILetter] = idxI;
    largoActual++;

    int idxF = idxI + 1;

    while(string[idxF] != '\0'){

        char idxFLetter = string[idxF];
        
        if(idxs[idxFLetter] != -1){
            printf("%d\n", largoActual);
            if (largoActual > largoMasGrande){
                largoMasGrande = largoActual;
            }

            

            // esto esta mal. es un rango, no siempre desde menos uno hasta el indice ese
            for (int i = -1; i < idxs[idxFLetter]; i++){

            }



        } 

          

    }


    printf("\n\n%d\n\n", largoMasGrande);

}














int main (){
    char string[] = "dvdf";
    lengthOfLongestSubstring(string);

    return 0;
}























