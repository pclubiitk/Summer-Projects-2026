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
const ll MOD = 1e8;

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
int k1,k2;


void func(int n1,int n2, int lm, char lmt, auto &dp){
    
    int&ans = lmt=='F' ? dp[n1][n2][lm].first : dp[n1][n2][lm].second;
    //if (lmt=='F') int &ans = dp[n1][n2][lm].first;
    //else int &ans = dp[n1][n2][lm].second;

    //if (ans!=-1) return;

    if (n1==0 && n2==0) ans=1;

    else if (n1==0){
        if (lmt=='H' && lm==0) ans= 0;
        else if(lmt=='H') {
            if (dp[0][n2-1][lm-1].second==-1) func(0,n2-1,lm-1,'H',dp);
            ans=dp[0][n2-1][lm-1].second;
        }
        else {
            if (dp[0][n2-1][k2-1].second==-1) func(0,n2-1,k2-1,'H',dp);
            ans=dp[0][n2-1][k2-1].second;
            
        }
    }
    else if (n2==0){
        if (lmt=='F' && lm==0) ans= 0;
        else if(lmt=='F') {
            if (dp[n1-1][0][lm-1].first==-1) func(n1-1,0,lm-1,'F',dp);
            ans=dp[n1-1][0][lm-1].first;
        }
        else {
            if (dp[n1-1][0][k1-1].first==-1) func(n1-1,0,k1-1,'F',dp);
            ans=dp[n1-1][0][k1-1].first;
            
        }
    }

    else if (lm==0){
        if(lmt=='H'){
            if (dp[n1-1][n2][k1-1].first==-1) func(n1-1,n2,k1-1,'F',dp);
            ans=dp[n1-1][n2][k1-1].first;
             
        }
        else{
            if (dp[n1][n2-1][k2-1].second==-1) func(n1,n2-1,k2-1,'H',dp);
            ans=dp[n1][n2-1][k2-1].second;
        }
    }

    else if (lmt=='H'){
        if (dp[n1-1][n2][k1-1].first==-1) func(n1-1,n2,k1-1,'F',dp);
        if (dp[n1][n2-1][lm-1].second==-1) func(n1,n2-1,lm-1,'H',dp);

        ans= (dp[n1-1][n2][k1-1].first+dp[n1][n2-1][lm-1].second)%MOD;
        //return func(n1-1,n2,k1-1,'F') + func(n1,n2-1,lm-1,'H');
    }
    else{
        if (dp[n1-1][n2][lm-1].first==-1) func(n1-1,n2,lm-1,'F',dp);
        if (dp[n1][n2-1][k2-1].second==-1) func(n1,n2-1,k2-1,'H',dp);

        ans= (dp[n1-1][n2][lm-1].first+dp[n1][n2-1][k2-1].second)%MOD;
       // return func(n1-1,n2,lm-1,'F') + func(n1,n2-1,k2-1,'H');
    }

    /*
    if (lmt=='F') cout<<dp[n1][n2][lm].first;
    else cout<<dp[n1][n2][lm].second;
    */
    



}

void solve(){
    //cout<<"YAY";
    
    int n1,n2; cin>>n1>>n2>>k1>>k2;
    //vector<vi> dp(n1+n2+1, vi(k1+k2,0));
    vector<vector<vector<pii>>> dp(n1+1,vector<vector<pii>>(n2+1,vector<pii>(max(k1,k2),{-1,-1})));
    
    //cout<<func(n1-1,n2,k1-1,'F',dp) +func(n1,n2-1,k2-1,'H',dp); //total footmen, total horsemen, last_max, last_max_type (F or H)
    func(n1-1,n2,k1-1,'F',dp);
    func(n1,n2-1,k2-1,'H',dp);
    
    
    cout<<(dp[n1-1][n2][k1-1].first+dp[n1][n2-1][k2-1].second)%MOD;
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



