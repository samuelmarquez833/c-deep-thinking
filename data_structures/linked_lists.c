#include <stdlib.h>
#include <stdio.h>



// next NO guarda un valor, guarda una dirección de otro nodo.
struct Node {
    int value;
    struct Node *next;
};



/* 
struct Node*
para que devuelva una direccion de memoria de un objeto que tiene que ser un struct Node
no se le pasa la direccion del nodo al que ha de apuntar x separacion de responsabilidades
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


void addAtEnd(int val, struct Node **head, struct Node **tail) {    
    struct Node *newNode = createNode(val);
    if (newNode == NULL) {
        return;
    }

    if (*head == NULL) {
        *head = newNode;
        *tail = newNode;
        return;
    }

    /*
    “En la dirección de memoria donde está el struct Node 
    que actualmente es el último, escribe en su campo next 
    la dirección del nuevo nodo.”
    */
    (*tail)->next = newNode;
    // eso  de arriba es lo mismo a decir
    //(*(*tail)).next = newNode;
    // solo que en el primeor el seugndo * esta implicito en la azucar sintactica
    
    *tail = newNode;
}




// sabias que no puedes imprimir un struct completo en C? no se puede
struct Node* findNode(int val, struct Node *head){
    struct Node *current = head;

    while (current != NULL) {
        if (current->value == val) {
            return current;   // encontrado
        }
        current = current->next;
    }

    return NULL; // no encontrado

}



void invertirLista (struct Node **head){


    if (*head == NULL){
        printf("La lista esta vacia");
        return;    
    }

    struct Node *second = (*head)->next;
    if (second == NULL){
        printf("La lista solo tiene un elemento ");
        return;
    }
    
    struct Node *prev = NULL;
    struct Node *curr = *head;
    struct Node *siguiente  = NULL;


    while (curr != NULL){
        siguiente = (*curr).next;
        curr->next = prev;
        prev = curr;
        curr = siguiente;
    }
    *head = prev;
}






int main (){


    
    


    // un puntero sin inicializar apunta a basura.
    // head es 0x1000
    // *head es basicamente > 0x1000 -> struct Node { value = 42, next = NULL }
    struct Node *head = NULL;
    struct Node *tail = NULL;


    /*
    Este head
    tiene una direccion de mememoria pero para que se vea en todos lados cuando la cambies
    por eso mandas la direccion
    de la variable que contiene una direccion de memoria
    estrellacuadrado
    */
    
    
    addAtBeginning(4, &head, &tail);
    addAtBeginning(3, &head, &tail);
    addAtBeginning(2, &head, &tail);
    addAtBeginning(1, &head, &tail);
    addAtEnd(5, &head, &tail);


    
    struct Node* locationOfLookedNode = findNode(3, head);

    invertirLista(*head);


    return 0;
}



/*

todo empieza en el main
caundo por definicion, tiene que haber una variable head la cual guarda la direccion del primer nodo
->     struct Node *head = NULL;
(si esta variable no esta van a habe problemas) (pero si es posible hacerlo sin esta variable)
(lo mismo con tail)

ahora llamamos a la funcion de aniadir al inicio o al final
pasamos el valor que quieres aniadir
y pasamos
la direccion de la variable que contiene la direccion de head
asi como la direccion de la variable que contiene la direccion de tail 
por que? 
por que asi y solo asi las variables declaradas en main las voy a poder modificar

ahora en la firma de las funciones (aniadir al inicio o al final)
vemos que hay un ** preceisamente por que eso se usa para poder recibir la direccion de una direccion

ahora cuando quiera modificar esa direccion que es todo lo que quiero hacer 
solo digo *head o *tail


por que no solo pasar head y tail si cuando imprimo eso ya me sale la direccion? 
no se puede pq
sino
cambia en la funcion pero en el main no


*/


/*

la azucar
(*p).propiedad = p->propiedad

sabias que
*p.campo
esta mal
pq es como decir
*(p.campo)
lo cual no existe



*/



/*
en la func de buscar nodo
printf("%p\n", current);
printf("%p\n", (void *)current);
ambos son lo mismo pero el estandar dice que el segundo es mejor
*/