#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node *left;
    struct Node *right;
} Node;

Node* node_create(int value) {
    Node *n = (Node*)malloc(sizeof(Node));
    if (!n) return NULL;
    n->value = value;
    n->left = NULL;
    n->right = NULL;
    return n;
}

void freeTree(Node *root){
    free (root);
}



/*
un dfs

*/


int count_nodes(Node *root ){
    if (root == NULL){
        return 0;
    }

    int left_count  = count_nodes(root->left);
    int right_count = count_nodes(root->right);

    int total = 1 + left_count + right_count;
    return total;
}


int findMax(int first, int second){
    if (first > second) return  first;
    return second;
}


int height (Node *root){
    if (root == NULL){
        return 0;
    }

    int left_count  = height(root->left);
    int right_count = height(root->right);

    int maximo = findMax(left_count, right_count);
    maximo += 1;
    return maximo;
}


Node *contains(Node *root, int val){
    
    if (root == NULL){
        return NULL;
    }

    if (root->value == val){
        return root;
    } 


    Node *leftNode = contains (root->left, val);
    if (leftNode){
        return leftNode;
    }

    Node *rightNode = contains (root->right, val);
    if (rightNode){
        return rightNode;
    }

    return NULL;
}



int count_leaves(Node *root){
    if (root == NULL){
        return 0;    
    }

    int conteoPorLaIzq = 0;
    int conteoPorLaDer = 0;
    int conteoDeHojas = 0; 
    if (root->left == NULL && root->right == NULL){
        conteoDeHojas++;
    } else{
        conteoPorLaIzq = count_leaves(root->left);
        conteoPorLaDer = count_leaves(root->right);
        conteoDeHojas = conteoPorLaIzq + conteoPorLaDer;

    }
    return conteoDeHojas;
}


#include <stdio.h>

void print_levels_bfs(Node *root) {
    if (root == NULL) return;

    Node *queue[100];
    int front = 0, back = 0;

    queue[back++] = root;

    while (front < back) {
        int level_size = back - front;

        for (int i = 0; i < level_size; i++) {
            Node *curr = queue[front++];
            printf("%d ", curr->value);

            if (curr->left)  queue[back++] = curr->left;
            if (curr->right) queue[back++] = curr->right;
        }
        printf("\n");
    }
}



int main(void) {
    Node *root = node_create(10);
    Node *one = node_create(5);
    Node *two = node_create(3);
    Node *three = node_create(15);
    
    root->left = one;
    one->left = two;
    root->right = three;

    

    int amount_of_node = count_nodes(root);
    printf("amount_of_nodes in the tree: %d \n", amount_of_node);

    printf("la direccion del 3 es: %d\n", two);
    
    Node *lookedFor = contains(root, 3);
    printf("la direccion del numero buscado (3) es: %d\n", lookedFor);
    
    int conteoDeHojas = count_leaves(root);
    printf("%d", conteoDeHojas);

    // listo: ya existe el árbol (3 nodos)
    return 0;
}
