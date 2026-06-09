#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

#define INF LLONG_MAX
#define NINF LLONG_MIN
#define vi vector<int> 
#define vll vector<long long>

vector<vector<int>> divisors(const int N)
{
    vector<vector<int>> divisors(N+1);
    for(int i=1;i<=N;i++)
    {
        for(int j=i;j<=N;j+=i)
        {
            divisors[j].push_back(i);
        }
    }
    return divisors;
}

ll modpow(ll a,ll b,ll MOD)
{
    if(a==1) return 1;

    ll ans=1;
    ll curr=a;
    while(b>0)
    {
        if(b%2==0)
        {
            curr=(1LL*curr*curr)%MOD;
            b=b/2;
        }
        else
        {
            ans=(1LL*ans*curr)%MOD;
            b--;
        }
    }
    return ans;
}

ll modInv(ll a,ll MOD) //assuming that MOD is prime
{
    return modpow(a,MOD-2,MOD);
}

// Precompute factorials only
void precomputeFact(int n, ll mod, vector<ll> &fact) {
    fact.resize(n + 1);
    fact[0] = 1;
    for (int i = 1; i <= n; i++)
        fact[i] = fact[i - 1] * i % mod;
}

void precomputeInvFact(int n, ll mod, vector<ll> &fact, vector<ll> &invFact) {
    invFact.resize(n + 1);

    invFact[n] = modInv(fact[n],mod);  

    for (int i = n - 1; i >= 0; i--)
        invFact[i] = invFact[i + 1] * (i + 1) % mod;
}

const int MOD=998244353;

ll nCr(ll n,ll p,vector<ll>& invFact)
{
    ll ans=1;
    ll val=n;
    for(int i=0;i<p;i++)
    {
        ans=(ans*val)%MOD;
        val--;
    }
    ans=(ans*invFact[p])%MOD;
    return ans;
}

void solve(vector<vector<int>>& dp,vector<ll>& invFact)
{
    int k,n;
    cin>>k>>n;
    cout<<n<<" ";
    for(int i=2;i<=k;i++)
    {
        ll ans=0;
        for(int j=1;j<=20;j++)
        {
            if(dp[i][j]==0) break;
            ll val=nCr(n+1,j+1,invFact);
            val=(1LL*val*dp[i][j])%MOD;
            ans=(ans+val)%MOD;
        }
        cout<<ans<<" ";
    }
    cout<<endl;
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t=1;
    cin>>t;

    vector<ll> fact;
    vector<ll> invFact;
    precomputeFact(1e5+1,MOD,fact);
    precomputeInvFact(1e5+1,MOD,fact,invFact);

    vector<vector<int>> div=divisors(1e5);
    vector<vector<int>> dp(1e5+1,vector<int>(21,0));
    dp[2][1]=1;
    for(int i=3;i<=1e5;i++)
    {
        for(int x:div[i])
        {
            if(x==1) continue;
            if(x==i)
            {
                dp[i][1]=1;
                continue;
            }
            int divisor=x;
            int quotient=i/x;
            for(int y=2;y<=20;y++)
            {
                dp[i][y]=(dp[i][y]+dp[quotient][y-1])%MOD;
            }
        }
    }

    while(t--){
        solve(dp,invFact);
    }
    return 0;
}