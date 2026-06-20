/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>




struct AuxNode {
    struct TreeNode* realNode;

    bool visitado;
    int accumulated;

    struct AuxNode* left;
    struct AuxNode* right;

    struct AuxNode* prev;
};



struct Stack {
    struct AuxNode* top;
};








struct Stack* stack;

int escogerLoMasGrande(int a, int b, int b_existe, int c, int c_existe, int *global){
    
    // Lo que le reportamos al papa (solo un lado)
    int maxi = a;
    if(b_existe && b > 0) maxi = a + b;
    if(c_existe && c > 0 && a + c > maxi) maxi = a + c;

    // Lo que considera global (puede cruzar, usar ambos lados)
    int suma = a;
    if(b_existe && b > 0) suma += b;
    if(c_existe && c > 0) suma += c;
    if(suma > *global) *global = suma;

    return maxi;
}




struct AuxNode* crearNodoMioApartirDeTreeNode(struct TreeNode* treeNode){
    struct AuxNode* nodoMio = malloc(sizeof(struct AuxNode));
    nodoMio->realNode = treeNode;
    nodoMio->visitado = false;
    nodoMio->accumulated = 0;
    
    nodoMio->left = NULL;
    nodoMio->right = NULL;

    nodoMio->prev = NULL;
    
    return nodoMio;
}




int maxPathSum(struct TreeNode* root) {


    stack = malloc(sizeof(struct Stack));
    stack->top = NULL;

    int global = root->val;
    

    struct AuxNode* rootNode = crearNodoMioApartirDeTreeNode(root);
    stack->top = rootNode;

    /*if((rootNode->realNode)->right != NULL){
        struct AuxNode* nodoB =  crearNodoMioApartirDeTreeNode((rootNode->realNode)->right);
        rootNode->right = nodoB;
        if(stack->top == NULL){
            nodoB->prev = NULL;
        } else if (stack->top != NULL){
            nodoB->prev = stack->top;
        }
        stack->top = nodoB;
    }


    if((rootNode->realNode)->left != NULL){
        struct AuxNode* nodoA = crearNodoMioApartirDeTreeNode((rootNode->realNode)->left);
        rootNode->left = nodoA;
        if(stack->top == NULL){
            nodoA->prev = NULL;
        } else if (stack->top != NULL){
            nodoA->prev = stack->top;
        }
        stack->top = nodoA;
    }*/


    // a ver, de momento hay solo dos
    // 20 primero y luego 9
    
    while(stack->top != NULL){
        

        struct AuxNode* nodoParaAnalizar = stack->top; 



        /*si izq o derecha no son NULL YY el nodo no ha sido visitado
            si izq no es null, mete al stack
            si der no es null, mete al stack
            marcalo como visitado
            continue*/

        if(nodoParaAnalizar->visitado == false){

            if((nodoParaAnalizar->realNode)->right != NULL){
                struct AuxNode* nodoB = crearNodoMioApartirDeTreeNode((nodoParaAnalizar->realNode)->right);
                nodoParaAnalizar->right = nodoB;
                if(stack->top == NULL){
                    nodoB->prev = NULL;
                } else if (stack->top != NULL){
                    nodoB->prev = stack->top;
                }
                stack->top = nodoB;

            }

            if((nodoParaAnalizar->realNode)->left != NULL){ 
                struct AuxNode* nodoA = crearNodoMioApartirDeTreeNode((nodoParaAnalizar->realNode)->left);
                nodoParaAnalizar->left = nodoA; 
                if(stack->top == NULL){
                    nodoA->prev = NULL;
                } else if (stack->top != NULL){
                    nodoA->prev = stack->top;
                }
                stack->top = nodoA;        
            }
            

            nodoParaAnalizar->visitado = true;
            
            
            //printf("esto ahora es true: %d\n", (nodoParaAnalizar->realNode)->val);

            continue;
        }
        

        int a = (nodoParaAnalizar->realNode)->val;
        int b = 0;
        int c = 0;
        int b_existe = 0;
        int c_existe = 0;
        
        if (nodoParaAnalizar->visitado == true){
            if((nodoParaAnalizar->realNode)->left != NULL){
                b = (nodoParaAnalizar->left)->accumulated;
                b_existe = 1;
            }
            if((nodoParaAnalizar->realNode)->right != NULL){
                c = (nodoParaAnalizar->right)->accumulated;
                c_existe = 1;
            }

            /*printf("%d\n", a);
            printf("%d\n", b);
            printf("%d\n", c);*/
            

            nodoParaAnalizar->accumulated = escogerLoMasGrande(a, b, b_existe, c, c_existe, &global);




        }
        
        //printf("tenemos acumulado: %d\n", nodoParaAnalizar->accumulated);
        //printf("\n\n\n");

        stack->top = (stack->top)->prev;


        /*si el nodo ya fue visitado, ES POR QUE, YA METIMOS A SUS HIJOS EN EL STACK y es hora de calcular su calculated
        crea las varibables con las que se puedan crear si es que is lo tienen
        escoge las mas grande, ponle valor a calculated
        quita del top*/

        
       


    }

    printf("top global: %d\n", global);
    
    return global;
}


