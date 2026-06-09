#include <bits/stdc++.h>
 
#include <cstdint>
 
using namespace std;
typedef long long ll;
typedef vector <ll> vi;
 
ll mod1 = 1000000007;
 
void solve() {
    int n = 100001;
    vi points(n,0);
    int k;
    cin >> k;
    int x;
    for (int i=0; i<k; i++) {
        cin >> x;
        points[x] += x;
    }
    vi dp(n,0);
    dp[0] = 0;
    dp[1] = points[1];
    for (int i=2; i<n; i++) {
        dp[i] = max(dp[i-1], dp[i-2] + points[i]);
    }
    cout << dp[n-1];
}
 
int32_t main() {
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
 
}
