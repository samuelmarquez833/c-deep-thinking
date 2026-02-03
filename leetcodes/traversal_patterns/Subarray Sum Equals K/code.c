#include <stdio.h>
#include <stdlib.h>



struct Node{
    int key;
    int value;
};

/*
Me falto la cantidad de nodos a la que puede llegar, pero creo qeu no lo necesito

en el ejmplo usan
struct node** arr;
pero aja, yo creo qeu lo puedo sustituir simplemente apuntando al primer nodo y ya

mmm, he seguido el reto y a la hora de llenar el hashmap, me doy cuenta de qeu esta mas comodo si lo hago con
struct node** arr;
por que ahora depende del array, que es basicamente, donde se guardan los nodos
*/
struct HashMap{
    int amountOfNodes;
    struct Node** arr;
};


struct Node *createNode(int key, int value){
    struct Node *node = malloc(sizeof(struct Node));
    node->key = key;
    node->value = value;
    return node;

}

struct HashMap *createHashMap(int amountOfNodes){
    
    amountOfNodes+=1;
    struct HashMap *hashMap = malloc (sizeof(struct HashMap));
    hashMap->amountOfNodes = amountOfNodes;
    hashMap->arr = malloc(amountOfNodes * sizeof(struct Node*));
    
    return hashMap;
}



void subarraySum(int* nums, int numsSize, int k) {

    int *prefixes = malloc(numsSize * sizeof(int));
    int acumulador = 0;
    int prefix = 0;

    // de seguro hay algo de lo shash maps que hace que no sea tanto problema trabajar con ellos caundo se repiten cosas y asi, pero no es el foco, enotrnces por eso me saqeu esto de los huevos 
    // de modo que caundo hay un cero, no se repita, el unico que cero qeu va a haber sera simplemente el inicial, el qeu esta de cajon. y como incluso caundo hay un cero en los prefijos, poner el cero en uno desde el inicio se tiene que hacer si o si
     
    struct HashMap *hashMap = createHashMap(numsSize); 
    *((hashMap->arr)+0) = createNode(0, 1);
    for (int i = 0; i < numsSize; i++){
        prefix = nums[i] + acumulador;
        prefixes[i] = prefix;
        if (prefix == 0){
        }else {
            int inserccionArrayDelHashMap = i+1;
            *((hashMap->arr)+inserccionArrayDelHashMap) = createNode(prefix, 0);
        }
        acumulador += nums[i];
    }


    for (int i = 0; i < numsSize+1; i++){
        printf("%d", (*((hashMap->arr)+i))->key);
    }



}






int main () {
    int largo = 6;
    int nums[] = {2, -1, 3, 1, -2, 4};
    subarraySum(nums, largo, 3);
    return 0;
}
