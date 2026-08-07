#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin>>n;
    vector<int> a(n);
    for(int &x : a) cin>>x;
    vector<vector<int>> dp(n,vector<int> (n,1000));

    for(int i=0;i<n;i++) dp[i][i] = 1;
    for(int i=0;i<n-1;i++) dp[i][i+1] = a[i]==a[i+1] ? 1 : 2 ;

    for(int len=3;len<=n;len++){
        for(int i=0;i<=n-len;i++){
            int j = i + len -1;
            if(a[i]==a[j]) dp[i][j] = min(dp[i][j],dp[i+1][j-1]);
            for(int k=i;k<j;k++) dp[i][j] = min(dp[i][j],dp[i][k]+dp[k+1][j]);
        }
    }
    cout<<dp[0][n-1]<<'\n';
}
