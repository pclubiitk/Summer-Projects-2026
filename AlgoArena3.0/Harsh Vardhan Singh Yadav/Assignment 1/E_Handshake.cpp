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

// ─── Solve ────────────────────────────────────────────────
void solve() {
    int n,m;
    cin>>n>>m;
    vi v(n),pf(n+1);
    
    
    for(int &a:v){cin>>a;
        
    }
    sort(v.begin(),v.end());

    for(int i =1;i<=n;i++){
        pf[i]=pf[i-1]+v[i-1];
    }
    
    int lo = 2,hi=v[n-1]*2,mid;
    
    auto cntp = [&](int x) -> int{
        int cnt=0;
        for(int i = 0 ; i<n;i++){
            int need=x-v[i];
            cnt+=n-(lower_bound(v.begin(),v.end(),need)-v.begin());
        }
        return cnt;
    };

    int ans=2;
    while(lo<=hi){
        mid=lo+(hi-lo)/2;
        if(cntp(mid)>=m){
            ans=mid;
            lo=mid+1;
        }
        else{
            hi=mid-1;
        }

    }
    int finalans=0,cnt=0;
    for(int i = 0 ; i < n;i++){
        int need = ans + 1 - v[i];
        int pos =lower_bound(v.begin(),v.end(),need)- v.begin();
         cnt+=n-pos;
         finalans+=pf[n]-pf[pos]+(n-pos)*v[i];

    }
    cout<<finalans+ans*(m-cnt);

    

}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

        solve();
    

    return 0;
}