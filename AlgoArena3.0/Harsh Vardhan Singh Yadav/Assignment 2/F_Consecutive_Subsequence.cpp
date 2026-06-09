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


    


void solve() {
    int n;
    cin>>n;
    vi v;

    
    for(int i = 0 ; i<n;i++){
        int a;
        cin>>a;
        v.push_back(a);
    }
    int mx=-1;
    int mxval=-1;
    unordered_map<int,int> dp;
    for(int i = 0 ; i<n;i++){
        dp[v[i]]=dp[v[i]-1]+1;
        if(dp[v[i]]>mx){
            mx=dp[v[i]];
            mxval=v[i];
        }
    }
    cout<<mx<<"\n";
    
    int start=mxval-mx+1;
    for(int i=0;i<n;i++){
        if(v[i]==start){
            cout<<i+1<<" ";
            if(start==mxval){
                break;
            }
            start++;
            
        }

        };
    


}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    
        solve();
    

    return 0;
}