#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int buffer[200005];

void merge(int n, int *array, int offset){

    if (n == 1){
        *(buffer+offset) = *(array+0);
        return;
    }
    
    int inicioIzq = 0;
    int idxEndOne = (n/2 - 1) + offset;
    int largoOne = n/2;

    int inicioDer = n/2;
    int idxEndTwo = (n - 1) + offset;
    int largoTwo = n-n/2;

    merge(largoOne, (array+inicioIzq), inicioIzq+offset);
    merge(largoTwo, (array+inicioDer), inicioDer+offset);

    int idxEscritura = 0;
    int i = inicioIzq+offset;
    int j = inicioDer+offset;

    
    while (i <= idxEndOne || j <= idxEndTwo){
        if (i > idxEndOne){
            *(array+idxEscritura) = *(buffer+j);  
            j++; 
        } else if (j > idxEndTwo){
            *(array+idxEscritura) = *(buffer+i);  
            i++;
        } else if (*(buffer+i) >= *(buffer+j)){
            *(array+idxEscritura) = *(buffer+j);  
            j++; 
        }else if (*(buffer+i) < *(buffer+j)) {
            *(array+idxEscritura) = *(buffer+i);  
            i++;
        }
        idxEscritura++;
    }

    
    for (int i = 0; i < n; i++){
        *(buffer+offset) = *(array+i);
        offset++;
    }

}



void funcion (int n, int *array){
    merge (n, array, 0);

    

    int dif = 1000000000;

    int a = 0;
    int countA = 1;
    int b = 0;
    int countB = 1;

    int state = 0;

    
    for (int i = 1; i < n; i++){
        
        if(array[i] == array[i-1]){
            
            if (a > 0 && array[i] != a){
                b = array[i]; 
                countB++;
                printf("hay un rectangulo\n");
                printf("%d %d %d %d\n", a, a, b, b);
                state = 1;
                break;
            }

            a = array[i];
            countA++;

            if(countA == 4){
                printf("hay un cuadrado\n");
                printf("%d %d %d %d\n", a, a, a, a);
                state = 1;
                break;
            }
        }          
    }




    if(countA > 1 && countB == 1){

        if(countA % 2 == 0){
            countA++;
        } else {
            countA--;
        }

        for(int i = 1; i < n; i++){
            if (array[i] == a){
                i += countA;
            }
            
            float B = array[i];
            float b = array[i-1];
            float base = (B-b)/2;


            if (base < a){
                printf("%d %d %.0f %.0f\n", a, a, B, b);
                state = 1;
                break;
            }  
        }
    } 

    
    if (state == 0){
        printf("-1");
    }

}


/*
int main(){
    int n = 4;
    int array[] = {10,5,10,5};
    funcion(n, array);

    return 0;
}
*/


int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        int n;
        scanf("%d", &n);
        int *array = malloc(n * sizeof(int));
        scanf("%d", array);
        
        funcion(n, array);
        free(array);
    }
}



