

struct ListNode* reverseBetween(struct ListNode* head, int left, int right) {


  if (left == 1){
      
    struct ListNode* last = head;
    struct ListNode* beforeLast = head;

    int jumps = 0;
    for(int i = 1; i < (right-1); i++){
      beforeLast = beforeLast->next;
      last = last->next;
      jumps++;
    }
    last = last->next;



    struct ListNode* dondeApuntabaElprimeroAlInicio = head->next;
    

    if(jumps != 0){
      beforeLast->next = head;
      head->next = last->next;

      head = last;
      last->next = dondeApuntabaElprimeroAlInicio;
    } else if(jumps == 0 && left != right){

      struct ListNode* headBuffer = head;
      struct ListNode* aDondeApuntabaElUltimo = last->next;

      head = last;
      last->next = headBuffer;
      headBuffer->next = aDondeApuntabaElUltimo;
      
      
    }

    struct ListNode* cero = head;

    left++;
    right--;
  }

  int numberOfElementsInTheInterval = right - (left-1);
  int numberOfSwitchesToDo = numberOfElementsInTheInterval/2;
  struct ListNode* actual;
  struct ListNode* prevIzq = NULL;
    
  if (left == 1){
    actual = head;
    prevIzq = NULL;

  } else{

    prevIzq = head;
    
    for (int i = 1; i < left-1; i++){
      prevIzq = prevIzq->next;
    }

    actual = prevIzq->next;
  }

  int headUsado = 0;
  for (int i = 0; i < numberOfSwitchesToDo; i++){

    struct ListNode* futureRightToSwap = actual;
    struct ListNode* futurePrevRightToModifyItsNext = actual;
  
    int jumps = (right-left)-1;
    
    for (int j = 0; j < jumps; j++){
      futureRightToSwap = futureRightToSwap->next;
      futurePrevRightToModifyItsNext = futurePrevRightToModifyItsNext->next;      
    }
    futureRightToSwap = futureRightToSwap->next;

    struct ListNode* prevIzqBuffer = prevIzq->next;
    struct ListNode* izqBuffer = actual->next;

    if(jumps == 0){
      prevIzq->next = actual->next;
      actual->next = futureRightToSwap->next; 
      futureRightToSwap->next = actual;
    } else{
        prevIzq->next = futurePrevRightToModifyItsNext->next;
        actual->next = futureRightToSwap->next;
        futurePrevRightToModifyItsNext->next = prevIzqBuffer;
        futureRightToSwap->next = izqBuffer;
    }

    prevIzq = futureRightToSwap;
    actual = izqBuffer;
    left+=1;
    right-=1;

  
  }
  
  
  struct ListNode* cero = head;
  while (cero->next != NULL){
    printf("valor: %d\n", cero->val);
    cero = cero->next;  
  }
  printf("valor: %d\n", cero->val);

    return head;

}


