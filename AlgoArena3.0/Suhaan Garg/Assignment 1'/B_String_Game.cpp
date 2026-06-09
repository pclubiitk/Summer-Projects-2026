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

bool check(string &t,string &p,LL n,LL x,vector<LL> &a)
{
    string new1=t;
    for(int i=0;i<min(x,(LL)t.size());i++)
    {
        new1[a[i]-1]='0';
    }
    new1.erase(remove(new1.begin(),new1.end(), '0'),new1.end());
    LL p2=0;
    for(int i=0;i<new1.size();i++)
    {
        if(new1[i]==p[p2])
        {
            p2++;
        }
        if(p2==p.size())
        {
            return true;
        }
    }
    return false;
}



LL bs(string &t,string &p,LL n,vector<LL> &a)
{
    LL lo=0,hi=1e9;
    while(lo<=hi)
    {
        LL mid=lo+(hi-lo)/2;
        if(check(t,p,n,mid,a))
        {
            lo=mid+1;
        }
        else hi=mid-1;
    }
    return lo-1;
}

void solve()
{
    string t,p;
    cin>>t>>p;
    LL n=t.size();
    vector<LL> a(n);
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    cout<<bs(t,p,n,a)<<endl;

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
