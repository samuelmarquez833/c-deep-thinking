
/*

ahora toma mas tiempo run time peor la verdad es que
asi ya se limpia la memoria
es buen codigo
es mas sano

(hay mejores frees)

*/


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
      int caracterDeCierre = s[i];
      if(stack->top == NULL){
        while(stack->top != NULL){
            pop(stack);
        }

        free(stack);
        return false;
      }
      int caracterDeInicio = stack->top->value;
      int diferencia = caracterDeCierre - caracterDeInicio;
      if (diferencia <= 2 && diferencia >= 1 ){
        pop(stack);
      }else{
        while(stack->top != NULL){
            pop(stack);
        }

        free(stack);
        return false;
      }
    } 
    i++;
  }
  if(stack->top == NULL){
    free(stack);
    return true;
  }
  while(stack->top != NULL){
      pop(stack);
  }

  free(stack);
  return false;
}