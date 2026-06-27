#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

struct Node {
  char* string;
  struct Node* next;
};

struct Group{
  char* key;
  int length;
  struct Node* head;
  struct Node* tail;
  struct Group* next;
};

struct Bucket {
  int groupsAmount;
  struct Group* head;
  struct Group* tail;
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



char*** groupAnagrams(char** strs, int strsSize){


  struct Bucket* bucketList = malloc(strsSize*sizeof(struct Bucket));

  for (int i = 0; i < strsSize; i++){
    bucketList[i].head = NULL;
    bucketList[i].tail = NULL;
    bucketList[i].groupsAmount = 0;
  }


  for (int i = 0; i < strsSize; i++){
    int largo = 0;
    while(strs[i][largo] != '\0'){
      largo++;
    }

    char* key = malloc((largo+1)*sizeof(char));

    sortWord(strs[i], largo, key);

    int idx = hashing(key, strsSize);



    // 
    struct Node* word = malloc(sizeof(struct Node));
    word->string = malloc((largo+1)*sizeof(char));
    int a = 0;
    while(a < largo){
      (word->string)[a] = strs[i][a];
      //printf("%c\n", (word->string)[a]);
      a++;
    }
    (word->string)[a] = '\0';


    

    if((bucketList[idx]).head == NULL){
      struct Group* newGroup = malloc(sizeof(struct Group));
      newGroup->key = key;
      newGroup->head = word;
      newGroup->tail = word;
      word->next = NULL;
      bucketList[idx].head = newGroup;
      bucketList[idx].tail = newGroup;
      newGroup->length = 1;
      newGroup->next = NULL;
      bucketList[idx].groupsAmount = 1;
    } else{

      struct Group* grupoActual = bucketList[idx].head;
      bool state = true;
      while (grupoActual != NULL){
        if(strcmp(grupoActual->key, key) == 0){
          ((grupoActual->tail)->next) = word;
          (grupoActual->tail) = word;
          grupoActual->length += 1;
          word->next = NULL;
          state = false;
          break;
        }
        grupoActual = grupoActual->next;
      }

      if (state){
        struct Group* newGroup = malloc(sizeof(struct Group));
        newGroup->key = key;
        newGroup->head = word;
        newGroup->tail = word;
        word->next = NULL;
        ((bucketList[idx].tail)->next) = newGroup; 
        bucketList[idx].tail = newGroup;
        newGroup->length = 1;
        newGroup->next = NULL;
        bucketList[idx].groupsAmount += 1;
      }
    }
  }



  
  int totalGroups = 0;


  
  for (int i = 0; i < strsSize; i++){
      totalGroups += bucketList[i].groupsAmount;
  }

  int* columns = malloc (totalGroups*sizeof(int));

  int indiceDeArrayDeChar = 0;
  char*** arrayDeArraysDeCharS = malloc(totalGroups * sizeof(char**));


  for (int i = 0; i < strsSize; i++){
    
    if (bucketList[i].head != NULL){
      struct Group* grupoActual = bucketList[i].head;
      

      while(grupoActual != NULL){
        struct Node* palabra = grupoActual->head;
        columns[indiceDeArrayDeChar] =  grupoActual->length;
        arrayDeArraysDeCharS[indiceDeArrayDeChar] = malloc(grupoActual->length * sizeof(char*));
        int indiceDentroDelArrayDeGrupo = 0;

        while(palabra != NULL){

          arrayDeArraysDeCharS[indiceDeArrayDeChar][indiceDentroDelArrayDeGrupo] = palabra->string; 
          
          printf("%s\n", arrayDeArraysDeCharS[indiceDeArrayDeChar][indiceDentroDelArrayDeGrupo]);

          palabra = palabra->next;
          indiceDentroDelArrayDeGrupo += 1;




        }

        grupoActual = grupoActual->next;
        printf("cambio de grupo\n");
        indiceDeArrayDeChar++;
      }
    }

  }

  return arrayDeArraysDeCharS;

}




void main(){

  int strsSize = 6;

  char* strs[] = {"eat","tea","tan","ate","nat","bat"};

  groupAnagrams(strs, strsSize);


}