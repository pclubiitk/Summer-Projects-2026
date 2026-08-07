#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#define loop(i, start, end) for(long long int i = start; i <= end; ++i)
typedef std::string st;
typedef long long int ll;
const ll inf = 9e18;

using namespace std;

void solve(vector<ll>& a, ll n){
    vector<vector<ll>> dp(n+1,vector<ll>(n+1, inf));
    loop(i, 0, n-1) dp[i][i] = 1;
    loop(i, 0, n-2) dp[i][i+1] = 1+(a[i] != a[i+1]);
    loop(i, 0, n){
        loop(j, 0, i-1) dp[i][j] = 0;
    }
    loop(len, 3, n){
        loop(i, 0, n-len){
            ll j = i+len-1;
            dp[i][j] = min(dp[i][j], 1+dp[i+1][j]);
            if(a[i] == a[i+1]) dp[i][j] = min(dp[i][j], 1+dp[i+2][j]);
            loop(k, i+2, j){
                if(a[i] == a[k]) dp[i][j] = min(dp[i][j], dp[i+1][k-1]+dp[k+1][j]);
            }
        }
    }
    cout << dp[0][n-1] << "\n";
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    ll n;
    cin >> n;
    vector<ll> a(n);
    loop(i, 0, n-1) cin >> a[i];
    solve(a,n);

    return 0;
}
