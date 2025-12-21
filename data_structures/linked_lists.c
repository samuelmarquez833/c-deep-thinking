#include <stdlib.h>
#include <stdio.h>



struct Node {
    int value;
    struct Node *next;
};

/*
struct Node*
tiene que tener su * pq sino
El struct Node vive en el stack
Al salir de la función → desaparece
La lista enlazada queda apuntando a nada válido
*/

/* 
cuando escribie el segundo parametro de la func puse
int *next
pero next NO es un puntero a int.
next debe apuntar a:
otro nodo - no a un entero
El tipo correcto del parametro next es:
struct Node *

ahora, ese parametro ni deberia de ir ahi
no va x separacion de responsabilidades
una cosa es crear el nodo y otra es la logica de enlace de la lista

*/
struct Node* createNode(int val){
    struct Node *node = malloc(sizeof(struct Node));
    if (node == NULL){
        return NULL;
    }
    node->value = val;
    node->next = NULL;
    return node;
}



/*
Pero mejorando la funcion
queda algo asi
*/

/*
estrellacuadrado
por eso ponemos el ** para que lo pueda admitir
*/
void addAtBeginning(int val, struct Node **head, struct Node **tail) {
    struct Node *newNode = createNode(val);
    if (newNode == NULL) {
        return;
    }

    // Caso: lista vacía
    if (*head == NULL) {
        *head = newNode;
        *tail = newNode;
        return;
    }

    // Caso: lista no vacía
    newNode->next = *head;
    *head = newNode;
}


void addAtBeginning(int val, struct Node **head, struct Node **tail) {    struct Node *newNode = createNode(val);
    if (newNode == NULL) {
        return;
    }

    if (*head == NULL) {
        *head = newNode;
        *tail = newNode;
        return;
    }
    
    (*tail)->next = newNode;
    *tail = newNode;
    

}





int main (){

    // un puntero sin inicializar apunta a basura.
    // head es 0x1000
    // *head es basicamente > 0x1000 -> struct Node { value = 42, next = NULL }
    struct Node *head = NULL;

    /*
    Este head
    tiene una direccion de mememoria pero para que se vea en todos lados cuando la cambies
    por eso mandas la direccion
    de la variable que contiene una direccion de memoria
    estrellacuadrado
    */

    // aja lo mismo para con tail pero para el final


    struct Node *tail = NULL;

    addAtBeginning(4, &head, &tail);
    addAtEnd(5, &head, &tail);


    return 0;
}