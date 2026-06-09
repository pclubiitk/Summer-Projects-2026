#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9 + 7;
const int MOD = 1000000007;

#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define per(i, a, b) for (int i = (b); i >= (a); i--)

#define ll long long
#define vi vector<int>
#define vvi vector<vi>
#define ii pair<int, int>
#define pb push_back
#define mp make_pair
#define F first
#define S second

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;
    vi a (n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    vvi dp (n + 1,vi (n,0));

    for(int i = 0; i < n; i++){
        dp[i][i] = 1;
    }

    for(int len = 2; len <= n; len++){
        for(int l = 0; l + len - 1 < n; l++){
            int r = l + len - 1;
            dp[l][r] = INF;
            if(a[l] == a[r]){
                if(len == 2) dp[l][r] = 1;
                else dp[l][r] = dp[l + 1][r - 1];
            }
            for(int k = l; k < r; k++){
                int q = dp[l][k] + dp[k + 1][r];
                dp[l][r] = min(dp[l][r],q);
            }
        }
    }
    cout << dp[0][n - 1] << '\n';
    return 0;
}