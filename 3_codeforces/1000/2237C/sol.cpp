#include <stdio.h>
#include <stdlib.h>
#include <bits/stdc++.h>
using namespace std;

long long arr[200005];

void sol(int length){
    long long arrBuffer = 0;
    for(int i = 0; i < length-1; i++){
        if(arr[i] > arr[i+1]){
            arrBuffer = arr[i+1];
            arr[i+1] += arr[i];
            arr[i] = arrBuffer;   
        }
    }
    printf("%lld\n", arr[length-1]);
}





int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        for(int i = 0; i < n; i++) cin >> arr[i];
        
        sol(n);
    }
    return 0;
}