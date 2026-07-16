#include <stdlib.h>
#include <stdio.h>


long long int pref[1500005];

void solucion(int n, int *ais){

    // if n == 1 
    if (n == 1){
        printf("0\n");
    } else {

        pref[0] = 0;
        for (int i = 0; i < n; i++){
            pref[i+1] = pref[i] + ais[i]; 
        } 
        
        int k = 1;

        long long int diferencia = 0;
        while (k <= n){
            if (n % k == 0){
                int idxActual = k;
                long long int mayor = pref[idxActual];
                long long int menor = pref[idxActual];
                long long int diferenciaActual;
                while (idxActual <= n){
                    long long int candidato = pref[idxActual] - pref[idxActual-k];
                    if (mayor < candidato){
                        mayor = candidato;
                    }
                    if (menor > candidato){
                        menor = candidato;
                    } 
                    idxActual = idxActual + k;
                }
                diferenciaActual = mayor - menor;
                if (diferenciaActual > diferencia) diferencia = diferenciaActual;
            }
            k++;
        }

        printf("%d\n", diferencia);

    }
    



}

/*
int main (){
    int n = 4; 
    long long ais[4] = {1000000000, 1000000000, 1000000000, 1000000000};
    solucion(n, ais);
    return 1;
}
*/


int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        int n;
        scanf("%d", &n);
        int *a = malloc((n) * sizeof(int));
        scanf("%d", a);
        
        solucion(n, a);
        
        free(a);
    }
}
