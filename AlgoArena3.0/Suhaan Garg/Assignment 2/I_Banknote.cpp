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
    string a;
    cin>>a;
    vector<LL> b;

    // in b, we did it in opposite order
    for(int i=a.size()-1;i>=0;i--)
    {
        b.push_back(a[i]-'0');
    }
    
    vector<vector<LL>> dp(a.size()+1,vector<LL>(2,0));
    // dp[i][0] denote the min. notes exchanges to give the first i digits of val. from unit digit
    // 0-> for no carry over for next digit
    // 1-> for carry over for next digit

    LL n=a.size();
    if(n==1)
    {
        cout<<min(b[0],11-b[0])<<endl;
        return;
    }

    dp[0][1]=1e15;

    for(int i=1;i<=n;i++)
    {
        dp[i][0]=min(dp[i-1][0]+b[i-1],dp[i-1][1]+b[i-1]+1);

        dp[i][1]=min(dp[i-1][0]+10-b[i-1],dp[i-1][1]+9-b[i-1]);
    }
    cout<<min(dp[a.size()][0],dp[a.size()][1]+1)<<endl;

}

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);  
    int t = 1;
    cin>>t;
    while (t--) solve();
    return 0;
}