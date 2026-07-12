#include <stdio.h>
#include <stdlib.h>

int min(int a, int b){
    if (a < b) return a; 
    return b; 
}
Can you open up a folder
void funcion(int n, char *a, char *b){

    int *dp = malloc((n+1) * sizeof(int));
    
    *(dp) = 0;
    for (int i = 1; i < (n+1); i++){
        *(dp+i) = 200001;
    }

    for (int i = 0; i < n; i++){
        
        int costoVertical = 0;
        if (a[i] != b[i]){
            costoVertical++;
        }
        dp[i+1] = min((costoVertical+dp[i]), dp[i+1]);

        if (i + 1 < n){
        int costoHorizontal = 0;
            if (a[i] != a[i+1]){
                costoHorizontal++;
            }
            if (b[i] != b[i+1]){
                costoHorizontal++;
            }
            dp[i+2] = min((costoHorizontal+dp[i]), dp[i+2]);
        }
    }

    printf("%d\n", *(dp+n));

}







int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        int n;
        scanf("%d", &n);
        char *a = malloc((n+1) * sizeof(char));
        char *b = malloc((n+1) * sizeof(char));
        scanf("%s", a);
        scanf("%s", b);
        
        funcion(n, a, b);
        
        free(a);
        free(b);
    }
}
