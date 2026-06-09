#include <bits/stdc++.h>
using namespace std;

// --- Type Definitions ---
using ll   = long long;
using lli  = long long int;
using ld   = long double;
using ull  = unsigned long long;

// --- Vectors ---
using vi   = vector<int>;
using vll  = vector<ll>;
using vvi  = vector<vi>;
using vvll = vector<vll>;
using vb   = vector<bool>;
using vd   = vector<double>;
using vs   = vector<string>;

// --- Pairs & Maps ---
using pii  = pair<int, int>;
using pll  = pair<ll, ll>;
using vpii = vector<pii>;
using vpll = vector<pll>;
using mii  = map<int, int>;
using mll  = map<ll, ll>;
using umii = unordered_map<int, int>;
using umll = unordered_map<ll, ll>;

// --- Macros & Utilities ---
#define pb                     push_back
#define mp                     make_pair
#define eb                     emplace_back
#define fi                     first
#define se                     second
#define sz(x)                  ((int)(x).size())
#define all(x)                 (x).begin(), (x).end()
#define rall(x)                (x).rbegin(), (x).rend()
#define uniq(v)                (v).erase(unique(all(v)), (v).end())
#define mem(a, b)              memset(a, b, sizeof(a))

// --- Loops ---
#define rep(i, a, b)           for (int i = (a); i < (b); ++i)
#define repn(i, n)             rep(i, 0, n)
#define per(i, a, b)           for (int i = (b) - 1; i >= (a); --i)
#define pern(i, n)             per(i, 0, n)
#define each(a, x)             for (auto &a : x)

// --- Constants ---
const int INF  = 1e9 + 7;
const ll LINF  = 1e18 + 9;
const ld PI    = acos(-1.0);
const ll MOD   = 1e9 + 7; // 998244353

// --- Fast I/O ---
void fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    #endif
}
ll exist(ll x,ll n,ll m){
    ll res=0;
    for(ll i=1;i<=n;i++){
        res+=min(m,(x-1)/i);
    }
    return res;
}
void solve() {
    ll n,m,k;
    cin>>n>>m>>k;
    ll l,h;ll x;
    l=1;
    h=n*m;
    ll ans;
    while(l<=h){
        x=l+(h-l)/2;
        if(exist(x,n,m)<k){
            ans=x;
            l=x+1;
        }
        else{
            h=x-1;
        }
    }
    cout<<ans<<endl;
}

int main() {
    fast_io();
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}