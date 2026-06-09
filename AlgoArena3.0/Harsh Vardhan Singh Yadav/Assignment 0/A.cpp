#include "bits/stdc++.h"
using namespace std;
#define int long long
#define vi vector<int>
#define vvi vector<vector<int>>

void solve() {
    int n,m,k;
    cin>>n>>m>>k;
    int lo=1,hi=n*m,mid,ans;
    while(lo<=hi){
        mid=lo+(hi-lo)/2;
        int count=0;
        for(int i = 1 ;i<=n;i++){
            count+=min(m,mid/i);
        }
        if(count>=k){
            ans=mid;
            hi=mid-1; 
        }
        else{
            lo=mid+1;
        }
    }
    cout<<ans;
}


signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

   
        solve();
    

    return 0;
}