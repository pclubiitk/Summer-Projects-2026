#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m; cin>>n>>m;
    vector<vector<int>> a(n,vector<int> (m));
    vector<vector<int>> dp1(n+2,vector<int> (m+2,0));
    vector<vector<int>> dp2 = dp1, dp3 = dp1, dp4 = dp1;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++) cin>>a[i][j];
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++) dp1[i][j] = a[i-1][j-1] + max(dp1[i-1][j],dp1[i][j-1]);
    }
    for(int i=n;i>=1;i--){
        for(int j=m;j>=1;j--) dp2[i][j] = a[i-1][j-1] + max(dp2[i+1][j],dp2[i][j+1]);
    }
    for(int i=n;i>=1;i--){
        for(int j=1;j<=m;j++) dp3[i][j] = a[i-1][j-1] + max(dp3[i+1][j],dp3[i][j-1]);
    }
    for(int i=1;i<=n;i++){
        for(int j=m;j>=1;j--) dp4[i][j] = a[i-1][j-1] + max(dp4[i-1][j],dp4[i][j+1]);
    }
    ll best = 0;
    for(int i=2;i<n;i++){
        for(int j=2;j<m;j++){
            ll c1 = 1LL*dp1[i-1][j] + dp2[i+1][j] + dp3[i][j-1] + dp4[i][j+1];
            ll c2 = 1LL*dp1[i][j-1] + dp2[i][j+1] + dp3[i+1][j] + dp4[i-1][j];
            best = max(best,max(c1,c2));
        }
    }
    cout<<best;
}
