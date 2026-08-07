// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
	ll t;
    cin>>t;
    while(t--){
       ll d,k;
       cin>>d>>k;
       ll a;
       a=d/(pow(2,0.5));
    //    cout<<a<<" ";
       a/=k;
       a*=k;
        // cout<<a<<" ";
       if((a+k)*(a+k)+a*a>d*d) cout<<"Utkarsh"<<endl;
       else cout<<"Ashish"<<endl;

        

    }
}
