#include <bits/stdc++.h>

#include <cstdint>

using namespace std;
typedef long long ll;
// #define long long ll
// #define int long long

void solve() {
    ll n, m;
    cin >> n >> m;
    vector < ll > v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end(), std::greater < > ());
    vector < ll > pref(n);
    pref[0] = v[0];
    for (int i = 1; i < n; i++) {
        pref[i] = pref[i - 1] + v[i];
    }
    ll high = 2 * v[0];
    ll low = 2 * v[n - 1];
    ll mid = low + (high - low) / 2;
    ll final = 0;
    while (high >= low) {
        ll count = 0;
        ll sum = 0;
        ll countabove = 0;
        ll sumabove = 0;
        for (int i = 0; i < n; i++) {
            ll right = n - 1;
            ll left = 0;
            ll ans = -1;
            ll cent = left + (right - left) / 2;
            
            while (right >= left) {
                
                if (v[cent] + v[i] >= mid) {
                    left = cent + 1;
                    ans = cent;
                }
                else right = cent - 1;
                cent = left + (right - left) / 2;
            }
            if(ans==-1) continue;
            sum += pref[ans] + (ans + 1) * v[i];
            count += ans + 1;
        }
        
        for (int i = 0; i < n; i++) {
            ll right = n - 1;
            ll left = 0;
            ll ans = -1;
            ll cent = left + (right - left) / 2;
            
            while (right >= left) {
                
                if (v[cent] + v[i] > mid) {
                    left = cent + 1;
                    ans = cent;
                }
                else right = cent - 1;
                cent = left + (right - left) / 2;
            }
            if(ans==-1) continue;
            sumabove += pref[ans] + (ans + 1) * v[i];
            countabove += ans + 1;
        }
        
        if (count >= m) {
            low = mid + 1;
            
        }
        else {
            high = mid - 1;
        }
        if (count >=m && m >= countabove) {
            final = sumabove + mid*(m-countabove);
        }
        
        mid = low + (high - low) / 2;
    }
    cout << final;
}

int32_t main() {
    int t = 1;
    // cin >> t;
    while (t--)
        solve();

}
