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
        string a,b; cin>>a>>b;
        int c1=0,c2=0;
        for(int i=0;i<n;i++){
            if(a[i]!=b[i]){
                c1++;
            }
        }
        reverse(a.begin(),a.end());
        for(int i=0;i<n;i++){
            if(a[i]!=b[i]){
                c2++;
            }
        }
        int ans = INT_MAX;
        int h = 2*c1 + (c1%2==1 ? -1 : 0);
        ans = min(ans,max(h,0));
        int g = c2%2==1 ? 2*c2 : 2*c2-1;
        ans = min(ans,max(g,2));
        cout<<ans<<'\n';
    }
}
