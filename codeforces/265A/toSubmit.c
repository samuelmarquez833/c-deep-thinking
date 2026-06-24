#include <stdio.h>

int main() {

    char username[200];
    scanf("%s", username);
    int length = strlen(username);

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


    return 0;
}




