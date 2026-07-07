#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
//hakuna matata
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t=1; cin>>t;
    while(t--){
        int h,w,xa,ya,xb,yb; cin>>h>>w>>ya>>xa>>yb>>xb;
        int h1 = (abs(ya-yb)+1);
        if(yb<=ya) cout<<"Draw"<<'\n';
        else if(h1%2==0){
            if(abs(xa-xb)<=1) cout<<"Alice"<<'\n';
            else{
                if((xb>xa && xa+h1/2>=w) || (xb<xa && xa-h1/2<=1)) cout<<"Alice"<<'\n';
                else cout<<"Draw"<<'\n';
            }
        }
        else{
            if(xa==xb) cout<<"Bob"<<'\n';
            else{
                if((xa>xb && xb+h1/2>=w) || (xa<xb && xb-h1/2<=1)) cout<<"Bob"<<'\n';
                else cout<<"Draw"<<'\n';
            }
        }
    }
}
