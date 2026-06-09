#include <span>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll MOD = 1000000007;

struct cmp {
    bool operator()(pair<ll,ll> a, pair<ll,ll> b) const {
        if (a.second-a.first+1>b.second-b.first+1) {
            return true;
        }
        else if (a.second-a.first+1<b.second-b.first+1) {
            return false;
        }
        else {
            if (a.second<b.second) {
                return true;
            }
            else {
                return false;
            }
        }
    }
};

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

bool ispalin(string s) {
    bool check=true;
    for (int i=0;i<s.length();i++) {
        if (s[i]!=s[s.length()-1-i]) {
            check=false;
            break;
        }
    }
    return check;
}

bool isit1(string s) {
    bool check=true;
    for (int i=0;i<s.length();i++) {
        if (s[i]!='1') {
            check=false;
            break;
        }
    }
    return check;
}

ll binpow(ll a, ll b) {
    ll ans=1;
    while (b>0) {
        if (b%2==0) {
            a=a*a;
            a=a%MOD;
            b=b/2;
        }
        else {
            b--;
            ans=ans*a;
            ans=ans%MOD;
        }
    }
    return ans;
}

vector<vector<ll>> multi(vector<vector<ll>>& a, vector<vector<ll>>& b) {
    vector<vector<ll>> c(a.size(),vector<ll>(a.size()));
    for (int i=1;i<a.size();i++) {
        for (int k=1;k<a.size();k++) {
            if (a[i][k]==0) continue;

            for (int j=1;j<a.size();j++) {
                c[i][j]+=a[i][k]*b[k][j];
                c[i][j]=c[i][j]%MOD;
            }
        }
    }
    return c;
}

vector<vector<ll>> matpow(vector<vector<ll>> a, ll b) {
    vector<vector<ll>> ans(a.size(),vector<ll>(a.size()));
    for (int i=1;i<a.size();i++) {
        ans[i][i]=1;
    }
    while (b>0) {
        if (b%2==1) {
            ans = multi(ans,a);
            b--;
        }
        else {
            a = multi(a,a);
            b=b/2;
        }
    }
    return ans;
}

ll inv_arr[1000001];

void preinv(ll n) {
    inv_arr[1] = 1;
    for (ll i = 2; i <= n; i++)
        inv_arr[i] = (MOD - (MOD / i) * inv_arr[MOD % i] % MOD) % MOD;
}

ll nCr(ll n, ll r) {
    if (r > n || r < 0) return 0;
    if (r > n - r) r = n - r;
    ll ans = 1;
    for (ll i = 0; i < r; i++) {
        ans = ans * ((n - i) % MOD) % MOD;
        ans = ans * inv_arr[i + 1] % MOD;
    }
    return ans;
}

void solve() {
    string s;
    cin>>s;
    string t;
    cin>>t;
    ll n = s.length();
    vector<ll> num(s.length()+1);
    for (int i=1;i<=n;i++) {
        cin>>num[i];
    }
    ll min1=1;
    ll max1=n;
    ll best=0;
    while (min1<=max1) {
        ll mid = (min1+max1)/2;
        vector<bool> shouldwetakeit(n+1,true);
        for (int i=1;i<=mid;i++) {
            shouldwetakeit[num[i]]=false;
        }
        string newone="";
        for (int i=1;i<=n;i++) {
            if (shouldwetakeit[i]) {
                newone+=s[i-1];
            }
        }
 //       cout<<newone<<" "<<mid<<'\n';
        ll pointerleft=0;
        bool couldwemakeit=true;
        for (int i=0;i<t.length();i++) {
            while (pointerleft<newone.length() && newone[pointerleft]!=t[i]) {
                pointerleft++;
            }
            if (pointerleft<newone.length()) {
                pointerleft++;
            }
            else {
                couldwemakeit=false;
                break;
            }
        }
        if (couldwemakeit) {
            min1=mid+1;
            if (mid>best) {
                best=mid;
            }
        }
        else {
            max1=mid-1;
        }
    }
    cout<<best<<'\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t=1;
    //cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
