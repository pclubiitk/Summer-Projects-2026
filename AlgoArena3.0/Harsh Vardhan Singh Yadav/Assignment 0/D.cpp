#include "bits/stdc++.h"
using namespace std;
#define int long long
#define vi vector<int>
#define vvi vector<vector<int>>

void solve() {
int n;
cin>>n;
string s;
cin>>s;
int ans=0;
vi v(n),pf(n+1);
pf[0]=0;
for(int i = 0 ; i <n;i++){
    v[i]=(s[i]-'0')-1;
    pf[i+1]=v[i]+pf[i];
}
map<int,int> mp;

for(int i = 0 ; i<=n;i++){
    mp[pf[i]]++;
}
for(auto it:mp){
   ans+=(it.second*(it.second-1))/2;
}
cout<<ans<<"\n";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin>>t;
    for(int i = 0 ; i<t;i++)
   {     
    solve();
}
    return 0;
}