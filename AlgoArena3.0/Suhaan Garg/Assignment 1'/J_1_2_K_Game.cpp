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
// bool check(LL n,LL k,vector<LL> &a,vector<LL> &b,LL x)  
// {
//     LL count=0;
//     for(int i=0;i<n;i++)
//     {
//         auto it=upper_bound(b.begin(),b.end(),x-a[i]);
//         count+=(it-b.begin());
//     }    
//     if(count>=k)
//     return true;
//     else return false;
// }

// LL bs(LL n,LL k,vector<LL> &a,vector<LL> &b)
// {
//     LL lo=0,hi=2e9;
//     while(lo<=hi)
//     {
//         LL mid=lo+(hi-lo)/2;
//         if(check(n,k,a,b,mid))
//         {
//             hi=mid-1;
//         }
//         else 
//         {
//             lo=mid+1;
//         }
//     }
//     return hi+1;
   
// }


void solve()
{
    LL n,k;
    cin>>n>>k;
    

    bool ok;
    
    if(n==0)
    {
        cout<<"Bob\n";
        return;
    }
    
    if(k==3)
    {
        if((n+1)%4==1)
        {
            cout<<"Bob\n";
            return;
        }
        else 
        {
            cout<<"Alice\n";
            return;
        }
    }
    if(k%3!=0)
    {
        if((n+1)%3==1)
        {
            cout<<"Bob\n";
            return;
        }
        else
        {
            cout<<"Alice\n";
            return;
        }
    }
    if(k%3==0)
    {
        LL m=k/3;
        LL u=n+1;
        u%=(k+1);
        if(u<=(m-1)*3)
        {
            if(u%3==1)
            {
                cout<<"Bob\n";
                return;
            }
            else
            {
                cout<<"Alice\n";
                return;
            }
        }
        else
        {
            if(u==3*(m-1)+1)
            {
                cout<<"Bob\n";
                return;
            }
            else
            {
                cout<<"Alice\n";
                return;
            }
        }
    }

}
int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 
    int t=1;
    cin>>t;
    while (t--) solve();
    return 0;
}
