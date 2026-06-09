#include <bits/stdc++.h>
using namespace std;

/* ===================== TYPEDEFS ===================== */
using ll = long long;
using ull = unsigned long long;
using ld = long double;

using pii = pair<int,int>;
using pll = pair<ll,ll>;

/* ===================== VECTOR ALIASES ===================== */
using vi  = vector<int>;
using vll = vector<ll>;
using vull = vector<ull>;
using vld = vector<ld>;
using vc  = vector<char>;
using vs  = vector<string>;
using vb  = vector<bool>;
using vpii = vector<pii>;
using vpll = vector<pll>;

/* ===================== 2D VECTOR ALIASES ===================== */
using vvi  = vector<vi>;
using vvll = vector<vll>;
using vvc  = vector<vc>;

/* ===================== CONSTANTS ===================== */
const ll INFLL = 4e18;
const int INF = 1e9;
const int MOD = 1e9 + 7;

/* ===================== FAST IO ===================== */
#define fastio() ios::sync_with_stdio(false); cin.tie(NULL)

/* ===================== MACROS ===================== */
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()

/* ===================== DEBUG ===================== */
#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x << " = " << (x) << "\n"
#else
#define debug(x)
#endif

/* ===================== NUMBER THEORY ===================== */
ll gcdll(ll a, ll b) { return b ? gcdll(b, a % b) : a; }
ll lcmll(ll a, ll b) { return a / gcdll(a, b) * b; }

bool isPrime(ll n) {
    if (n < 2) return false;
    for (ll i = 2; i * i <= n; i++)
        if (n % i == 0) return false;
    return true;
}

vector<ll> getDivisors(ll n) {
    vector<ll> d;
    for (ll i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            d.pb(i);
            if (i * i != n) d.pb(n / i);
        }
    }
    return d;
}

/* ===================== MODULAR ARITHMETIC ===================== */
ll modexp(ll a, ll b, ll m = MOD) {
    ll res = 1;
    while (b) {
        if (b & 1) res = (res * a) % m;
        a = (a * a) % m;
        b >>= 1;
    }
    return res;
}

ll modinv(ll a, ll m = MOD) {
    return modexp(a, m - 2, m);
}

/* ===================== BIT UTILITIES ===================== */
int setbitcount(ll x) { return __builtin_popcountll(x); }
bool isPowerOfTwo(ll x) { return x && !(x & (x - 1)); }
ll lowestSetBit(ll x) { return x & -x; }

/* ===================== MATH HELPERS ===================== */
ll ceil_div(ll a, ll b) { return (a + b - 1) / b; }
ll floor_div(ll a, ll b) { return a / b; }

/* ===================== STRING HELPERS ===================== */
string toLower(string s) {
    for (char &c : s) c = tolower(c);
    return s;
}

string toUpper(string s) {
    for (char &c : s) c = toupper(c);
    return s;
}

bool isPalindrome(const string &s) {
    int l = 0, r = sz(s) - 1;
    while (l < r) if (s[l++] != s[r--]) return false;
    return true;
}

/* ===================== VECTOR HELPERS ===================== */
template <typename T>
T sumVector(const vector<T> &v) {
    T s = 0;
    for (auto &x : v) s += x;
    return s;
}

template <typename T>
T maxVector(const vector<T> &v) {
    return *max_element(all(v));
}

template <typename T>
T minVector(const vector<T> &v) {
    return *min_element(all(v));
}

/* ===================== GRID HELPERS ===================== */
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

bool inside(int x, int y, int n, int m) {
    return x >= 0 && y >= 0 && x < n && y < m;
}
ll check(ll mid,vll a){
    ll n=a.size();
    ll l=0;
    ll h=n-1;
    ll res=0;
    for(ll i=0;i<n;i++){
        auto k = lower_bound(all(a),mid-a[i]);
        res += n-(k-a.begin());
    }
    return res;//how many elements are >=mid
}
/* ===================== SOLVER ===================== */
void solve() {
    ll n;
    cin>>n;
    ll m;
    cin>>m;
    vll a(n);vll psum(n+1);
    psum[0]=0;
    for(ll i=0;i<n;i++){
        cin>>a[i];
    }
    sort(all(a));
    for(ll i=0;i<n;i++){
        psum[i+1]=psum[i]+a[i];
    }
    ll l=0;
    ll h=2*a[n-1];
    ll mid;
    ll msum=0;
    while(l<=h){
        mid=l+(h-l)/2;
        if(check(mid,a)>=m){
            l=mid+1;
            msum=mid;
        }
        else{
            h=mid-1;
        }
    }
    ll ans=0;
    ll pairs_counted=0;
    for(ll i=0;i<n;i++){
        auto k = lower_bound(all(a),msum-a[i]);
        ans+=psum[n]-psum[k-a.begin()]+(n-(k-a.begin()))*a[i];
        pairs_counted+=n-(k-a.begin());
    }
    if(pairs_counted > m){
        ans -= (pairs_counted - m) * msum;
    }
    cout<<ans<<endl;
}
/* ===================== MAIN ===================== */
int main() {
    fastio();
    int t = 1;
    // cin >> t;
    while (t--) solve();
    return 0;
}