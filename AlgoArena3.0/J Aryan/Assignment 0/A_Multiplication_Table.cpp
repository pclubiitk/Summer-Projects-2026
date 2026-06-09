#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
ll count(ll mid, ll n , ll m){
    ll c=0;
    for(ll i=1;i<=n;i++) c += min(m,mid/i);
    return c;
}
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n,m,k; cin>>n>>m>>k;
    ll l=1,r=n*m,ans=r;
 
    while(l<=r){
        ll mid = l + (r-l)/2;
        if(count(mid,n,m)>=k){
            ans = mid;
            r = mid-1;
        }
        else l = mid +1;
    }
    cout<<ans<<'\n';
}
