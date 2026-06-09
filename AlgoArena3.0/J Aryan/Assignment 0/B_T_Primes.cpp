#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int s = 1e6;
    vector<int> v(s+1,0);
    v[0]=1;v[1]=1;
    for(int i=2;i*i<=s;i++){
        if(v[i]==0){
            for(int j=i*i;j<=s;j +=i) v[j]=1;
        }
    }
    int n;cin>>n;
    vector<ll> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
        ll k = llround(sqrt(a[i]));
        if(k*k==a[i] && v[k]==0) cout<<"YES"<<'\n';
        else cout<<"NO"<<'\n';
    }
 
}
