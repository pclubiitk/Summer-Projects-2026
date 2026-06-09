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

// LL gcd(LL a,LL b) 
// {
//     return b?gcd(b,a%b):a;
// }
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
bool check(LL n,LL m,LL x,LL k)  
{
    LL count=0;
    for(LL i=1;i<=n;i++)
    {
        count+=(min((x/i),m));
    }
    if(count>=k)
    {
        return true;
    }        
    else return false;
}

LL bs(LL n,LL m,LL k)
{
    LL hi=1e14,lo=0,ans;
    while(lo<=hi)
    {
        LL mid=lo+(hi-lo)/2;
        if(check(n,m,mid,k))
        {
            hi=mid-1;
            ans=mid;
        }
        else
        {
            lo=mid+1;
        }
    }
    return ans;
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





void solve()
{
    LL n,m,k;
    cin>>n>>m>>k;
    cout<<bs(n,m,k)<<endl;   
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
