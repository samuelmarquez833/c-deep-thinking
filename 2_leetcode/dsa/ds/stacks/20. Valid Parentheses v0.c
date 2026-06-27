#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>




struct Node{
  char value;
  struct Node* next;
};

struct Stack {
  struct Node* top;
};


void pop(struct Stack* stack){
  struct Node* ogTop = stack->top;

  stack->top = ogTop->next;
  free(ogTop);

}

bool isValid(char* s) {
  struct Stack* stack = malloc(sizeof(struct Stack));
  int i = 0;
  stack->top = NULL;
  while(s[i] != '\0'){

    if(s[i] == '(' || s[i] == '{' || s[i] == '['){
        struct Node* currentValue = malloc(sizeof(struct Node));
        currentValue->value = s[i];    
        currentValue->next = stack->top;
        stack->top = currentValue; 
    } else if(s[i] == ')' || s[i] == '}' || s[i] == ']' ){
      if(stack->top == NULL){
        return false;
      }else if(s[i] == ')' && stack->top->value == '('){
        pop(stack);
      } else if(s[i] == ']' && stack->top->value == '['){
        pop(stack);
      } else if(s[i] == '}' && stack->top->value == '{'){
        pop(stack);
      } else{
        return false;
      }
    } 
    i++;
  }
  if(stack->top == NULL){
    free(stack);
    return true;
  }
  return false;
}





void main(){
    
  char* txt = "((";
  isValid(txt);

}

