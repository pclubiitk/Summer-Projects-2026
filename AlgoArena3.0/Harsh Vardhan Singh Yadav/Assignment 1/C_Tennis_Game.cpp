// #include "bits/stdc++.h"
// using namespace std;
// #define int long long
// #define vi vector<int>
// #define vvi vector<vector<int>>
// #define pb push_back
// #define all(x) (x).begin(), (x).end()
// #define sz(x) (int)(x).size()
// #define ff first
// #define ss second
// #define input(v) for(int &i:v)cin>>i
// #define output(v) for(int &i:v)cout>>i>>" "
// typedef pair<int,int> pii;
// typedef vector<pii> vpii;

// const int MOD = 1e9 + 7;
// const int INF = 1e18;
// const int NEG_INF = -1e18;

// // ─── Graph ───────────────────────────────────────────────
// const int N = 2e5 + 5;
// vector<int> adj[N];
// vector<bool> visited(N, false);

// void resetGraph(int n) {
//     for (int i = 0; i <= n; i++) {
//         adj[i].clear();
//         visited[i] = false;
//     }
// }

// void dfs(int u) {
//     visited[u] = true;
//     for (int v : adj[u])
//         if (!visited[v]) dfs(v);
// }

// void bfs(int src, vector<int>& dist) {
//     queue<int> q;
//     visited[src] = true;
//     dist[src] = 0;
//     q.push(src);
//     while (!q.empty()) {
//         int u = q.front(); q.pop();
//         for (int v : adj[u]) {
//             if (!visited[v]) {
//                 visited[v] = true;
//                 dist[v] = dist[u] + 1;
//                 q.push(v);
//             }
//         }
//     }
// }

// // ─── DSU ─────────────────────────────────────────────────
// struct DSU {
//     vector<int> par, rnk;
//     DSU(int n) : par(n), rnk(n, 0) { iota(all(par), 0); }
//     int find(int x) { return par[x] == x ? x : par[x] = find(par[x]); }
//     bool unite(int x, int y) {
//         x = find(x); y = find(y);
//         if (x == y) return false;
//         if (rnk[x] < rnk[y]) swap(x, y);
//         par[y] = x;
//         if (rnk[x] == rnk[y]) rnk[x]++;
//         return true;
//     }
// };

// // ─── Math ─────────────────────────────────────────────────
// int power(int base, int exp, int mod = MOD) {
//     int result = 1; base %= mod;
//     while (exp > 0) {
//         if (exp & 1) result = result * base % mod;
//         base = base * base % mod;
//         exp >>= 1;
//     }
//     return result;
// }

// // ─── Sieve ────────────────────────────────────────────────
// const int SIEVE_N = 1e6 + 5;
// vector<bool> is_prime(SIEVE_N, true);

// void sieve() {
//     is_prime[0] = is_prime[1] = false;
//     for (int i = 2; i * i < SIEVE_N; i++)
//         if (is_prime[i])
//             for (int j = i * i; j < SIEVE_N; j += i)
//                 is_prime[j] = false;
// }

// // ─── Solve ────────────────────────────────────────────────
// void solve() {
//     int n;
//     cin>>n;
//     vi v(n);
//     input(v);
//     vpii v2;
//     int c1,c2;
//     for(int i : v){
//         c1 +=(i==1);
//         c2 +=(i==2);
//     } 
//     if(c1==c2){
//         cout<<"0\n";
//         return;
//     }
//     int lo=1,hi=max(c1,c2),mid;


    
// }

// signed main() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
//     // freopen("input.txt", "r", stdin);
//     // freopen("output.txt", "w", stdout);

    
//         solve();
    

//     return 0;
// }