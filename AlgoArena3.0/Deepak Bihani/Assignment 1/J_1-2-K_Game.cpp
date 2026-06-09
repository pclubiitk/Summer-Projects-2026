#include <bits/stdc++.h>

#include <cstdint>

using namespace std;
typedef long long ll;
// #define long long ll
// #define int long long

void solve() {
    int n, k;
    cin >> n >> k;
    
    if (k % 3 != 0 || k>n) {
        if (n % 3 == 0) {
            cout << "Bob" << "\n";
        }
        else cout << "Alice" << "\n";
    }
    else if (k == 3) {
        if (n % 4 == 0) {
            cout << "Bob" << "\n";
        }
        else cout << "Alice" << "\n";
    }
    else {
        if (n % (k+1) == 0 || (((n) % (k+1))%3 == 0 && n%(k+1)!=k)) {
            cout << "Bob" << "\n";
        }
        else cout << "Alice" << "\n";
    }
}

int32_t main() {
    int t = 1;
    cin >> t;
    while (t--)
        solve();

}
