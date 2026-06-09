#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9 + 7;
const int MOD = 1000000007;

#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define per(i, a, b) for (int i = (b); i >= (a); i--)

#define ll long long
#define int ll
#define vi vector<int>
#define vvi vector<vi>
#define ii pair<int, int>
#define pb push_back
#define mp make_pair
#define F first
#define S second

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n; 
    vi freq (1e5 + 1);
    int c;
    for(int i = 0; i < n; i++){
        cin >> c;
        freq[c]++;
    }
    vi dp (1e5 + 1);
    dp[0] = 0;
    dp[1] = freq[1];
    for(int i = 2; i <= 1e5; i++){
        dp[i] += max(i * freq[i] + dp[i - 2], dp[i - 1]);
    }
    cout << dp[1e5] << '\n';
    return 0;
}