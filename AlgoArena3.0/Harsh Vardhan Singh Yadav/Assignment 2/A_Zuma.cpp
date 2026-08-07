#include "bits/stdc++.h"
using namespace std;
#define int long long
#define vi vector<int>
#define vvi vector<vector<int>>
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
#define ff first
#define ss second
typedef pair<int,int> pii;
typedef vector<pii> vpii;

const int MOD = 1e9 + 7;
const int INF = 1e18;
const int NEG_INF = -1e18;

void solve() {
   int n;
   cin>>n;
   vi v(n+1);
   for(int i=1;i<=n;i++)cin>>v[i];
   vvi dp(n+1,vi(n+1,INF));
   //dp[i][j]= minimum no. of seconds to remove v[i] to v[j];
   for(int i = 1 ; i<=n;i++){
    dp[i][i]=1;
   }
   for(int i = 1;i<n;i++){
    dp[i][i+1]=(v[i]!=v[i+1])+1;
   }
    for(int len=3 ; len<=n;len++){
      for(int i = 1;i<=n-len+1;i++){
        int j = i+len-1;
        
        if(v[i]==v[j]){
            
            dp[i][j]=min(dp[i][j],dp[i+1][j-1]);
        }
        for(int k = i; k < j; k++) {
        dp[i][j] = min(dp[i][j], dp[i][k] + dp[k+1][j]);    
        }       
    }
   }
   cout<<dp[1][n];
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

        solve();
    

    return 0;
}