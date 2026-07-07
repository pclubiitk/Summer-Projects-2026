#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
//hakuna matata
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t=1; cin>>t;
    while(t--){
        int n; cin>>n;
        int e=0,o=0;
        vector<int> v(n);
        for(int i=0;i<n;i++){
            cin>>v[i];
            v[i] = abs(v[i]);
            if(v[i]%2==0) e++;
            else o++;
        }
        if(o%4==0 || o%4==3 || (o%4==1 && e%2==1)) cout<<"Alice"<<'\n';
        else cout<<"Bob"<<'\n';
    }
}
