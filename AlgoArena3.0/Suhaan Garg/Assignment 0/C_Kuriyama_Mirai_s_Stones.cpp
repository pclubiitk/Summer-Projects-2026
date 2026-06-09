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
bool check(vector<LL> &a, LL diff, vector<LL> &pref, LL k)  
{
    
}



LL bs(vector<LL> &a,vector<LL> &pref,LL k)
{
   
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
    LL n;
    cin>>n;
    vector<LL> v(n),u(n),pref_v(n),pref_u(n);
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
        u[i]=v[i];
    }
    pref_v[0]=v[0];
    for(int i=1;i<n;i++)
    {
        pref_v[i]=pref_v[i-1]+v[i];
    }
    sort(u.begin(),u.end());
    pref_u[0]=u[0];
    for(int i=1;i<n;i++)
    {
        pref_u[i]=pref_u[i-1]+u[i];
    }
    LL m;
    cin>>m;
    while(m--)
    {
        LL type,l,r;
        cin>>type>>l>>r;
        l--,r--;
        if(type==1)
        {
            if(l==0)
            {
                cout<<pref_v[r]<<endl;
            }
            else
            {
                cout<<pref_v[r]-pref_v[l-1]<<endl;
            }
        }
        if(type==2)
        {
            if(l==0)
            {
                cout<<pref_u[r]<<endl;
            }
            else
            {
                cout<<pref_u[r]-pref_u[l-1]<<endl;
            }

        }

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
