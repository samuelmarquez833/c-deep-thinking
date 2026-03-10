#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef struct Node {
  int key, val;
  struct Node* next;
} Node;

typedef struct {
  int cap;
  Node** b;
} HashMap;

static uint32_t h32(int k){
  uint32_t x = (uint32_t)k;
  x ^= x >> 16; x *= 0x7feb352dU;
  x ^= x >> 15; x *= 0x846ca68bU;
  x ^= x >> 16;
  return x;
}


HashMap *hm_new(int cap){
    HashMap *hm = malloc(sizeof(HashMap));
    hm->cap = cap;
    hm->b = malloc(cap * sizeof(Node*));
    if(hm->b == NULL){
        return 0;
    }
    return hm;
}


int hm_get(HashMap* hm, int key){
    int bucketIdx = h32(key) % hm->cap;
    Node* p = hm->b[bucketIdx];
    while (p != NULL){
        if(p->key == key){
            return p->val;
        } else{
            p = p->next;
        }
    }
    return 0;
}


void hm_inc(HashMap* hm, int key, int d){
    int idx = h32(key) % hm->cap;
    Node* p = hm->b[idx];
    while (p != NULL){
        if(p->key == key){
            p->val += d;
            return;
        } else{   
            p = p->next;
        }
    }
    Node *newNode = malloc(d * sizeof(Node*));
    newNode->key = key;
    newNode->val = d;

    
    /*
    al inicio, tenemos esto>
    m->b[3] -> A -> B -> NULL
    pero con
    newNode->next = hm->b[idx];   
    n -> A -> B -> NULL
    luego con
    hm->b[idx] = newNode; 
    m->b[3] -> n -> A -> B -> NULL

    */
    newNode->next = hm->b[idx];   
    hm->b[idx] = newNode; 
    return;
}


void hm_free(HashMap* m){
    if (!m) return;

    for (int i = 0; i < m->cap; i++){
        Node* p = m->b[i];
        while (p){
            Node* next = p->next;  
            free(p);
            p = next;
        }
    }
    free(m->b);  
    free(m);     
}


void subarraySum(int* nums, int numsSize, int k) {

    int count = 0;
    int cap = numsSize+1;
    HashMap *hm = hm_new(cap);
    
    
    int *prefixes = malloc(numsSize * sizeof(int));
    int acumulador = 0;
    int minusK = 0;
    hm_inc(hm, 0, 1);
    for(int i = 0; i < numsSize; i++){
        acumulador = acumulador + *(nums+i);  
        *(prefixes+i) = acumulador;
        printf("%d\n", *(prefixes+i));
        int consulta = acumulador-k;

        minusK = hm_get(hm, consulta);
        if(minusK > 0){
            count = count + minusK;
        }
        hm_inc(hm, acumulador, 1);
    }

    printf("\ncount: %d\n", count);

}

int main () {
    int largo = 6;
    int nums[] = {2, -1, 3, 1, -2, 4};
    subarraySum(nums, largo, 3);
    return 0;
}
