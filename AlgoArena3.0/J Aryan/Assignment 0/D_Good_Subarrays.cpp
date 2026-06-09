#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        vector<int> a(n),pf(n+1,0);
        map<int,int> m;
        m[0]=1;
        for(int i=0;i<n;i++){
            char c; cin>>c;
            a[i] = c- '0' - 1;
        }
        for(int i=1;i<=n;i++){
            pf[i] = pf[i-1] + a[i-1];
            m[pf[i]]++; 
        }
        ll ans=0;
        for(auto p : m){
            if(p.second>1) ans += (ll)p.second*(p.second-1)/2;
        }
        cout<<ans<<'\n';
    }
}
