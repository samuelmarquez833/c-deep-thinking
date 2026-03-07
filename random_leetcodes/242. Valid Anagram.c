#include <stdio.h>
#include <stdlib.h>


// mi solucion, se pasa de tiempo
/*
bool isAnagram(char* s, char* t){
    int lengthUno = 0;
    while (s[lengthUno] != '\0') lengthUno++;
    int lengthDos = 0;
    while (t[lengthDos] != '\0') lengthDos++;
    if (lengthUno != lengthDos) return false;
    for (int i = 0; i < lengthUno; i++){
        for(int j = 0; j < lengthDos; j++){
            if(s[i] == t[j]){
                s[i] = '0';
                t[j] = '0';
                break;
            }
        }
    }
    for(int i = 0; i < lengthUno; i++){
        if (s[i] != '0'){
            return false;
        }
    }
    return true;
}*/



// un mejor enfoque
bool isAnagram(char* s, char* t) {

    int lengthUno = 0;
    while (s[lengthUno] != '\0') lengthUno++;

    int lengthDos = 0;
    while (t[lengthDos] != '\0') lengthDos++;

    if (lengthUno != lengthDos) return false;

    int marks[256] = {0};

    // "marco" las letras de s
    for (int i = 0; i < lengthUno; i++) {
        marks[(unsigned char)s[i]]++;
    }

    // "desmarco" usando t
    for (int i = 0; i < lengthDos; i++) {
        marks[(unsigned char)t[i]]--;
    }

    // verifico que todo quedó tachado
    for (int i = 0; i < 256; i++) {
        if (marks[i] != 0) return false;
    }

    return true;
}


int main (){
    char s[] = "anagram";
    char t[] = "nagaram";
    bool aja = isAnagram(s, t);
    printf("es... si o no?%d", aja);
    return 0;
}
