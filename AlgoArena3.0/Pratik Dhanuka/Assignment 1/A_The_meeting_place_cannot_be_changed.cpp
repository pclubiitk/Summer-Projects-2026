#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using lli = long long int;
using ull = unsigned long long;
using ld = long double;

using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vll = vector<ll>;

const int INF = 1e9;
const ll LINF = 1e18;
const int MOD1 = 1e9 + 7;
const int MOD2 = 998244353;

#define fastio ios::sync_with_stdio(false); cin.tie(nullptr)

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()

const int MAXN = 200000;
int spf[MAXN + 1];
vector<bool> isPrime(MAXN + 1, true);

void sieve_prime(){
    isPrime[0] = isPrime[1] = false;
    for(int i = 2; i * i <= MAXN; i++){
        if(isPrime[i]){
            for(int j = i * i; j <= MAXN; j += i) isPrime[j] = false;
        }
    }
}

void sieve_spf(){
    spf[0] = 0;
    spf[1] = 1;
    for(int i = 2; i <= MAXN; i++) spf[i] = i;
    for(int i = 2; i * i <= MAXN; i++){
        if(spf[i] == i){
            for(int j = i * i; j <= MAXN; j += i)
                if(spf[j] == j) spf[j] = i;
        }
    }
}

vector<pair<int,int>> factorize(int x){
    vector<pair<int,int>> res;
    while(x > 1){
        int p = spf[x], cnt = 0;
        while(x % p == 0){
            x /= p;
            cnt++;
        }
        res.push_back({p, cnt});
    }
    return res;
}

static vector<int> fact, ifact;

long long modpow(long long a, long long b) {
    long long res = 1;
    a %= MOD1;
    while (b > 0) {
        if (b & 1) res = (res * a) % MOD1;
        a = (a * a) % MOD1;
        b >>= 1;
    }
    return res;
}

long long modinv(long long q) {
    return modpow(q, MOD1 - 2);
}

void factorials(int n) {
    fact.resize(n + 1);
    ifact.resize(n + 1);
    fact[0] = 1;
    for (int i = 1; i <= n; ++i)
        fact[i] = (1LL * fact[i - 1] * i)%MOD1;

    ifact[n] = modinv(fact[n]);
    for (int i = n; i > 0; --i)
        ifact[i - 1] = (1LL * ifact[i] * i) % MOD1;
}

int nCr(int n, int r) {
    if (r < 0 || r > n) return 0;
    if ((int)fact.size() <= n) factorials(n);
    return (1LL * fact[n] * ifact[r] % MOD1) * ifact[n - r] % MOD1;
}

void dfs(int s, const vector<vi> &adj, vi &visited) {
    visited[s] = 1;
    for (int v : adj[s]) {
        if (!visited[v]) {
            dfs(v, adj, visited);
        }
    }
}

void bfs(int s, const vector<vi> &adj, vi &visited) {
    queue<int> q;
    q.push(s);
    visited[s] = 1;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v : adj[u]) {
            if (!visited[v]) {
                visited[v] = 1;
                q.push(v);
            }
        }
    }
}

lli exp(lli base, lli exp){
   lli a= 1;
   for(int i = 1;i<=exp;i++){
     a*=base;
   }
   return a;
}

void solve() {
    int n;
    cin>>n;
    ll x[n];
    ll v[n];
    ll m1=LONG_MAX;
    ll m2=0;
    for(int i=0;i<n;i++){
        cin>>x[i];
        m2 = max(m2, x[i]);
        m1 = min(m1, x[i]);
    }
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    double l=m1,r=m2,mid1,mid2,t1=0,t2=0;
    while(r-l>0.000001){
        mid1 = l+(r-l)/3.0;
        mid2 = r- (r-l)/3.0;
        t1=0,t2=0;
        for(int i=0;i<n;i++){
            t1 = max((abs(x[i]-mid1)/(1.0*v[i])),t1);
        }
        for(int i=0;i<n;i++){
            t2 = max((abs(x[i]-mid2)/(1.0*v[i])),t2);
        }
        if(t1<t2){
            r=mid2;
        }
        else l = mid1;
    }
    cout<<fixed<<setprecision(7)<<min(t1,t2)<<"\n";
}

int main() {
    fastio;

    int tt = 1;
    while (tt--) {
        solve();
    }
    return 0;
}