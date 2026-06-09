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

    int n, k; cin >> n >> k;
    vi a (n,0), b(n,0);
    for(int i = 0; i < n; i++){
        ll x; cin >> x;
        ll y = x;
        while(y % 2 == 0){
            a[i]++;
            y /= 2;
        }
        y = x;
        while(y % 5 == 0){
            b[i]++;
            y /= 5;
        }
    }
    vvi dp (k + 1,vi(27 * n, -INF));
    dp[0][0] = 0;
    for(int ind = 0; ind < n; ind++){
        for(int i = k - 1; i >= 0; i--){
            int q = b[ind];
            for(int j = 0; j < 27 * n - q; j++){
                dp[i + 1][j + q] = max(dp[i + 1][j + q],dp[i][j] + a[ind]);
            }
        }
    } 
    int max1 = 0;
    for(int i = 0; i < 27 * n; i++){
        max1 = max(max1, min(dp[k][i], i));
    }
    cout << max1 << '\n';
    return 0;
}