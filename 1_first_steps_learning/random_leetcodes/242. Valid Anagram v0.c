
// o 
// pero este no puedes compar acceder y la chingadera
// este es mas rapido sirve para cuando la cosa es pesada o partes de memoria etc
// char *word = "nat";

#include <stdlib.h>
#include <stdio.h>



bool esAnagrama(char wordOne[], char wordTwo[], int length){
    for(int i = 0; i < length; i++){
        for(int j = 0; j < length; j++){
            if(wordOne[i] == wordTwo[j]){
                wordTwo[j] = '0';
            }
        }
    }

    for(int i = 0; wordTwo[i] != '\0'; i++){
        if(wordTwo[i] != '0'){
            return false;
        }
    }

    return true;
}


int main (){
    
    int wordsLength = 3;
    int wordsInArray = 5;    
    char *words[] = { "eat", "tan", "ate", "eta", "tna"};

    int **arrayofarrays[3] = {{3,5,2}, {0,4,2,1,5}, {4,9,6}};
    for(int i = 0; i < 3; i++){
        printf("%d", *arrayofarrays[i]);
    }


/*
    for(int i = 0; i < wordsInArray; i++){
        for(int j = i; j < wordsInArray; j++){
            bool aja = esAnagrama(*words[i], *words[j], wordsLength);
            if (aja){
                
            }
        }   
    }
*/
    

    return 0;
}

