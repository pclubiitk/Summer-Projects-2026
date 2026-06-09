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

bool check(vector<LL> &x,vector<LL> &v,LL n,LD t)
{
    LD l=x[0]-v[0]*t,r=x[0]+v[0]*t;
    for(int i=1;i<n;i++)
    {
        l=max(l,x[i]-v[i]*t);
        r=min(x[i]+v[i]*t,r);
    } 
    if(l<=r)
    {
        return true;
    }
    else return false;
}



LD bs(vector<LL> &x,vector<LL> &v,LL n)
{
    LD lo=0.0,hi=1e9;
    for(int i=1;i<=200;i++)
    {
        LD mid=lo+(hi-lo)/2;
        if(check(x,v,n,mid))
        {
            hi=mid;
        }
        else 
        {
            lo=mid;
        }
    }
    return hi;
}

void solve()
{
   LL n;
   cin>>n;
   vector<LL> x(n),v(n);
   for(int i=0;i<n;i++)
   {
        cin>>x[i];
   }
   for(int i=0;i<n;i++)
   {
        cin>>v[i];
   }
   cout<<fixed<<setprecision(10)<<bs(x,v,n)<<endl;

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
