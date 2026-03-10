
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "uthash.h"




typedef struct {
    char key;
    int value;             
    UT_hash_handle hh;     
} HashItem;


void put(HashItem **map, char key, int value){
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


int get(HashItem *map, char key){
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


void inc(HashItem **map, char key){
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
    int *prefixes = malloc(newLength * sizeof(int));
    int acumulador = 0;

    for (int i = 0; i < numsSize; i++){
        acumulador += *(nums+i);
        *(prefixes+i) = acumulador;
        put(&map, acumulador, 1);

        /*printf("acumulador: %d\n", acumulador );
        printf("prefijo: %d\n", *(prefixes+i) );
        printf("mapa[%d]: %d\n\n", acumulador, get(map, acumulador));*/
        if (get(map, (acumulador-k)) == 1){
            contador++;
        }
    }

    
    printf("%d\n", contador);


}




int main () {
    int largo = 6;
    int nums[] = {2, -1, 3, 1, -2, 4};
    subarraySum(nums, largo, 3);
    return 0;
}


