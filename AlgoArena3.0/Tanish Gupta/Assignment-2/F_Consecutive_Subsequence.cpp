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
    int n; cin>>n; vi a = ivec(n);
    vi dp(n+1); //dp[i] is the largest length of such subsequence ending with last element as a[i]
    map<int,vi> mp; 
    for (int i=1; i<=n; i++) mp[a[i]].pb(i);

    for (auto it =mp.begin(); it!=mp.end();it++){
        vi&v = it->second;
        sort(v.begin(),v.end());

    }

    for (int i=1; i<=n; i++){
        dp[i]=1;

        if (mp[a[i]-1].size()>0){
            auto it=lower_bound(mp[a[i]-1].begin(),mp[a[i]-1].end(),i);
            if (it!=mp[a[i]-1].begin()) {
                it--;
                dp[i]=dp[*it]+1;
            }
        }
        /*
        for (int ind: mp[a[i]-1]){
            if (ind<i) dp[i] = max(dp[i],dp[ind]+1);
        }   
        */      
    }

    cout<<*max_element(dp.begin(),dp.end())<<endl;
    
    int ind=max_element(dp.begin(),dp.end())-dp.begin();
    vi ans;
    
    while(1){
        ans.pb(ind);


        if (mp[a[ind]-1].size()>0){
            auto it=lower_bound(mp[a[ind]-1].begin(),mp[a[ind]-1].end(),ind);
            if (it!=mp[a[ind]-1].begin()) {
                it--;
                ind=*it;
            }
            else break;
        }
        else break;

        /*
        for(int i: mp[a[ind]-1]){
            if (i<ind && max<dp[i]) {max=dp[i]; news=i;}
        }
        ind=news;
        */
    }
    for (int i=ans.size()-1; i>=0; i--) cout<<ans[i]<<" ";
    
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



