#include "bits/stdc++.h"
using namespace std;
#define int long long
#define vi vector<int>
#define vvi vector<vector<int>>
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
#define ff first
#define ss second
typedef pair<int,int> pii;
typedef vector<pii> vpii;

const int MOD = 1e9 + 7;
const int INF = 1e18;
const int NEG_INF = -1e18;

// ─── Graph ───────────────────────────────────────────────
const int N = 2e5 + 5;
vector<int> adj[N];
vector<bool> visited(N, false);

void resetGraph(int n) {
    for (int i = 0; i <= n; i++) {
        adj[i].clear();
        visited[i] = false;
    }
}

void dfs(int u) {
    visited[u] = true;
    for (int v : adj[u])
        if (!visited[v]) dfs(v);
}

void bfs(int src, vector<int>& dist) {
    queue<int> q;
    visited[src] = true;
    dist[src] = 0;
    q.push(src);
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int v : adj[u]) {
            if (!visited[v]) {
                visited[v] = true;
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
}

// ─── DSU ─────────────────────────────────────────────────
struct DSU {
    vector<int> par, rnk;
    DSU(int n) : par(n), rnk(n, 0) { iota(all(par), 0); }
    int find(int x) { return par[x] == x ? x : par[x] = find(par[x]); }
    bool unite(int x, int y) {
        x = find(x); y = find(y);
        if (x == y) return false;
        if (rnk[x] < rnk[y]) swap(x, y);
        par[y] = x;
        if (rnk[x] == rnk[y]) rnk[x]++;
        return true;
    }
};

// ─── Math ─────────────────────────────────────────────────
int power(int base, int exp, int mod = MOD) {
    int result = 1; base %= mod;
    while (exp > 0) {
        if (exp & 1) result = result * base % mod;
        base = base * base % mod;
        exp >>= 1;
    }
    return result;
}

// ─── Sieve ────────────────────────────────────────────────
const int SIEVE_N = 1e6 + 5;
vector<bool> is_prime(SIEVE_N, true);

void sieve() {
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * i < SIEVE_N; i++)
        if (is_prime[i])
            for (int j = i * i; j < SIEVE_N; j += i)
                is_prime[j] = false;
}
bool isSubsequence(string s, string t) {
    
    int i = 0, j = 0;
    while (i < s.size() && j < t.size()) {
        if (s[i] == t[j]) i++; 
        j++;                    
    }
    return i == s.size();
}
// ─── Solve ────────────────────────────────────────────────
void solve() {
    string t,p;
    cin>>t>>p;
    vi v(t.size());
    int a=0;
    for(int &i:v) {cin>>i;
    i--;}
    int lo=0,hi=t.size(),mid;
    while(lo<=hi){
        mid=lo+(hi-lo)/2;
        vector<char> v2(t.size(),'0');
        for(int i = mid;i<v.size();i++){
            v2[v[i]]=t[v[i]];
        }
        string s="";
        for(char b:v2){
            if(b=='0')continue;
            s+=b;
        }
        if(isSubsequence(p,s)==1){
            a=mid;
            lo=mid+1;
        }
        else{
            hi=mid-1;
        }

    }  
    cout<<a<<"\n";      

}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    
        solve();
    

    return 0;
}