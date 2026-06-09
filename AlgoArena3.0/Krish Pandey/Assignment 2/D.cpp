#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

#define INF LLONG_MAX
#define NINF LLONG_MIN
#define vi vector<int> 
#define vll vector<long long>

#define ll long long
void solve(vector<ll>& fact)
{
    ll n;
    int m;
    cin>>n>>m;
    vi digits;
    int ct=0;
    while(n>0)
    {
        digits.push_back(n%10);
        n/=10;
        ct++;
    }
    ll val=(1<<ct);
    vector<vector<ll>> dp(val,vector<ll>(m,0));
    dp[0][0]=1;
    for(int mask=1;mask<val;mask++)
    {
        for(int i=0;i<ct;i++)
        {
            if(mask & (1<<i))
            {
                int prev_mask=mask^(1<<i);
                if(prev_mask==0 && digits[i]==0)
                continue;
                for(int S=0;S<m;S++)
                {
                    int d=digits[i];
                    if(dp[prev_mask][S]>0)
                    dp[mask][(10*S+digits[i])%m]+=dp[prev_mask][S];
                }
            }
        }
    }
    map<int,int> freq;
    for(int x:digits)
        freq[x]++;

    ll ans=dp[val-1][0];
    for(auto x:freq)
        ans=ans/fact[x.second];
    cout<<ans<<endl;
}

int32_t main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t=1;
    vll factorial(20);
    factorial[0]=1;
    for(int i=1;i<=19;i++)
    factorial[i]=i*factorial[i-1];
    //cin>>t;
    while(t--){
        solve(factorial);
    }
    return 0;
}