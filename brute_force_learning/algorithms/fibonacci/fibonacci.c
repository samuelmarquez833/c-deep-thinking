/*
o sea yo pense
a ver, vamos a buscar una forma de modo 
que pueda calcular el 0 y el 1 iniciales 
pero aparentemente no se puede

luego
a ver una fomr asin arrays
creo que no se puede

espera, se peude con recursividad
como?

wow
vine yo solo con una forma que basicamente se trata de que como un loop recursivo o unamierda asi
no se

hay una forma de recursividad matematica, pero me la pela

*/






























// Solucion sin recursion lo mas sencilla posible
/*
int main(){

    int fibonacci[100];
    fibonacci[0] = 0;
    fibonacci[1] = 1;
    for (int i = 2; i < 100; i++){
        fibonacci[i] = fibonacci[i-1] + fibonacci[i-2];
    }

    for (int i = 0; i < 100; i++){
        printf("%d\n", fibonacci[i]);
    }

    return 0;
}
*/



























// solucion con recursión de cola (tail recursion) que sustituye a un loop.
/*
#include <stdio.h>

void fib(int elemento, int* arr, int indice, int limite){
    
    
    if (indice == limite){
        printf("llegamos al limite");
    } else if(elemento == 0){        
        arr[indice] = elemento;
        indice++;
        for(int i = 0; i < indice; i++){
           printf("ok, indice vale %d y lo que hay en el arr es: %d \n", i, arr[i]);
        }
        fib(1, arr, indice, limite);
    } else if (elemento == 1 && indice == 1){
        arr[indice] = elemento;
        indice++;
        for(int i = 0; i < indice; i++){
           printf("ok, indice vale %d y lo que hay en el arr es: %d \n", i, arr[i]);
        }
        fib(elemento, arr, indice, limite);
    } else if (indice > 1){
        int numero = arr[indice-1] + arr[indice-2];
        arr[indice] = numero;
        indice++;
        for(int i = 0; i < indice; i++){
           printf("ok, indice vale %d y lo que hay en el arr es: %d \n", i, arr[i]);
        }
        fib(numero, arr, indice, limite);
    }
}


int main(){
    int largo = 20;
    int arr[largo];
    fib(0, arr, 0, largo);
    return 0;
}
*/




















// mi codigo medio refactorizado
/*
#include <stdio.h>

void fib(int* arr, int indice, int limite){
    
    
    if (indice == limite){
        printf("llegamos al limite");
    } else if(indice == 0){        
        arr[indice] = 0;
        indice++;
        for(int i = 0; i < indice; i++){
           printf("ok, indice vale %d y lo que hay en el arr es: %d \n", i, arr[i]);
        }
        fib(arr, indice, limite);
    } else if (indice == 1){
        arr[indice] = 1;
        indice++;
        for(int i = 0; i < indice; i++){
           printf("ok, indice vale %d y lo que hay en el arr es: %d \n", i, arr[i]);
        }
        fib(arr, indice, limite);
    } else if (indice > 1){
        int numero = arr[indice-1] + arr[indice-2];
        arr[indice] = numero;
        indice++;
        for(int i = 0; i < indice; i++){
           printf("ok, indice vale %d y lo que hay en el arr es: %d \n", i, arr[i]);
        }
        fib(arr, indice, limite);
    }
}


int main(){
    int largo = 20;
    int arr[largo];
    fib(arr, 0, largo);
    return 0;
}
*/














/*
Habian varios casos los cuales, tienes que tener cuidado, no por que te halla fallado la logica al crear la solucion
solo pq no pensaste en esa situacion o input al crear la solucion
que pasaba si limite era igual a 0 o a 1? 
respuesta
solo creamos un camino para cuando es igual a 0
y para cuando es igual a 1
la logica se quedaba igual (me puse a imaginar en mas caminos complique y rompi todo)
*/
/*#include <stdio.h>

void fib(int* arr, int indice, int limite){
    
    if(limite == 0){
        printf("No hay espacio para llenar");
        return;
    } else if (indice == limite){
        printf("llegamos al limite");  
        return;      
    } else if(indice == 0){        
        arr[indice] = 0;
        indice++;
        for(int i = 0; i < indice; i++){
           printf("ok, indice vale %d y lo que hay en el arr es: %d \n", i, arr[i]);
        }
        fib(arr, indice, limite);
    } else if (indice == 1){
        arr[indice] = 1;
        indice++;
        for(int i = 0; i < indice; i++){
           printf("ok, indice vale %d y lo que hay en el arr es: %d \n", i, arr[i]);
        }
        fib(arr, indice, limite);
    } else if (indice > 1){
        int numero = arr[indice-1] + arr[indice-2];
        arr[indice] = numero;
        indice++;
        for(int i = 0; i < indice; i++){
           printf("ok, indice vale %d y lo que hay en el arr es: %d \n", i, arr[i]);
        }
        fib(arr, indice, limite);
    }
}


// el indice siempre va a ser 0
int main(){
    int largo = 20;
    int arr[largo];
    fib(arr, 0, largo);
    return 0;
}
*/









/*
Codigo bien refactorizado 
(bueno)
mejor simplemente, mas lindo
pero con la misma logica de antes y con las mismas condicones de no ponerlo afuera o otra fucion etc...
*/


#include <stdio.h>

void fib(int* arr, int indice, int limite){
    


    if(limite == 0){
        return;
    } else if (limite == 1){
        arr[0] = 0;
        indice++;
        for(int i = 0; i < indice; i++){
           printf("ok, indice vale %d y lo que hay en el arr es: %d \n", i, arr[i]);
        }
        return;
    } else if (indice == limite){
        printf("llegamos al limite");  
        return;      
    // en caso de que ala chingada el limite sea mayor de 1, entonces, puede ejecutar los sigueintes ifs sin problema por ene se incializa en seco y ya
    } else if (indice < 2){
        arr[indice] = indice;
        indice++;
        if (indice == limite){
            for(int i = 0; i < indice; i++){
                printf("ok, indice vale %d y lo que hay en el arr es: %d \n", i, arr[i]);
            }
        }
        fib(arr, indice, limite);
    } else if (indice > 1){
        int numero = arr[indice-1] + arr[indice-2];
        arr[indice] = numero;
        indice++;
        if (indice == limite){
            for(int i = 0; i < indice; i++){
                printf("ok, indice vale %d y lo que hay en el arr es: %d \n", i, arr[i]);
            }
        }
        fib(arr, indice, limite);
    }
}


// el indice siempre va a ser 0
int main(){
    int largo = 4;
    int arr[largo];
    fib(arr, 0, largo);

    return 0;
}


/*
igual podrias  hacer una fucion aparte para incializar el array de fibonacci
o podrias inicializarlo en main, hay un huevo de caminos, solo agarre los dificiles, resbuscados etc
si lo quieres imprimir despues, ya imprimelo luego en el main, no se, realemnte no inmporta
*/

