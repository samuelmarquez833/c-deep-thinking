#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>




bool cabe(int l, int w, int f){
    l = l - f;
    w = w - f;
    if(l < 0 || w < 0){
        return 0;
    } else if (l >= 0 && w >= 0){
        return 1;
    }

}


void solucion(int n, int m, int **boxes){


    int a = 1;
    int b = 1;
    int buffer = a;
    while (n > 1){
        buffer = b;
        b = b + a;
        a = buffer;
        n--;
    }


    for(int i = 0; i < m; i++){
    
        int mayor = 0; 
        int x = 0;
        int y = 0;

        if(*(*(boxes+i)) >= *(*(boxes+i)+1) && *(*(boxes+i)) >= *(*(boxes+i)+2)){
            mayor = *(*(boxes+i));
            x = *(*(boxes+i)+1);
            y = *(*(boxes+i)+2);
        } else if (*(*(boxes+i)+1) >= *(*(boxes+i)) && *(*(boxes+i)+1) >= *(*(boxes+i)+2)){
            mayor = *(*(boxes+i)+1);
            x = *(*(boxes+i));
            y = *(*(boxes+i)+2);
        } else if (*(*(boxes+i)+2) >= *(*(boxes+i)) && *(*(boxes+i)+2) >= *(*(boxes+i)+1)){
            mayor = *(*(boxes+i)+2);
            x = *(*(boxes+i)+1);
            y = *(*(boxes+i));
        }


        if (mayor >= a+b && cabe(x,y,b)){
            printf("1");
        } else {
            printf("0");
        }

    }

    printf("\n");


}


int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        int n, m;
        scanf("%d %d", &n, &m);

        int cols = 3;
        int **boxes = malloc(m * sizeof(int*));

        for(int i = 0; i < m; i++){
            boxes[i] = malloc(cols * sizeof(int));
            for(int j = 0; j < cols; j++){
                scanf("%d", &boxes[i][j]);
            }
        }

        solucion(n, m, boxes);

        for(int i = 0; i < m; i++)
            free(boxes[i]);
        free(boxes);
    }

    return 0;
}