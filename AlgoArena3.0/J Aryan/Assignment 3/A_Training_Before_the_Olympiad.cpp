#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t=1; cin>>t;
    while(t--){
        int n; cin>>n;
        vector<ll> a(n),pre(n+1,0),odd(n+1,0);
        for(int i=0;i<n;i++){
            cin>>a[i];
            pre[i+1] = pre[i] + a[i];
            odd[i+1] = odd[i] + (a[i]%2==1 ? 1 : 0);
        }
        cout<<pre[1]<<' ';
        for(int i=2;i<=n;i++){
            pre[i] -= odd[i]/3;
            pre[i] -= (odd[i]%3==1 ? 1 : 0);
            cout<<pre[i]<<' ';
        }
        cout<<'\n';
    }
}
