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
        
        if (k >= n){
            printf("%d\n", n);
            continue;
        }

        while(n > 0){

            if ((n - (k * a)) >= 0){
                n -= (k * a);
                count += k;
            } else{
                for (int i = 0; i < k; i++){
                    if (n >= a){
                        n -= a;
                    } else {
                        n = 0;
                        break;
                    }
                    count++;
                }
            }
            a = a * 2;
        }
        printf("%d\n", count);
        continue;
    }
}



