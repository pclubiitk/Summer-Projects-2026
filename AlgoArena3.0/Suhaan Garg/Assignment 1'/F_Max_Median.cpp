#include <bits/stdc++.h>
using namespace std;
using LL = long long;
#include<vector>
#include<string>
#include<map>
#include<set>
#include<stack>
#include<queue>
#define M 1000000007
#include<unordered_map>
using LD = long double;

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


void dfs(int node,vector<set<int>> &adj,vector<bool>&visited)
{
    visited[node]=true;
    for(auto n:adj[node])
    {
        if(!visited[n])
        {
            visited[n]=true;
            dfs(n,adj,visited);
        }
    }
}

bool check_cycle(int curr,int p,vector<set<int>> &adj,vector<bool> &visited) {
    visited[curr] = true;
    for (int v:adj[curr])
    {
        if (v==p)
        continue;
        if(visited[v])
        return true;
        if(check_cycle(v,curr,adj,visited)) 
        return true;
    }
    return false;
}

bool bfs(int start_node,vector<vector<int>> &adj,vector<int> &team)
{
    queue<int> q;
    team[start_node]=1;
    q.push(start_node);
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        for(auto v:adj[u])
        {
            if(team[v]==0)
            {
                if(team[u]==1)
                team[v]=2;
                else
                team[v]=1;
                q.push(v);
            }
            else if(team[u]==team[v])
            {
                return false;                
            }
        }
    }
    return true;
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
bool check(LL n,LL k,vector<LL> &a,LL x)  
{
    vector<LL> b(n);
    for(int i=0;i<n;i++)
    {
        if(a[i]<x)
        {
            b[i]=-1;
        }
        else
        b[i]=1;
    }
    vector<LL> pref(n+1,0);
    // it is 1-indexing 
    for(int i=1;i<=n;i++)
    {
        pref[i]=pref[i-1]+b[i-1];
    }

    LL max_sum=LLONG_MIN;
    LL pref_min=LLONG_MAX;
    for(LL r=k;r<=n;r++)
    {
        LL l=r-k;
        pref_min=LLONG_MAX;
        pref_min=min(pref_min,pref[r-k]);
        max_sum=max(max_sum,pref[r]-pref_min);
    }
    if(max_sum>=1)
    return true;
    else return false;
}

LL bs(LL n,LL k,vector<LL> &a)
{
    LL lo=0,hi=2e9;
    while(lo<=hi)
    {
        LL mid=lo+(hi-lo)/2;
        if(check(n,k,a,mid))
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
    LL n,k;
    cin>>n>>k;
    vector<LL> a(n);
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    cout<<bs(n,k,a)<<endl;


}
int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 
    int t=1;
    // cin>>t;
    while (t--) solve();
    return 0;
}
