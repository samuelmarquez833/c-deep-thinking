#include <stdio.h>

void sol(char *username, int length){


    int count[123] = {};


    int i = 0;
    while (i < length){
        int letterInIdx = username[i]; 
        count[letterInIdx]++;
        i++;
    }



    i = 97;
    int nOfcharacters = 0;

    while (i <= 122){
        if (count[i] != 0){
            nOfcharacters++;
        }
        i++;
    }
    
    
    if(nOfcharacters % 2 == 0){
        printf("CHAT WITH HER!\n");
    } else {
        printf("IGNORE HIM!\n");
    }

    

}



void main (){
    int length = 7;
    char string[] = {'s','e','v','e','n','k','p','l','u','s'};

    sol(string, length);

    /*
    'w','j','m','z','b','m','r'
    'x','i','a','o','d','a','o'
    's','e','v','e','n','k','p','l','u','s'

    */
}




