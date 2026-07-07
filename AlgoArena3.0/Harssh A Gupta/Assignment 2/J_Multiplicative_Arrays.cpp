#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#define loop(i, start, end) for(long long int i = start; i <= end; ++i)
typedef std::string st;
typedef long long int ll;
const ll inf = 9e18;

using namespace std;

const ll limit = 1e5+5;
const ll M = 998244353;

vector<ll> factorials(limit+1), inv_factorials(limit+1);

vector<vector<ll>> divisors(limit);

ll modpow(ll x, ll n){
    ll res = 1;
    while(n > 0){
        if(n%2){
            res = (res*x)%M;
            n--;
        } else {
            x = (x*x)%M;
            n /= 2;
        }
    }
    return res;
}

void init(){
    factorials[0] = factorials[1] = 1;
    loop(i, 2, limit) factorials[i] = (i*factorials[i-1])%M;
    inv_factorials[limit] = modpow(factorials[limit],M-2)%M;
    for(ll i = limit-1; i >= 0; --i) inv_factorials[i] = ((i+1)*inv_factorials[i+1])%M;

    loop(d,1,limit){
        for(ll m = d; m <= limit; m += d){
            divisors[m].push_back(d);
        }
    }
}

void solve(ll n, ll k){
    vector<ll> sum_res(21,1);
    loop(i, 1, 20){
        if(i > n){
            sum_res[i] = 0;
            continue;
        }
        loop(j, n-i+1, n+1) sum_res[i] = (sum_res[i]*j)%M;
        sum_res[i] = (sum_res[i]*inv_factorials[i+1])%M;
    }

    vector<vector<ll>> dp(k+1, vector<ll>(17));
    loop(i, 2, k) dp[i][1] = 1;
    loop(j, 2, 16){
        loop(i, 1, k){
            for(ll d: divisors[i]) if(d != 1) dp[i][j] += dp[i/d][j-1];
        }
    }

    loop(i, 1, k){
        ll res = (i == 1) ? n%M : 0;
        loop(j, 1, 16){
            res = (res+(dp[i][j]*sum_res[j])%M)%M;
        }
        cout << res << " ";
    }
    cout << "\n";
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    init();

    ll t,n,k;
    cin >> t;
    while(t--){
        cin >> k >> n;
        solve(n,k);
    }

    return 0;
}