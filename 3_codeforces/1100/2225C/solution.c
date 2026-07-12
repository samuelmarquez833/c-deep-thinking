#include <stdio.h>
#include <stdlib.h>

int min (int a, int b){
    if (a < b) return a;
    return b;
}

void funcion (int n, int *a, int *b){
    int *acumulated = malloc((n+1) * sizeof(int));
    *(acumulated) = 0;
    for (int i = 1; i <= n; i++){\
        *(acumulated+i) = 10000;
    }
    int write = 1;
    int read = 0;
    int countDown = n;

    while (countDown > 0){
        int cuentaVertical = 0;
        if(a[read] != b[read]){
            cuentaVertical++;
        }
        *(acumulated+write) = min(cuentaVertical+*(acumulated+read),  *(acumulated+write) );
        if (read < (n-1)){
            int cuentaHorizontal = 0;
            if(a[read] != a[read+1]){
                cuentaHorizontal++;
            }
            if(b[read] != b[read+1]){
                cuentaHorizontal++;
            }
            *(acumulated+(write+1)) = min(cuentaHorizontal+*(acumulated+read), *(acumulated+(write+1)));
        }
        write++;
        read++;        
        countDown--;
    }
    printf("out: %d\n", acumulated[read]);
}

int main (){
    int n = 4;
    int a[4] = {'R', 'R', 'B', 'B'}; 
    int b[4] = {'B', 'B', 'R', 'B'};
    funcion (n, a, b);
    return 0;
}
