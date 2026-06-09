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
    string a;
    cin>>a;
    LL l=0,r=n-1;
    vector<LL> b(n),pref(n);
    for(int i=0;i<n;i++)
    {
        b[i]=a[i]-'0'-1;
    }
    pref[0]=b[0];
    for(int i=1;i<n;i++)
    {
        pref[i]=pref[i-1]+b[i];
    }
    map<LL,LL> freq;
    LL ans=0;
    for(int i=0;i<n;i++)
    {
        LL k=pref[i];
        ans+=freq[k];
        freq[k]++;
    }
    cout<<ans+count(pref.begin(),pref.end(),0)<<endl;
    

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
