#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin>>n;
    vector<int> a(n),b(n);
    vector<ll> pa(n+1,0),pb(n+1,0);
    for(int i=0;i<n;i++) cin>>a[i];
    b = a;
    sort(b.begin(),b.end());
    for(int i=1;i<=n;i++){
        pa[i] = pa[i-1] + a[i-1];
        pb[i] = pb[i-1] + b[i-1];
    }
    int m;cin>>m;
    while(m--){
        int t,l,r;cin>>t>>l>>r;
        if(t==1){
            cout<<pa[r]-pa[l-1]<<'\n';
        }
        else cout<<pb[r]-pb[l-1]<<'\n';
    }
}
