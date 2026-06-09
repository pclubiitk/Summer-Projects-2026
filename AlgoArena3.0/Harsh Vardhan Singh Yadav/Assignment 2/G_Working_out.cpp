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
    int n,m;

    cin>>n>>m;
    
    vvi v(n+2,vi (m+2,0));

    for(int i = 1 ; i<=n;i++){
        for(int j = 1 ;j<=m;j++){
            cin>>v[i][j];
        }
    }
    vvi dp1(n+2,vi(m+2,0)),dp2(n+2,vi(m+2,0)),dp3(n+2,vi(m+2,0)),dp4(n+2,vi(m+2,0));
    for(int i = 1;i<=n;i++){
        for(int j =1;j<=m;j++){
            dp1[i][j]=max(dp1[i-1][j],dp1[i][j-1])+v[i][j];
        }
    }
    for(int i = n;i>=1;i--){
        for(int j =1;j<=m;j++){
            dp2[i][j]=max(dp2[i+1][j],dp2[i][j-1])+v[i][j];
        }
    }
    for(int i = 1;i<=n;i++){
        for(int j =m;j>=1;j--){
            dp3[i][j]=max(dp3[i-1][j],dp3[i][j+1])+v[i][j];
        }
    }
    for(int i = n;i>=1;i--){
        for(int j =m;j>=1;j--){
            dp4[i][j]=max(dp4[i+1][j],dp4[i][j+1])+v[i][j];
        }
    }
    
    int ans=0,ans1,ans2;
    for(int i = 2 ; i<n;i++){
        for(int j =2;j<m;j++){
            ans1=dp1[i][j-1]+dp2[i+1][j]+dp3[i-1][j]+dp4[i][j+1];
            ans2=dp2[i][j-1]+dp1[i-1][j]+dp3[i][j+1]+dp4[i+1][j];
        
        ans=max(ans,max(ans1,ans2));
        }
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