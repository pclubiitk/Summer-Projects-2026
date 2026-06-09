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

int nf(int n,int x){
    int ans=0;
    while(n!=0 && n%x==0){
        n/=x;
        ans++;
    }
    return ans;
}
// ─── Solve ────────────────────────────────────────────────
void solve() {
    int n,k;cin>>n>>k;
    vvi v;
    // total 5;
    int c5=0;
    for(int i = 0 ; i<n;i++){
        int a;
        cin>>a;
        int b=nf(a,2),c=nf(a,5);
        c5+=c;
        
            v.push_back({a,b,c});
        
    }
    
    vvi dp2(k+1,vi(c5+1,-1));
    dp2[0][0]=0;
    for(int i = 1 ; i<=n;i++){
        for(int j = k;j>=0;j--){
            for(int p = c5 ; p>=0;p--){
                if(p-v[i-1][2]>=0 && j-1>=0 && dp2[j-1][p-v[i-1][2]]!=-1)
                {dp2[j][p]=max(dp2[j][p],dp2[j-1][p-v[i-1][2]]+v[i-1][1]);}
                
            }
        }
    }
    
       
    
    int ans = 0;
for(int p = 0; p <= c5; p++)
    ans = max(ans, min(p, dp2[k][p]));
cout << ans;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    // int t;
    // cin >> t;
    // while (t--) {
        solve();
    

    return 0;
}