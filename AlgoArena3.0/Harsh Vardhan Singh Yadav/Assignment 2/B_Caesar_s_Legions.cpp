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

const int MOD = 1e8 ;
const int INF = 1e18;
const int NEG_INF = -1e18;

void solve() {
    int n1,n2,k1,k2;
    cin>>n1>>n2>>k1>>k2;
    vector<vector<vvi>> dp(n1+1,vector<vvi>(n2+1,vvi(2,vi(12,0))));
    // v[i][j][k][l] means i footmen left , j horsemen left , last placed a hm or fm means 0 or 1=k, and l of them are previously there.
    
    dp[1][0][0][1]=1;
    dp[0][1][1][1]=1;
    // dp[1][1][0][1]=2;
    // dp[1][1][1][1]=2;
    for(int i = 0 ; i<=n1;i++){
        for(int j = 0 ;j<=n2;j++){
            if(i+j<=1){
                continue;
            }
            if(i>0)
            {for(int l=0;l<k1;l++){
                
                dp[i][j][0][l+1]+=dp[i-1][j][0][l];
                dp[i][j][0][l+1]%=MOD;
            }
            for(int l=0;l<=k2;l++){
                dp[i][j][0][1]+=dp[i-1][j][1][l];
                dp[i][j][0][1]%=MOD;
                
            }}
            if(j>0)
           { for(int l=0;l<k2;l++){
                dp[i][j][1][l+1]+=dp[i][j-1][1][l];
                dp[i][j][1][l+1]%=MOD;
            }
             for(int l=0;l<=k1;l++){
                dp[i][j][1][1]+=dp[i][j-1][0][l];
                dp[i][j][1][1]%=MOD;
                
            }
}
        }
    }
   int ans=0;
   for(int i =0;i<12;i++){
    ans=((ans + dp[n1][n2][0][i])%MOD+dp[n1][n2][1][i])%MOD;
   }
   cout<<ans;
    
    
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    
        solve();
    

    return 0;
}