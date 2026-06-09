#include "bits/stdc++.h"
using namespace std;
#define int long long
#define vi vector<int>
#define vvi vector<vector<int>>

void solve() {
     int n;
     cin>>n;
     vi v(n),v2(n);
     int j=0;
     for(int &i:v) {cin>>i;
        v2[j]=i;
        j++;
        }
     int m;
     cin>>m;
    
     sort(v2.begin(),v2.end());
     vi pf(n+1),pfs(n+1);
     
     pf[0]=0;
     pfs[0]=0;

     for(int i = 0 ; i<n;i++){
        pf[i+1]=v[i]+pf[i];
        pfs[i+1]=v2[i]+pfs[i];
     }
     
     for(int i = 0 ;i<m;i++){
        int t,l,r;
        cin>>t>>l>>r;
        if(t==1){
            cout<<pf[r]-pf[l-1]<<"\n";
        }
        else{
            cout<<pfs[r]-pfs[l-1]<<"\n";
        }
     }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    
        solve();
    

    return 0;
}