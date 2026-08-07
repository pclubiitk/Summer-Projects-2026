#include <bits/stdc++.h>
using namespace std;

#define ll long long
int digits(ll n){
    int t=0;
    while(n>0){
        n/=10;
        t++;
    }
    return t;
}
int zero(ll t){
    int k=0;
    for(int i=1; i<=9; i++){
        if(t%(ll)pow(10,i)==0) k++;
    }
    return k;
}
int main() {
    int t;
    cin>>t;
   
    while(t--){
        ll n,m;
        cin>>n>>m;
        ll ar[n];
        ll sum=0,minu=0;
        for(int i=0; i<n; i++) cin>>ar[i];
         for(int i=0; i<n; i++) sum+=digits(ar[i]);
         vector<int> v;
        for(int i=0; i<n; i++){
            if(zero(ar[i])>=1) v.push_back(zero(ar[i]));
        }
        sort(v.rbegin(),v.rend());
        for(int i=0; i<v.size(); i+=2)minu+=v[i];
       if(sum-minu>m) cout<<"Sasha"<<endl;
       else cout<<"Anna"<<endl;
    }
     
}