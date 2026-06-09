#include <bits/stdc++.h>

#include <cstdint>

using namespace std;
typedef long long ll;
typedef vector <int> vi;

ll mod1 = 1000000007;
ll mod2 = 998244353;

void solve() {
    string s;
    cin >> s;
    int n = s.size();
    int carry = 0;
    int cost = 0;
    for (int i=n-1; i>=0; i--) {
        int d = s[i] - '0';
        d+=carry;
        carry = d/10;
        d = d%10;
        cost += min(d, 10-d);
        if (d>10-d) carry++;
        else if (d == 5 && i!=0) {
            int nxt = s[i-1] - '0';
            if (nxt >= 5) carry++;
        }
        
        // cout << min(d, 10-d) << " ";
    }
    cost +=carry;
    cout << cost << "\n";
}

int32_t main() {
    int t = 1;
    cin >> t;
    while (t--)
        solve();

}
