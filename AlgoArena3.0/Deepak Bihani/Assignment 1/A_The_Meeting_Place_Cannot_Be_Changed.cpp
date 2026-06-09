#include <bits/stdc++.h>

#include <cstdint>

using namespace std;
typedef long long ll;

void solve() {
    ll n;
    cin >> n;
    vector < pair < ll, ll >> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].first;
    }
    for (int i = 0; i < n; i++) {
        cin >> a[i].second;
    }

    double low = 1;
    double high = 1e9;
    double p1 = low + (high - low) / 3;
    double p2 = high - (high - low) / 3;
    double ans = high;
    
    int k = 1000;
    while (k--) {
        double mx1 = 0;
        double mx2 = 0;
        for (int i = 0; i < n; i++) {
            mx1 = max(mx1, abs(a[i].first - p1) / a[i].second);
            mx2 = max(mx2, abs(a[i].first - p2) / a[i].second);
        }
        if (mx2 >= mx1) {
            high = p2;
        }
        else {
            low = p1;
        }
        ans = mx1;
        p1 = low + (high - low) / 3;
        p2 = high - (high - low) / 3;
    }
    cout << fixed << setprecision(15) << ans << "\n";
}

int32_t main() {
    int t = 1;
    // cin >> t;
    while (t--)
        solve();

}
