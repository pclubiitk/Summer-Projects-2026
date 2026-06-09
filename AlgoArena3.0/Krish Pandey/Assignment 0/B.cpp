#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

#define pii pair<int,int>
#define pli pair<ll,int>
#define minpq priority_queue<int, vector<int>, greater<int>>
#define minpqDij priority_queue<pli, vector<pli>, greater<pli>>

#define INF LLONG_MAX
#define NINF LLONG_MIN
#define vi vector<int> 
#define vll vector<long long>

vector<int> seive(const int N)
{
    vector<int> s(N+1,1);
    s[0]=s[1]=0;
    for(int i=2;i*i<=N;i++)
    {
        if(s[i]==0) continue;
        for(int j=i*i;j<=N;j+=i)
        {
            s[j]=0;
        }
    }
    return s;
}

vector<int> spf(const int N)
{
    vector<int> spf(N+1);
    for(int i=0;i<=N;i++)
    {
        spf[i]=i;
    }
    for(int i=2;i*i<=N;i++)
    {
        if(spf[i]!=i) continue;
        for(int j=i*i;j<=N;j+=i)
        {
            if(spf[j]!=j) continue; //unnecessary in this context
            spf[j]=i;
        }
    }
    return spf;

    //factorization into primes template using spf
    /*int x;
    while(x>1)
    {
        int p=spf[x];
        int ct=0;
        while(x%p==0)
        {
            x=x/p;
            ct++;
        }
    }*/
}

vector<vector<int>> divisors(const int N)
{
    vector<vector<int>> divisors(N+1);
    for(int i=1;i<=N;i++)
    {
        for(int j=i;j<=N;j+=i)
        {
            divisors[j].push_back(i);
        }
    }
    return divisors;
}

ll modpow(ll a,ll b,ll MOD)
{
    if(a==1) return 1;

    ll ans=1;
    ll curr=a;
    while(b>0)
    {
        if(b%2==0)
        {
            curr=(1LL*curr*curr)%MOD;
            b=b/2;
        }
        else
        {
            ans=(1LL*ans*curr)%MOD;
            b--;
        }
    }
    return ans;
}

ll modInv(ll a,ll MOD) //assuming that MOD is prime
{
    return modpow(a,MOD-2,MOD);
}

// Precompute factorials only
void precomputeFact(int n, ll mod, vector<ll> &fact) {
    fact.resize(n + 1);
    fact[0] = 1;
    for (int i = 1; i <= n; i++)
        fact[i] = fact[i - 1] * i % mod;
}

void precomputeInvFact(int n, ll mod, vector<ll> &fact, vector<ll> &invFact) {
    invFact.resize(n + 1);

    invFact[n] = modInv(fact[n],mod);  

    for (int i = n - 1; i >= 0; i--)
        invFact[i] = invFact[i + 1] * (i + 1) % mod;
}

void nge(vector<int>& a)
{
    int n=a.size();
    vector<int> nge(n,n);
    stack<int> s;
    for(int i=0;i<n;i++)
    {
        while(!s.empty() && a[s.top()]<a[i])
        {
            nge[s.top()]=i;
            s.pop();
        }
        s.push(i);
    }
}


// nCr using fact and invFact
ll nCr(int n, int r, ll mod,
       vector<ll> &fact, vector<ll> &invFact) {

    if (r < 0 || r > n) return 0;
    return fact[n] * invFact[r] % mod * invFact[n - r] % mod;
}

vector<ll> dijkstra(vector<vector<pli>>& adj,int s)
{
    int n=adj.size();
    vector<ll> dist(n,INF);
    dist[s]=0;

    minpqDij pq;
    pq.push({0,s});
    while(!pq.empty())
    {
        auto x=pq.top();
        pq.pop();
        int u=x.second;
        ll d=x.first;

        if(d>dist[u]) continue;
        for(auto y:adj[u])
        {
            int v=y.second;
            ll w=y.first;
            if(dist[u]!=INF && w+dist[u]<dist[v])
            {
                dist[v]=w+dist[u];
                pq.push({dist[v],v});
            } 
        }
    }
    return dist;
}

vector<int> topoSort(int n, vector<vector<int>> &adj) {
    vector<int> indeg(n+1, 0);
    for (int i = 1; i <= n; i++) {
        for (int v : adj[i]) indeg[v]++;
    }
    queue<int> q;
    for (int i = 1; i <= n; i++) if (indeg[i] == 0) q.push(i);
    vector<int> topo;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        topo.push_back(u);
        for (int v : adj[u]) {
            indeg[v]--;
            if (indeg[v] == 0) q.push(v);
        }
    }

    if(topo.size()!=n)
    {
        //CYCLE DETECTED
        cout<<"CYCLE"<<endl;
    }
    return topo;
}

//cmp for sets
/*struct cmp {
    bool operator()(const pair<int,int>& a, const pair<int,int>& b) const {
        if (a.first != b.first)
            return a.first > b.first;   
        return a.second > b.second;     
    }
};*/ 

void dfsGraphs(int i,
         vector<vector<int>> &adj,
         vector<int> &vis) {

    vis[i] = 1;

    for (int x : adj[i]) {
        if (!vis[x]) {
            dfsGraphs(x, adj, vis);
        }
    }
}

void bfs(int start,vector<vector<int>> &adj) 
{
    int n=adj.size()-1;
    queue<int> q;
    q.push(start);
    vector<int> dist(n+1,-1);
    dist[start] = 0;

    while (!q.empty()) {
        int i = q.front();
        q.pop();

        for (int x : adj[i]) {
            if (dist[x] == -1) {
                dist[x] = dist[i] + 1;
                q.push(x);
            }
        }
    }
}

void dfs(int i,int p,vector<vector<int>>& adj) //DFS ON TREES ONLY
{
    for(int x:adj[i])
    {
        if(x==p) continue;
        dfs(x,i,adj);
    }
}

bool cmp(pair<ll,ll> a,pair<ll,ll> b) {
    if (a.first!=b.first) {
        return a.first<b.first;
    }
    else {
        return a.second<b.second;
    }
}

struct Compare {
    bool operator()(pair<int,int> a, pair<int,int> b) {
        ll xa=1LL*a.first*a.second;
        ll xb=1LL*b.first*b.second;

        return xa>xb;
    }
};


void solve()
{
    int n;
    cin>>n;
    vll x(n);
    for(int i=0;i<n;i++)
    {
        cin>>x[i];
        ll val=round(sqrt(x[i]));
        if(1LL*val*val!=x[i])
        {
            cout<<"NO"<<endl;
        }
        else
        {
            if(val==1)
            {
                cout<<"NO"<<endl;
                continue;
            }
            int ct=0;
            for(int j=2;j<=sqrt(val);j++)
            {
                if(val%j==0) ct++;
            }
            if(ct==0)
            {
                cout<<"YES"<<endl;
                continue;
            }
            else
            {
                cout<<"NO"<<endl;
            }
        }
    }
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t=1;
    //cin>>t;
    while(t--){
        solve();
    }
    return 0;
}