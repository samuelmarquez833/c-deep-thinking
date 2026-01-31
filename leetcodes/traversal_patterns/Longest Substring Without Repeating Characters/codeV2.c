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

        
        // chat dice esto>         if(idxs[idxFLetter] >= idxI){
        if(idxs[idxFLetter] != -1){
            printf("%d\n", largoActual);
            if (largoActual > largoMasGrande){
                largoMasGrande = largoActual;
            }

            



            // esto esta mal. es un rango, no siempre desde menos uno hasta el indice ese
            /*for (int i = -1; i < idxs[idxFLetter]; i++){
            }*/
            // en esta version incorrecta lo que pasa es que: idxI avanzaba de más (te “comías” caracteres que todavía debían seguir en la ventana).
            //asi deberia de ser el for 

            int prev = idxs[idxFLetter];
            int cantidadDeVecesABorrar = prev - idxI + 1;
            for (int i = 0; i < cantidadDeVecesABorrar; i++){
                char letraActual = string[idxI];
                idxs[letraActual] = -1;
                idxI++;
            }
        
            // no me lo salto ni hago nada
            // digamos que idxI es dos y que idxF es dos
            // entonces al salir de aqui lo primeor que hago es poner qeu 
            // idxF su indice se suma - entonces me voy al sigueinte de modo que evaluo cada letra bien
            // y tambien digo qeu su valor en la lista de trakcing (idxs)
            // es igual a idxF
            // la duda es doned hago cada uno de estos dos?
            if(idxI == idxF){
                
            }
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
    char string[] = "dvdf";
    lengthOfLongestSubstring(string);

    return 0;
}


















// file 2

#include <stdlib.h>
#include <stdio.h>
#include <string.h>














int main (){
    char string[] = "";
    lengthOfLongestSubstring(string);

    return 0;
}




























