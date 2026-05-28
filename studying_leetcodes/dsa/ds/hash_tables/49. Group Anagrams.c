#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

struct Node {
  char* string;
  struct Node* next;
};

struct Bucket {
  char** bucket;
  int length;
  struct Node* head;
  struct Node* tail;
};

void sortWord(char* string, int largo, char *key){
  


  int *arr = malloc(largo*sizeof(int));
  
  for (int i = 0; i < largo; i++){  
    *(arr+i) = string[i];
  }

  for (int actual = 1; actual < largo; actual++){
    int nActual = *(arr+actual);  
    int pasos = 1;
    while(actual-pasos >= 0 && nActual < arr[actual-pasos]){
      int nAcambiar = arr[actual-pasos];
      arr[actual-pasos] = nActual;
      arr[(actual-pasos)+1] = nAcambiar;
      
      pasos++;
    }
  }

  int a = 0;
  while(a < largo){
    *(key+a) = *(arr+a);
    a++;
  }
  *(key+a) = '\0';
  
}

int hashing(char *key, int mod){

  int i = 0;
  int hash = 0;
  while(key[i] != '\0'){
    hash = 31*hash + key[i];
    i++;
  }
  hash = hash % 10;
  return hash;

}



void groupAnagrams(char** strs, int strsSize){


  // este si lo entinedo, no tiene sentido usar struct Bucket** en el malloc
  struct Bucket** bucketList = malloc(strsSize*sizeof(struct Bucket*));
  
  for (int i = 0; i < strsSize; i++){
    // por que malloc(sizeof(struct Bucket*)) estaria mal? 
    bucketList[i] = malloc(sizeof(struct Bucket));
    (bucketList[i])->length = 0;
    (bucketList[i])->head = NULL;
    (bucketList[i])->tail = NULL;

  }


  for (int i = 0; i < strsSize; i++){  
    int largo = 0;
    while(strs[i][largo] != '\0'){
      //printf("%c\n", strs[i][largo]);
      largo++;
    }

    char* key = malloc((largo+1)*sizeof(char));

    sortWord(strs[i], largo, key);

    int idx = hashing(key, strsSize);


    // aqui igual lo entiendo, no tiene sentido guardar espacio para la direccion de memoria, vamos a directamente almacenar un nodo ahi
    //como no lo vi? 
    struct Node* word = malloc(sizeof(struct Node));  
    
    word->string = malloc((largo+1)*sizeof(char));

      
    int a = 0;
    while(a < largo){
      (word->string)[a] = strs[i][a]; 
      printf("%c\n", (word->string)[a]);
      a++;
    }
    (word->string)[a] = '\0';
  
    printf("------------\n");


    if((bucketList[idx])->head == NULL){
      (bucketList[idx])->head = word;
      (bucketList[idx])->tail = word;
    } else{
      ((bucketList[idx])->tail)->next = word;
      // se me paso esto
      (bucketList[idx])->tail = word;
    }
    // se me paso esto
    word->next = NULL;
    (bucketList[idx])->length += 1;
  }

  for (int i = 0; i < strsSize; i++){
    int ania = (bucketList[i])->length;
    struct Node* nonio = bucketList[i]->head;
    for (int i = 0; i < ania; i++){

      printf("%s\n", nonio->string);
      nonio = nonio->next;
    }
  }


  for (int i = 0; i < strsSize; i++){
    int ania = (bucketList[i])->length;
    struct Node* nonio = bucketList[i]->head;
    for (int i = 0; i < ania; i++){

      printf("%s\n", nonio->string);
      nonio = nonio->next;
  }
  


}


void main(){

  int strsSize = 6;

  char* strs[] = {"eat","tea","tan","ate","nat","bat"};

  groupAnagrams(strs, strsSize);


}


