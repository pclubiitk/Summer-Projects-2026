#include <bits/stdc++.h>
#include <cstdint>

using namespace std;
// #define long long ll
// #define int long long

void solve() {
    string t, p;
    cin >> t >> p;
    int n = t.length();
    vector<int> v(n);
    for (int i=0; i<n; i++) {
        cin >> v[i];
    }
    int high = n - 1;
    int low = 0;
    int mid = low + (high - low)/2;
    
    int ans = -1;
    while (high >= low){
        //which are crossed out?
        vector<int> boo(n, 1);
        for(int i=0; i<=mid; i++) {
            boo[v[i] - 1] = 0;
            
        }
        // cout << mid << "\n";
        //is mid valid
        int k = 0;
        for (int i=0; i<n  && k < p.length(); i++) {
            // cout << boo[i];
            if(boo[i] && t[i] == p[k]) {
                k++;
            }
            
        }
        if (k == p.length()) {
            low = mid + 1;
            ans = mid;
        }
        else {
            high = mid - 1;
        }
        mid = low + ( high - low ) /2;
        // printf("\n");
    }
    
    cout << ans + 1 << '\n';
}

int32_t main() {
    int t = 1;
    // cin >> t;
    while (t--)
        solve();

}
