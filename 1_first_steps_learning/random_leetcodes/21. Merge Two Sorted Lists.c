#include <stdlib.h>
#include <stdio.h>




struct ListNode {
    int val;
    struct ListNode *next;
};
 
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {

    if (list1 == NULL) return list2;
    if (list2 == NULL) return list1;

    struct ListNode* head = NULL;
    struct ListNode* tail = NULL;

    while (list1 != NULL && list2 != NULL) {
        struct ListNode* chosen;

        if (list1->val <= list2->val) {
            chosen = list1;
            list1 = list1->next;
        } else {
            chosen = list2;
            list2 = list2->next;
        }

        if (head == NULL) {
            head = chosen;
            tail = chosen;
        } else {
            tail->next = chosen;
            tail = chosen;
        }
    }

    if (list1 != NULL) tail->next = list1;
    else tail->next = list2;

    return head;
}


int main(){

 // ===== LISTA 1 =====
    struct ListNode* a1 = malloc(sizeof(struct ListNode));
    struct ListNode* a2 = malloc(sizeof(struct ListNode));
    struct ListNode* a3 = malloc(sizeof(struct ListNode));

    a1->val = 1;
    a2->val = 3;
    a3->val = 5;

    a1->next = a2;
    a2->next = a3;
    a3->next = NULL;

    struct ListNode* list1 = a1;   // cabeza de la lista


    // ===== LISTA 2 =====
    struct ListNode* b1 = malloc(sizeof(struct ListNode));
    struct ListNode* b2 = malloc(sizeof(struct ListNode));
    struct ListNode* b3 = malloc(sizeof(struct ListNode));

    b1->val = 2;
    b2->val = 4;
    b3->val = 6;

    b1->next = b2;
    b2->next = b3;
    b3->next = NULL;

    struct ListNode* list2 = b1;   // cabeza de la lista



    mergeTwoLists(list1, list2);




    return 0;
}