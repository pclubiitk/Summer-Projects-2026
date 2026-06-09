#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9 + 7;
const int MOD = 100000000;

#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define per(i, a, b) for (int i = (b); i >= (a); i--)

#define ll long long
#define int ll
#define vi vector<int>
#define vvi vector<vi>
#define vvvi vector<vvi>
#define ii pair<int, int>
#define pb push_back
#define mp make_pair
#define F first
#define S second

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n1, n2, k1, k2; 
    cin >> n1 >> n2 >> k1 >> k2;

    vvvi dp (n1 + 1, vvi (n2 + 1,vi(2,0)));
    for(int i = 1; i <= k1 && i <= n1; i++){
        dp[i][0][0] = 1;
    }
    for(int i = 1; i <= k2 && i <= n2; i++){
        dp[0][i][1] = 1;
    }

    for(int i = 0; i <= n1; i++){
        for(int j = 0; j <= n2; j++){
            for(int q = 1; q <= k1 && i + q <= n1; q++){
                dp[i+q][j][0] +=  dp[i][j][1];
                dp[i+q][j][0] %= MOD;
            }
            for(int q = 1; q <= k2 && j + q <= n2; q++){
                dp[i][j + q][1] +=  dp[i][j][0];
                dp[i][j + q][1] %= MOD;
            }
        }
    }
    cout << (dp[n1][n2][0] + dp[n1][n2][1]) % MOD << '\n';
    return 0;
}