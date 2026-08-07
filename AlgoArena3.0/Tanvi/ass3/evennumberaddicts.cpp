#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
  int t;
  cin>>t;
  while(t--){
    ll n;
    cin>>n;
    ll ar[n];
    for(int i=0; i<n; i++) cin>>ar[i];
    int od=0,ev=0;
    for(int i=0; i<n; i++){
        if(ar[i]%2==0) ev++;
        else od++;
    }
    if((od%4==1 && ev%2==0) || od%4==2) cout<<"Bob"<<endl;
    else cout<<"Alice"<<endl;
  }
}