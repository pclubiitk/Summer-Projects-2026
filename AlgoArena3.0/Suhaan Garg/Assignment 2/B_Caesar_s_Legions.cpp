#include <bits/stdc++.h>
using namespace std;
using LL = long long;
#include<vector>
#include<string>
#include<map>
#include<set>
#include<stack>
#define M 1000000007
#include<unordered_map>
using LD = long double;
#define pb  push_back
#define pll pair<LL,LL>
#define vl  vector<LL>
#define all(v) v.begin(), v.end()
#define sz(v) (LL)v.size()


LL gcd(LL a,LL b) 
{
    return b?gcd(b,a%b):a;
}
LL modpow(LL a, LL b, LL m)
{
    LL res=1;
    while(b) 
    {
        if(b&1) 
        res=(res*a)%m;
        a=(a*a)%m;
        b>>=1;
    }
    return res;
}
LL fact(LL n)
{
     if(n==1)
     return 1;
     else
     return fact(n-1)*n;
}

bool comp(pair<LL,LL> a,pair<LL,LL> b)
{
     if(a.first==b.first)
     {
          return a.second>b.second;
     }
     else
     {
          return a.first<b.first;
     }
}

bool check(vector<LL> &a,LL n,LL i, LL frost)
{
    vector<LL> pref(n);
    pref[0]=a[0]-frost;
    for(int j=1;j<n;j++)
    {
        pref[i]=pref[i-1]+(a[i]-frost);
    }   
    for(int j=0;j<=i;j++)
    {
        if(pref[j]<0)
        {
            return false;
        }
    }
    return true;
}



LL bs(vector<LL> &a,LL n,LL i)
{
    LL lo=*min_element(a.begin(),a.end()),hi=*max_element(a.begin(),a.end());
    while(lo<=hi)
    {
        LL mid=lo+(hi-lo)/2;
        if(check(a,n,i,mid))
        {
            lo=mid+1;
        }
        else
        {
            hi=mid-1;
        }
    }
    return lo-1;   
}

void solve()
{
    LL n1,n2,k1,k2;
    cin>>n1>>n2>>k1>>k2;

    vector<vector<vector<LL>>> dp(n1+1,vector<vector<LL>>(n2+1,vector<LL>(2,0)));
    // dp[i][j][k] -> i means no. of footmen placed,j means no. of horsemen placed, k means type
    // 0-> footmen, 1-> horsemen (last block placed)

   
    dp[0][0][0]=1,dp[0][0][1]=1;
    for(LL i=0;i<=n1;i++)
    {
        for(LL j=0;j<=n2;j++)
        {
            // if the last placed is footmen(0)

            for(LL x=1;x<=min(k1,i);x++)
            {
                dp[i][j][0]+=(dp[i-x][j][1])%M;
                dp[i][j][0]%=M;
            }
            for(LL y=1;y<=min(k2,j);y++)
            {
                dp[i][j][1]+=(dp[i][j-y][0])%M;
                dp[i][j][1]%=M;
            }
        }
    }
    cout<<(dp[n1][n2][0]+dp[n1][n2][1])%M<<endl;
}

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);  
    int t = 1;
    // cin>>t;
    while (t--) solve();
    return 0;
}