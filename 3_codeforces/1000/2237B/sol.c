#include <stdio.h>
#include <stdlib.h>

void funcion(int length, int *a, int *b){
    int *cambios = malloc (length * sizeof(int));
    

    
    int limite = b[length-1];
    int mal = 0;
       
    for (int i = 0; i < length; i++){
        int parejaActual = limite;
        int idxParaMatar = -1;
        for (int j = 0; j < length; j++){
            if(b[j] >= a[i] && b[j] <= parejaActual && b[j] != 0){
                parejaActual = b[j];
                idxParaMatar = j;
            }
        }
        
        //printf("idxParaMatar=%d\n", idxParaMatar);
        //printf("a i: %d\n", a[i]);   
        //printf("parejaActual: %d\n", parejaActual); 
        

        
        if (parejaActual < a[i] || idxParaMatar == -1){
            mal = 1;
        } else if(idxParaMatar != -1){
            b[idxParaMatar] = 0;
            *(cambios+i) = idxParaMatar;
        } 
    }
    
    int count = 0;

    if (mal == 1){
        count = -1;
    } else {
        for (int i = 0; i < length-1; i++){
            for (int j = i+1; j < length; j++){
                //printf("i: %d j: %d\n", cambios[i], cambios[j]);
                if (cambios[i] > cambios[j]){
                    count++;                
                }
            }   
        }
    }

    printf("%d\n", count);
    

}


int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        int n;
        scanf("%d", &n);
        int *a = malloc(n * sizeof(int));
        int *b = malloc(n * sizeof(int));
        for(int i = 0; i < n; i++) scanf("%d", &a[i]);
        for(int i = 0; i < n; i++) scanf("%d", &b[i]);
        
        funcion(n, a, b);
        
        free(a);
        free(b);
    }
}


