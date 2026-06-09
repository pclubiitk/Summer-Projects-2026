#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define int long long

#define vi vector<int>
#define si set<int>
#define vll vector<ll>
#define ivec input_to_a_vector
#define binsrc binary_search
#define pii pair<int,int>
#define pb push_back
const ll MOD = 1000000007;

// Include sieve in templates

const int MAXN = 2e5 + 5;
long long fact[MAXN], inv_fact[MAXN];

long long power(long long a, long long b, long long mod) { //O(logb)
    long long res = 1; a %= mod;
    while (b > 0) {
        if (b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

void precompute() {
    fact[0] = 1;
    for (int i = 1; i < MAXN; i++)
        fact[i] = fact[i-1] * i % MOD;
    inv_fact[MAXN-1] = power(fact[MAXN-1], MOD-2, MOD); //Fermat's little theoram
    for (int i = MAXN-2; i >= 0; i--)
        inv_fact[i] = inv_fact[i+1] * (i+1) % MOD;
}
long long nCr(int n, int r) {
    if (r < 0 || r > n) return 0;
    //cout<<fact[n]<<endl;
    return fact[n] % MOD * inv_fact[r] % MOD * inv_fact[n-r] % MOD;
}


bool comp(pii p1, pii p2){
    if (p1.first<p2.first || p1.first==p2.first && p1.second<p2.second) return true;
    return false;   
}


vi input_to_a_vector(int n){
    vi vec(n+1);
    for (int i=1; i<=n; i++) cin>>vec[i];
    return vec;
}
void swap(int &a, int&b){
    int t = a; a=b; b=t;
}

void solve(){
    int n; cin>>n;
    vi a = ivec(n);

    map<int,int> freq;
    for (int i=1; i<=n; i++) freq[a[i]]++;

    int num = (*(freq.begin())).first;
    auto it = freq.begin(); it++;

    vi vec={num};
    int pts=0;
    while(it!=freq.end()){
        if (it->first==num+1){
            vec.pb(it->first);
            num++;
        }
        else{
            int k = vec.size();
            vi dp(k);
            dp[0] = freq[vec[0]]*vec[0];
            if (k>=2) dp[1] = max(freq[vec[0]]*vec[0], freq[vec[1]]*vec[1]);
            if (k>=3) dp[2] = max(freq[vec[0]]*vec[0] + freq[vec[2]]*vec[2], freq[vec[1]]*vec[1]);
            for (int i=3; i<k; i++) dp[i] = max({dp[i-1], dp[i-2]+freq[vec[i]]*vec[i], dp[i-3]+freq[vec[i]]*vec[i]});
            pts+=dp[k-1];


            vec={it->first};
            num=it->first;
        }
        it++;
    }
    int k = vec.size();
    vi dp(k);
    dp[0] = freq[vec[0]]*vec[0];
    if (k>=2) dp[1] = max(freq[vec[0]]*vec[0], freq[vec[1]]*vec[1]);
    if (k>=3) dp[2] = max(freq[vec[0]]*vec[0] + freq[vec[2]]*vec[2], freq[vec[1]]*vec[1]);
    for (int i=3; i<k; i++) dp[i] = max({dp[i-1], dp[i-2]+freq[vec[i]]*vec[i], dp[i-3]+freq[vec[i]]*vec[i]});
    pts+=dp[k-1];

    cout<<pts;

    
}


int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; t=1;
    while(t--){
        solve();
    }
    
}

/*
cout<<"Check1"<<endl;
cout<<"Check2"<<endl;
cout<<"Check3"<<endl;
cout<<"Check4"<<endl;
*/



