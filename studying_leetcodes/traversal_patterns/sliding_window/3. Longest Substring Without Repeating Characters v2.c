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










int lengthOfLongestSubstring(char* string) {
    HashItem *map = NULL;   

    // manejar el caso borde
    if (string[0] == '\0'){
        return 0;
    }

    int n = 0;

    
    while(string[n] != '\0'){
        put(&map, string[n], 0);
        n++;
    }

    /*
    print_map(map);
    printf("e -> %d\n", get(map, 'e'));
    put(&map, 'p', 1);
    */


    
    int left = 0; 
    inc(&map, string[left]);        

    int countFinal = 1; 
    int cuentatemporal = 0;

    int right = 1;
    printf("%d\n", right);
    while (right < n){
        inc(&map, string[right]);  

        if (get(map, string[right]) > 1){
            // brother no puedes poner un la madre que actulizar el largo aqui
            // por que imagina, is lo pones ahi, y tinees un arrya muy bueno, entonces, nunca lo vas a actualizar


            while(get(map, string[right]) > 1){
                // claro conio no  tien epor qeu bajar hasta cero, hace rato pusiste directo qeu sea igual a cero
                // pero debe de ser igual solo a menos uno su valor - esto por qeu no puedes dejar la letra que la cago igual a cero sino a uno
                put(&map, string[left], get(map, string[left]) - 1);
                left++;
                
                // tampoco necesitas decrementar la pinche cuenta no me jodasaaaaaaaaaaass
                // literlamente le calculo de right menos left mas uno y ate lo da. aaaaaaahhhhhh
                //cuentatemporal--;
            }
        } 

        // aqui si peudes poner sin problema el actulizar la cuenta
        cuentatemporal = right - left + 1;
        if (cuentatemporal > countFinal){
            countFinal = cuentatemporal;
        }


        // hace rato habias puesto solo
        // cuentatemporal++;
        // peor no le habias puesto  el menos menos en el while de arriba
        // primer error
        // lueog vienesy actualizar la logica por que te das ceunta de que cuenta final lo debes de actulizar despues de evaluar el caso
        // y no eliminas el chingado cuentatemporal++;
        // segundo error
        
        right++;
    }


    return countFinal;

}






int main (){
    char string[] = "pwwkew";
    int a = lengthOfLongestSubstring(string);
    printf("output: %d\n", a);
    return 0;
}

