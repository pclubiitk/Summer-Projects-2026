#include <bits/stdc++.h>

using namespace std;

const long long MOD = 1e8;

int main(){
    int n1,n2,k1,k2;
    cin >> n1 >> n2 >> k1 >> k2;
    vector<vector<vector<int>>> dp1(n1+1,vector<vector<int>>(n2+1,vector<int>(max(n1,n2) + 1,0)));
    vector<vector<vector<int>>> dp2(n1+1,vector<vector<int>>(n2+1,vector<int>(max(n1,n2) + 1,0)));
    
    dp1[1][0][1] = 1;
    dp2[0][1][1] = 1;

    for(int i = 2; i <= n1+n2; i++){
        for(int j = 1; j <= i; j++){
            if(j <= n1 && i-j <= n2){
                for(int t = 0; t <= min(j-1, k1-1); t++){
                    dp1[j][i-j][t+1] += dp1[j-1][i-j][t]; 
                    dp1[j][i-j][t+1] %= MOD;
                }
                for(int t = 0; t <= i-j; t++){
                    dp1[j][i-j][1] += dp2[j-1][i-j][t]; 
                    dp1[j][i-j][1] %= MOD;
                }
            }
            if(j-1 <= n1 && i-j+1 <= n2){
                for(int t = 0; t <= min(i-j, k2-1); t++){
                    dp2[j-1][i-j+1][t+1] += dp2[j-1][i-j][t]; 
                    dp2[j-1][i-j+1][t+1] %= MOD;
                }
                for(int t = 0; t <= j-1; t++){
                    dp2[j-1][i-j+1][1] += dp1[j-1][i-j][t]; 
                    dp2[j-1][i-j+1][1] %= MOD;
                }
            }

        }
    }
    long long ans = 0;
    for(int i = 0; i <= max(n1,n2); i++){
        ans = (ans + dp1[n1][n2][i] + dp2[n1][n2][i]) % MOD;
    }
    cout << ans;

}
