#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#define loop(i, start, end) for(long long int i = start; i <= end; ++i)
typedef std::string st;
typedef long long int ll;
const ll inf = 9e18;

using namespace std;

//& 0 -> (0,0) to (i,j)
//& 1 -> (i,j) to (n-1,m-1)
//& 2 -> (n-1,0) to (i,j)
//& 3 -> (i,j) to (0,m-1)

void solve(vector<vector<ll>>& gym, ll n, ll m){
    vector<vector<vector<ll>>> dp(n, vector<vector<ll>>(m, vector<ll>(4)));
    dp[0][0][0] = gym[0][0];
    loop(i, 0, n-1){
        loop(j, 0, m-1){
            if(j > 0) dp[i][j][0] = dp[i][j-1][0]+gym[i][j];
            if(i > 0) dp[i][j][0] = max(dp[i][j][0], dp[i-1][j][0]+gym[i][j]);
        }
    }
    dp[n-1][m-1][1] = gym[n-1][m-1];
    for(ll i = n-1; i >= 0; --i){
        for(ll j = m-1; j >= 0; --j){
            if(j < m-1) dp[i][j][1] = dp[i][j+1][1]+gym[i][j];
            if(i < n-1) dp[i][j][1] = max(dp[i][j][1], dp[i+1][j][1]+gym[i][j]);
        }
    }
    dp[n-1][0][2] = gym[n-1][0];
    for(ll i = n-1; i >= 0; --i){
        loop(j, 0, m-1){
            if(j > 0) dp[i][j][2] = dp[i][j-1][2]+gym[i][j];
            if(i < n-1) dp[i][j][2] = max(dp[i][j][2], dp[i+1][j][2]+gym[i][j]);
        }
    }
    dp[0][m-1][3] = gym[0][m-1];
    loop(i, 0, n-1){
        for(ll j = m-1; j >= 0; --j){
            if(j < m-1) dp[i][j][3] = dp[i][j+1][3]+gym[i][j];
            if(i > 0) dp[i][j][3] = max(dp[i][j][3], dp[i-1][j][3]+gym[i][j]); 
        }
    }
    ll res = -1;
    loop(i, 1, n-2){
        loop(j, 1, m-2){
            res = max(res, dp[i-1][j][0]+dp[i+1][j][1]+dp[i][j-1][2]+dp[i][j+1][3]);
            res = max(res, dp[i][j-1][0]+dp[i][j+1][1]+dp[i+1][j][2]+dp[i-1][j][3]);
        }
    }
    cout << res << "\n";
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    ll n,m;
    cin >> n >> m;
    vector<vector<ll>> gym(n, vector<ll>(m));
    loop(i, 0, n-1){
        loop(j, 0, m-1) cin >> gym[i][j];
    }
    solve(gym,n,m);

    return 0;
}