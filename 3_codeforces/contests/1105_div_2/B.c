#include <stdio.h>

long long fastPowerOut(long long exp){
    long long out = 1;
    long long base = 2;
    while (exp > 0){
        if (exp % 2 == 0){
            exp = exp / 2;
            base = base * base;
            base = base % 998244353;
        } else {
            exp--;
            out = out * base;
            out = out % 998244353;
        }
    }
    return out;
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        long long n, m, r, c;
        scanf("%lld %lld %lld %lld", &n, &m, &r, &c);

        long long rows = n - r + 1;
        long long columns = m - c + 1;
        long long totalCells = n * m;
        long long matrices = rows * columns;
        long long freeElements = totalCells - matrices;

        printf("%lld\n", fastPowerOut(freeElements));
    }
    return 0;
}