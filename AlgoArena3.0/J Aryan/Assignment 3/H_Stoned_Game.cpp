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
        vector<int> a(n);
        int sum = 0;
        for(int i=0;i<n;i++){
            cin>>a[i];
            sum += a[i];
        }
        sort(a.rbegin(),a.rend());
        if(a[0]>sum/2 || sum%2==1) cout<<"T"<<'\n';
        else cout<<"HL"<<'\n';
    }
}
