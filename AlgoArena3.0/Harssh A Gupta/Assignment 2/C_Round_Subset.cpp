#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#define loop(i, start, end) for(long long int i = start; i <= end; ++i)
typedef std::string st;
typedef long long int ll;
const ll inf = 9e18;

using namespace std;

const ll M = 1e9+7;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    ll n,k;
    cin >> n >> k;
    vector<ll> a(n);
    loop(i, 0, n-1) cin >> a[i];
    vector<ll> val2(n), val5(n);
    loop(i, 0, n-1){
        ll temp1 = a[i], temp2 = a[i];
        while(temp1%2 == 0){
            val2[i]++;
            temp1 /= 2;
        }
        while(temp2%5 == 0){
            val5[i]++;
            temp2 /= 5;
        }
    }
    ll sum2 = accumulate(val2.begin(), val2.end(), 0LL);
    ll sum5 = accumulate(val5.begin(), val5.end(), 0LL);
    if(sum5 > sum2){
        swap(val2,val5);
        swap(sum2,sum5);
    }
    vector<vector<ll>> dp(k+1, vector<ll>(sum5+1,-1));
    dp[0][0] = 0;
    loop(i, 0, n-1){
        for(ll j = k; j >= 1; --j){
            for(ll s = sum5; s >= val5[i]; --s){
                if(dp[j-1][s-val5[i]] != -1) dp[j][s] = max(dp[j][s], dp[j-1][s-val5[i]]+val2[i]);
            }
        }
    }
    ll res = -1;
    loop(i, 0, sum5){
        if(dp[k][i] != -1) res = max(res, min(i,dp[k][i]));
    }
    cout << res << "\n";
    
    return 0;
}  