#include <stdlib.h>
#include <stdio.h>

void funcion (int s, char *string){

    int cuentaDeCambios = 0;
    if (string[0] == '1') {
        cuentaDeCambios++;
    }

    for (int i = 1; i < s; i++){
        if (string[i] != string[i-1]){
            cuentaDeCambios++;
        }
    }

    if (cuentaDeCambios >= 3){
        cuentaDeCambios -= 2;
    } else if (cuentaDeCambios == 2){
        cuentaDeCambios -= 1;
        
    }


    int costo = s + cuentaDeCambios;

    printf("%d\n", costo);
    
}



/*
int main (){

    int n = 3;
    char string[3] = {'0','0','0',};  
    funcion(n, string);

    return 0;
}
*/



int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        int n;
        scanf("%d", &n);
        char *string = malloc((n + 1) * sizeof(char));
        scanf("%s", string);
        
        funcion(n, string);
        free(string);
    }
}
