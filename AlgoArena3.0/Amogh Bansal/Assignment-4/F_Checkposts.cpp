#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pi pair<int,int>
#define pl pair<ll,ll>
#define vi vector<int>
#define vl vector<ll>
#define vpi vector<pi>
#define vpl vector<pl>
#define endl '\n'
#define pb push_back

#define rep(i, n) for(int i = 0; i < (n); i++)
#define rep1(i, a, b) for(int i = (a); i < (b); i++)
#define rrep(i, n) for(int i = (n) - 1; i >= 0; i--)

const ll MOD = 1000000007;
const int MAXN = 2e5 + 5;

ll fact[MAXN], invFact[MAXN];

ll power(ll a, ll b, ll mod = MOD){
    ll res = 1;
    a %= mod;
    while(b > 0){
        if(b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

void precomputeFactorials(){
    fact[0] = 1;
    rep1(i, 1, MAXN) fact[i] = fact[i-1] * i % MOD;
    invFact[MAXN-1] = power(fact[MAXN-1], MOD-2);
    rrep(i, MAXN-1) invFact[i] = invFact[i+1] * (i+1) % MOD;
}

ll nCr(int n, int r){
    if(r < 0 || r > n) return 0;
    return fact[n] * invFact[r] % MOD * invFact[n-r] % MOD;
}

ll nPr(int n, int r){
    if(r < 0 || r > n) return 0;
    return fact[n] * invFact[n-r] % MOD;
}

//ONE INDEXED
void dfs(int node, vi& vis, stack<int>& st, const vector<vi>& adj){
    vis[node] = 1;
    for(int i : adj[node]){
        if(!vis[i]) dfs(i,vis,st,adj);
    }
    st.push(node);
}
//ONE INDEXED
vi topoSort(int V, const vector<vi>& adj){
    vi vis(V+1,0);
    stack<int> st;
    rep1(i,1,V+1){
        if(!vis[i]) dfs(i,vis,st,adj);
    }
    vi ans;
    while(!st.empty()){
        ans.pb(st.top());
        st.pop();
    }
    return ans;
}

int kosaraju(const vector<vi>& adj, vector<vi>& scc, int n){
    stack<int> st;
    vi vis(n+1,0);
    rep1(i,1,n+1){
        if(!vis[i]) dfs(i,vis,st,adj);
    }
    //dfs(1,vis,st,adj);
    vector<vi> rev_adj(n+1);
    rep1(i,1,n+1){
        for(int k : adj[i]){
            rev_adj[k].pb(i);
        }
    }

    rep(i,n+1){
        vis[i] = 0;
    }
    stack<int> ds;
    vi tmp;
    int num = 0;
    while(!st.empty()){
        
        while(vis[st.top()] != 0){
            st.pop();
            if(st.empty()) break;
        }
        
        if(st.empty()) break;
        //cout << st.top() << " ";
        int node = st.top();
        dfs(node, vis, ds, rev_adj);
        while(!ds.empty()){
            tmp.pb(ds.top());
            ds.pop();
        }
        scc.pb(tmp);
        tmp = {};
        num++;
        st.pop();
    }
    //cout << endl;
    return num;
}

vi getFactors(int n){
    vi factors;
    for(int i = 1; i * i <= n; i++){
        if(n % i == 0){
            factors.pb(i);
            if(i != n/i) factors.pb(n/i);
        }
    }
    sort(factors.begin(), factors.end());
    return factors;
}

struct SegTree {
    int n;
    vl t;

    ll e(){return 0;}
    ll op(ll a, ll b) {return a + b; }

    SegTree(int _n) : n(_n), t(4*_n, e()) {}
    SegTree(const vl& a) : n(a.size()), t(4*a.size()) {build(1,0,n-1,a);}

    void build(int node, int lo, int hi, const vl& a){
        if(lo == hi){t[node] = a[lo]; return;}
        int mid = (lo + hi)/2;
        build(2*node, lo, mid, a);
        build(2*node + 1, mid + 1, hi, a);
        t[node] = op(t[2*node], t[2*node+1]);
    }

    void update(int node, int lo, int hi, int idx, ll val){
        if(lo == hi){
            t[node] = val;
            return;
        }
        int mid = (lo+hi)/2;
        if(idx <= mid) update(2*node, lo, mid, idx, val);
        else update(2*node + 1, mid + 1, hi, idx, val);
        t[node] = op(t[2*node], t[2*node+1]);
    }

    ll query(int node, int lo, int hi, int l, int r){
        if(r < lo || hi < l) return e();
        if(l <= lo && hi <= r) return t[node];
        int mid = (lo + hi)/2;
        return op(query(2*node, lo, mid, l, r), query(2*node + 1, mid + 1, hi, l, r));
    }

    void update(int idx, ll val){
        update(1,0,n-1, idx, val);
    }
    ll query(int l, int r){
        return query(1,0,n-1,l,r);
    }
};



/*
sort(v.begin(), v.end(), greater<int>())
stable_sort(v.begin(), v.end())
reverse(v.begin(), v.end())
sort(v.begin(), v.end(), [](auto&a, auto&b){ return a.second < b.second; })
lower_bound(v.begin(), v.end(), x) (>=x)
upper_bound(v.begin(), v.end(), x) (>x)
binary_search(v.begin(), v.end(), x) (bool)
upper_bound(...) - lower_bound(...) to count occurences of x
*max_element(v.begin(), v.end())
accumulate(v.begin(), v.end(), 0LL)
accumulate(v.begin(), v.end(), 1LL, multiplies<ll>())
partial_sum(v.begin(), v.end(), out.begin())
iota(v.begin(), v.end(), 0)
count(v.begin(), v.end(), x)
find(v.begin(), v.end(), x) (iterator to first x or end())
v.erase(unique(v.begin(), v.end()), v.end())
next_permutation(v.begin(), v.end()) (returns false when wrapping) (use do while)
s.substr(pos, len) (substring starting at pos, length len)
s.find(t)  (index of first occurrence of t, or string::npos)
stoi(s), stoll(s), to_string(x)
sort(s.begin(), s.end())
count(s.begin(), s.end(), 'a')

fill(v.begin(), v.end(), x)
cout << fixed << setprecision(9) << ans

s.insert(x) add (set ignores dupes, multiset keeps them)
s.count(x) set: 0/1; multiset: how many
s.find(x) iterator to element, or s.end() if absent
s.erase(x) removes ALL copies (careful with multiset)
s.erase(s.find(x)) remove ONE copy (the multiset idiom)
s.lower_bound(x) s.upper_bound(x) 
*s.begin() smallest, *s.rbegin() — largest
s.erase(it) erase by iterator

mp[k] access/insert (auto-creates with default value 0 if absent)
mp[k]++, mp[k] += x
mp.count(k) 0/1 for existence (checking without inserting)
mp.find(k)  iterator or .end()
mp.erase(k)
mp.lower_bound(k) 
for(auto& [k,v] : mp) sorted by key
*/



void solve(){
    int n,m;
    cin >> n;
    vi arr(n+1);
    rep1(i,1,n+1){
        cin >> arr[i];
    }
    cin >> m;

    vector<vi> adj(n+1);
    rep(i, m){
        int a,b;
        cin >> a >> b;
        adj[a].pb(b);
    }
    vector<vi> scc;
    int num = kosaraju(adj,scc,n);

    vi kds(n+1);
    ll ans = 0;
    ll ways = 1;
    rep(i,num){
        int cs;
        ll ws = 1;
        for(int j = 0; j < scc[i].size(); j++){
            int k = scc[i][j];
            kds[k] = i+1;
            if(j==0){
                cs = arr[k];
                continue;
            }
            if(arr[k] == cs){
                ws++;
            }
            else if (arr[k] < cs){
                cs = arr[k];
                ws = 1;
            }
            //cs = min(cs,arr[k]);
        }
        ways = (ways * ws) % MOD;
        ans += cs;
    }
    cout << ans << " " << ways;

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    t = 1;
    //cin >> t;
    while (t--){
        solve();
    }
}
