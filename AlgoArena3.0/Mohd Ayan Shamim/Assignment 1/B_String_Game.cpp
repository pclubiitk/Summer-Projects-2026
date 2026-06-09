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
string getstring(string s,ll mid,vll k){
    string res="";
    ll n=k.size();
    // ll min=INFLL;
    // ll max=-1;
    vll k1(mid+1);
    for(ll i=0;i<=mid;i++){
        k1[i]=k[i];
    }
    sort(k1.begin(),k1.end());
    k1.pb(-1);
    // for(ll i=0;i<mid;i++){
    //     cout<<"k1["<<i<<"]"<<'='<<k1[i]<<endl;
    // }
    ll ptr=0;
    for(ll i=0;i<n;i++){
        if(i!=k1[ptr]-1){
            res+=s[i];
        }
        else ptr++;
    }
    return res;
}
bool found(string f,string s){
    ll ptr=0;
    f+='\0';
    ll n=s.length();
    for(ll i=0;i<n;i++){
        if(s[i]==f[ptr]) ptr++;
    }
    if(ptr==f.length()-1){
        return true;
    }
    return false;
}
/* ===================== SOLVER ===================== */
void solve() {
    string a,s;
    // vector<string> p;
    cin>>a;
    cin>>s;
    // if(found(s,a)){
        // cout<<"YES"<<endl;
    // }
    // else cout<<"NO"<<endl;
    ll n=a.length();
    vll k(n);
    for(auto &l:k)cin>>l;
    ll l=0;//means no removal of letter
    ll r=n-1;//means all letter removed
    // l++=>we can get less letters
    // r--=>we need more letters 
    string f;ll mid;
    bool u;ll ans=0;
    while(l<=r){
        mid=l+(r-l)/2;
       f = getstring(a,mid,k);
       debug(mid);
       debug(f);
       u=found(s,f);
       if(u){
        l=mid+1;ans=l;
       }
       else{
        r=mid-1;
       }
    //    debug(ans);
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