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
    LL maxe=*max_element(a.begin(),a.end());
    map<LL,LL> dp;
    // dp[i] denotes the longest consecutive seq. ending at i;

    for(int i=0;i<n;i++)
    {
        dp[a[i]]=dp[a[i]-1]+1;
    }
    
    LL final_val;
    LL cnt=1;
    LL maxi=0;
    for(auto x:dp)
    {
        if(maxi<x.second)
        {
            maxi=x.second;
            final_val=x.first;
        }                
        
    }
    
    vector<LL> indices;
    LL m=maxi;
    for(int i=n-1;i>=0 && m>0;i--)
    {
        if(a[i]==final_val)
        {
            indices.push_back(i+1);
            final_val--;
            m--;
        }                                
    }
    cout<<maxi<<endl;
    sort(indices.begin(),indices.end());
    for(auto x:indices)
    {
        cout<<x<<" ";
    }
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