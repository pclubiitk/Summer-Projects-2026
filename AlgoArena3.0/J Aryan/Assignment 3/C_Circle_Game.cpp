#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
//hakuna matata
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t=1; cin>>t;
    while(t--){
        ll d,k; cin>>d>>k;
        ll tr = 0;
        ll s = 0, e = d;
        while(s<=e){
            ll mid = s + (e-s)/2;
            if(mid*mid*2<=d*d){
                tr = mid;
                s = mid + 1;
            }
            else e = mid - 1;
        }
        ll a = tr/k*k + k, b = tr/k*k;
        if(a*a + b*b <=d*d) cout<<"Ashish"<<'\n';
        else cout<<"Utkarsh"<<'\n';
    }
}
