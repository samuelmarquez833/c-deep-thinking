#include <cstdio>
#include <cmath>

long long int nextPrime(long long int  candidate){
    
    candidate++;
    
    int state = 0;
    int miniState = 0;

    double copiaEnDouble = 0;

    while (state == 0){
        copiaEnDouble = candidate;
        for(int i = 2; i <= sqrt(copiaEnDouble); i++){
            if(candidate % i == 0){
                //no olvidar: es primo
                miniState = 1;
                continue;
            }
        }
        if(miniState == 0){
            state = 1;
        } else{
            candidate++;
        }
        miniState = 0;
    }

    return candidate;
}



void func(int n){

    long long int first = 1;
    long long int second = 2;
    long long int num = 0;
    while(n > 0){

        num = first*second;
        printf("%lld ", num);
        first = second;
        n--;    

        second = nextPrime(second);
    }
    printf("\n");


}



int main (){
    
    
    int t;
    scanf("%d", &t);
    while(t--){
        int n;
        scanf("%d", &n);

        func(n);
    }

    return 0;
}
