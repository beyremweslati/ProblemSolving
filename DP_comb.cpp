#include <bits/stdc++.h>
using namespace std;
const int N = 10e4;
const int K = 100;
int dp[N][K];

int comb(int n, int k){
    if(dp[n][k] != -1)
        return dp[n][k];
    if(k == 0)
        dp[n][k] = 1;
    else{
        if(n == 0)
            dp[n][k] = 0;
        else
            dp[n][k] = comb(n-1, k) + comb(n-1 , k-1);
    }
    return dp[n][k];
}

int main(){
    memset(dp,-1,sizeof dp);
    cout << comb(3,2) << endl;
    return 0;
}