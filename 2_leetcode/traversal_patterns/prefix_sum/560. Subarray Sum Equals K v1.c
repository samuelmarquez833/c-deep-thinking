
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "uthash.h"


//1.  el hashmap usado aqui especifica que uses un char key
// pero en realidad guardas un int (al menos antes estaba para char key) - corregir eso arriba

typedef struct {
    int key;
    int value;             
    UT_hash_handle hh;     
} HashItem;


void put(HashItem **map, int key, int value){
    HashItem *item;
    HASH_FIND(hh, *map, &key, sizeof(char), item);

    if (item == NULL){
        item = malloc(sizeof(HashItem));
        item->key = key;
        item->value = value;
        HASH_ADD(hh, *map, key, sizeof(char), item);
    }else{
        item->value = value;
    }
}


int get(HashItem *map, int key){
    HashItem *item;
    HASH_FIND(hh, map, &key, sizeof(char), item);
    if (item == NULL) return -1;

    return item->value;
}


void free_map(HashItem **map){
    HashItem *current;
    HashItem *tmp;

    HASH_ITER(hh, *map, current, tmp){
        HASH_DEL(*map, current);
        free(current);
    }
}



void print_map(HashItem *map) {
    HashItem *item;

    for (item = map; item != NULL; item = item->hh.next){
        printf("%c -> %d\n", item->key, item->value);
    }
}


void inc(HashItem **map, int key){
    HashItem *item;
    HASH_FIND(hh, *map, &key, sizeof(char), item);

    if (item == NULL){
        item = malloc(sizeof(HashItem));
        item->key = key;
        item->value = 1;
        HASH_ADD(hh, *map, key, sizeof(char), item);
    }
    else{
        item->value++;
    }
}








































    /*
    print_map(map);
    printf("e -> %d\n", get(map, 'e'));
    put(&map, 'p', 1);
    */








void subarraySum(int* nums, int numsSize, int k) {
    HashItem *map = NULL;   

    int contador = 0;

    put(&map, 0, 1);
    int newLength = numsSize+1;   
    // he declarado un array llamado prefixes el cual relamente no necesitaba
    // int *prefixes = malloc(newLength * sizeof(int));
    int acumulador = 0;

    for (int i = 0; i < numsSize; i++){
        acumulador += *(nums+i);
        

        // 2. hace rato pusiste> put(&map, acumulador, 1);
        // pero en realidad es>
        inc(&ma, acumuladorp)
        // por que mira, imaigna este ejemplo> {1, -1, 1, -1, 1} donde k=1
        // cuanod vaya en la tercer aiteracion o sea en el segundo uno
        // ya tienes tres subarrays que suman 1 el primer uno, luego el desde el primer uno hasta el segundo y por ultimo el seugndo uno
        // pero si caunod llegas al primer MENOS UNO, dices, que pues el prefijo sea igual a uno (lo cual habias escrito)
        // caunod llegues al segundo uno diras
        // if (get(map, (acumulador-k)) == 1) lo cual es cierto
        // aumenta contador en uno, pero la verdad es qeu eso solo vale por el subarrary del uno
        // no tambien por el subarray de 1 -1 1
        // pero si aumentas cada vez que vez el prefijo y caundo aumentas contador lo aumentas la cantidad de veces que esta guardado el prefijo
        // te da bien

        // resumen de lo anterior y regla general:
        
// regla:
// si prefix_actual - CUALQUIER_N_VECES_prefix_anterior = k
// entonces el subarray entre esos puntos suma k

        if (get(map, (acumulador-k)) == 1){
            // antes pusiste contador++;
            //pero en verdad es:
            contador += get(map, (acumulador-k));
        }
    }
    
    printf("%d\n", contador);


}




int main () {
    int largo = 5;
    int nums[] = {1, -1, 1, -1, 1};
    subarraySum(nums, largo, 1);
    return 0;
}


