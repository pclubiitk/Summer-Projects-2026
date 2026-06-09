#include "bits/stdc++.h"
using namespace std;
#define int long long

void solve() {
    int n;
    cin>>n;
    vector<int> fa(100001,0);
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        fa[a]++;
    }
    vector<int> dp(100001);
    dp[0]=0;
    dp[1]=fa[1];
    for(int i=2;i<100001;i++){
        dp[i]=max(dp[i-1],dp[i-2]+fa[i]*i);
    }
    cout<<dp[100000];

}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    
   
        solve();
    

    return 0;
}