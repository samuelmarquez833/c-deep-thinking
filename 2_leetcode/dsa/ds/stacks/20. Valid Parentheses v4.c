
/*
en ves de usar stack con linked lists la uso con un array
es mejor para la ocasion
que puedo decir? 
me gusta hacerlo de varias formas
*/


bool isValid(char* s) {

  char stack[strlen(s)];

  int i = 0;

  int inserccion = 0;
  int seleccionarElUltimoIDX = -1;
  while(s[i] != '\0'){


    if(s[i] == '(' || s[i] == '{' || s[i] == '['){
        stack[inserccion] = s[i];
        inserccion++;
        seleccionarElUltimoIDX++;

    } else if(s[i] == ')' || s[i] == '}' || s[i] == ']'){


      if(inserccion == 0){
        return false;
      }

      int caracterDeCierre = s[i];
      int caracterDeInicio = stack[seleccionarElUltimoIDX];


      
      int diferencia = caracterDeCierre - caracterDeInicio;

    
      if (diferencia <= 2 && diferencia >= 1 ){
        inserccion-=1;
        seleccionarElUltimoIDX-=1;
      }else{
        return false;
      }
    } 
    i++;
  }
  if(inserccion == 0){
    return true;
  }
  return false;
}
