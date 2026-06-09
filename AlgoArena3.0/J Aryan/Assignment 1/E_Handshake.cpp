#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    ll m; cin>>n>>m;
    vector<ll> a(n);
    ll sum = 0;

    for(ll &x : a) cin>>x;
    sort(a.begin(),a.end());
    vector<ll> prefix(n+1,0);
    for(int i=0;i<n;i++) prefix[i+1] = prefix[i] + a[i];
    ll st=1,end=2e5 + 1;
    ll best = 1;
    while(st<=end){
        ll mid = st + (end-st)/2;
        ll c=0;
        for(int i=0;i<n;i++){
            auto it = lower_bound(a.begin(),a.end(),mid-a[i]);
            c += a.end() - it;
        }
        if(c>=m){
            best = mid;
            st = mid+1;
        }
        else end = mid-1;
    }
    ll tc=0;
    for(int i=0;i<n;i++){
        auto it = lower_bound(a.begin(),a.end(),best-a[i]);
        ll k  = a.end() - it;
        tc += k;
        sum += k*a[i] + prefix[n] - prefix[it-a.begin()];
    }
    cout<<sum - (tc-m)*best;
}
