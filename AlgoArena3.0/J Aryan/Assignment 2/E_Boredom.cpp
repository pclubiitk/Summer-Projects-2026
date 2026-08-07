#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin>>n;
    vector<int> a(n),freq(1e5+3,0);
    int N = 1;
    for(int &x : a){
        cin>>x; freq[x]++;
        N = max(N,x);
    }
    vector<ll> dp(N+1,0);
    dp[1] = freq[1];
    for(int i=2;i<=N;i++) dp[i] = max(dp[i-1],dp[i-2]+freq[i]*1LL*i);
    cout<<dp[N]<<'\n';
}
