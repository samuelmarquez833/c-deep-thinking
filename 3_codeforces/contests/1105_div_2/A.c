#include <stdio.h>
#include <math.h>

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        int n, k;
        scanf("%d %d", &n, &k);
        int count = 0;
        int a = 1;
        while(n > 0){
            for (int i = 0; i < k; i++){
                if (n >= a){
                    n -= a;
                } else {
                    break
                    
                }
                count++;
            }
            a = a * 2;
        }
        return count;
    }
}



