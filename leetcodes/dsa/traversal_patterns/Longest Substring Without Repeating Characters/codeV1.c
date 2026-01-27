/*
**Summary:**
You are given a string and must find the maximum length of a **contiguous substring** that contains **no repeated characters**. The key restriction is that the characters must be consecutive (a substring), not just in order (a subsequence).

**Why this is Sliding Window:**
The problem maintains a window `[left, right]` over the string where:

* the window always contains **unique characters**
* the right pointer expands the window by exploring new characters
* the left pointer shrinks the window only when a duplicate appears, restoring validity

Both pointers move forward only, ensuring an **O(n)** solution.

This makes it a canonical example of the **sliding window technique**.
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>



/*


1) largoActual está desfasado por el orden de tus ++/--

Ahorita haces:

al inicio del loop: last[idxFLetra]++

al final del loop: largoActual++ siempre

dentro del if: haces varios largoActual--

Eso puede funcionar, pero tu printf("%d\n", largoActual); no representa la longitud real de la ventana en el momento de detectar duplicado, porque largoActual todavía no incluye consistentemente el char de idxF (dependiendo del paso). Te va a dar máximos mal en casos como abcabcbb y pwwkew.

📌 Arreglo correcto sin cambiar tu enfoque: no mantengas largoActual a mano.
La longitud real siempre es:

int len = idxF - idxI + 1;


Y el máximo se actualiza después de recortar (si hubo recorte), no antes.

2) Estás actualizando largoMasGrande en el lugar incorrecto

Lo haces antes de recortar, o sea cuando la ventana está inválida (ya hay duplicado).
No quieres registrar una ventana inválida.

📌 Regla con tu esquema:

metes idxF

si duplica, recortas hasta que vuelva a ser válida

ahí calculas longitud válida y actualizas máximo

O sea, el update del máximo va después del bloque del recorte.

3) Indexación segura: necesitas unsigned char

Esto sí importa porque puede romper por UB:

last[idxFLetra]++


Si char es signed, te puede indexar negativo.

📌 Hazlo así siempre:

unsigned char c = (unsigned char)string[idxF];
last[c]++;


y lo mismo con string[idxI].


*/



int lengthOfLongestSubstring(char* string) {

    if (string[0] == '\0') return 0;

    int last[256];
    memset(last, -1, sizeof(last));

    int idxI = 0;
    char idxILetra = string[idxI];
    last[(unsigned char)idxILetra]++;

    int largoActual = 1;
    int largoMasGrande = 1;

    int idxF = idxI + 1;

    while (string[idxF] != '\0') {
        char idxFLetra = string[idxF];
        last[(unsigned char)idxFLetra]++;

        if (last[(unsigned char)idxFLetra] == 1) {

            char letraParaBuscar = string[idxF];
            while (string[idxI] != letraParaBuscar) {
                char idxILetra = string[idxI];
                last[(unsigned char)idxILetra]--;
                largoActual--;
                idxI++;
            }

            last[(unsigned char)string[idxI]]--;
            idxI++;
            largoActual--;
        }

        largoActual++;
        // pq primeor actualioz y luego comparo? creo qeu ya se la repsuesta pero lo queiro dejar cristalino
        if (largoActual > largoMasGrande) {
            largoMasGrande = largoActual;
        }

        idxF++;
    }

    printf("%d", largoMasGrande);
    return 0;
}






















int main (){
    char string[] = "dvdf";

    int output = lengthOfLongestSubstring(string);

    return 0;
}























