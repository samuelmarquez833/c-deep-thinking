#include <stdlib.h>
#include <stdio.h>



int main (){

    int *data = NULL;
    int len = 0; 
    int cap = 0;

    for (int i = 0; i < 20; i++){
        if (len == cap){
            cap = (cap == 0) ? 4 : cap * 2;
            int *temporal = realloc(data, cap * sizeof(int));
            if (temporal == NULL) {
                return 1;
            } else {
                data = temporal;
            }
        }

        data[len] = i;
        len++; 
    }


    free(data);

    return 0;
}