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
    LL n;
    cin>>n;
    vector<LL> a(n);
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    vector<vector<LL>> dp(n+1,vector<LL>(n+1,1e9));
    // dp[i][j] -> min. turns req. to remove the subarray form i to j

    // base case
    for(int i=0;i<=n;i++)
    {
        dp[i][i]=1;
    }

    for(int i=n;i>=1;i--)
    {
        for(int j=i;j<=n;j++)
        {
            bool pal=true;
            for(int u=0;i+u<=j-u;u++)
            {
                if(a[i+u-1]!=a[j-u-1])
                {
                    pal=false;
                    break;
                }
            }
            if(pal)
            {
                dp[i][j]=1;
            }
            for(int k=i;k<=j-1;k++)
            {
                dp[i][j]=min(dp[i][k]+dp[k+1][j],dp[i][j]);
            }

            // edge case
            if(a[i-1]==a[j-1] && i+1<=j-1)  // the ith element is equal to the jth element 
            // (especially to deal cases like test 3)
            {
                dp[i][j]=min(dp[i][j],dp[i+1][j-1]);    // we dont add extra 1 for the ith and jth element because,
                // when we are removing the last element,we can remove those with it              
            }
        }
    }
    cout<<dp[1][n]<<endl;
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
