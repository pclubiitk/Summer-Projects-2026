#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin>>t;
    while(t--){
        ll n,k; cin>>n>>k;
        if(k%3==0) n = n % (k+1);
        if(n==k) cout<<"Alice"<<'\n';
        else cout<< (n%3!=0 ? "Alice" : "Bob") << '\n';
    }
}
