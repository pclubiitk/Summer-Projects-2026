#include <bits/stdc++.h>

#include <cstdint>

using namespace std;
typedef long long ll;

struct cmp {
    bool operator()(const vector < int > & a,
        const vector < int > & b) const {
        if (a[0] != b[0]) return a[0] > b[0];
        else return a[1] < b[1];
    }
};

void solve() {
    multiset < vector < int > , cmp > ms;
    int n;
    cin >> n;
    vector < int > v(n);
    int l = 0, r = n - 1;
    ms.insert({
        r - l + 1,
        l,
        r
    });
    int i = 1;
    while (!ms.empty()) {
        l = ( * ms.begin())[1];
        r = ( * ms.begin())[2];
        v[(l + r) / 2] = i++;
        ms.erase(ms.begin());
        int lnew = (l + r) / 2 + 1;
        int rnew = (l + r) / 2 - 1;
        if ((l + r) / 2 != l) ms.insert({
            rnew - l + 1,
            l,
            rnew
        });
        if ((l + r) / 2 != r) ms.insert({
            r - lnew + 1,
            lnew,
            r
        });
        // for (int i = 0; i < n; i++) {
        //     cout << v[i] << " ";
        // }
        // cout << "\n";
    }
    for (int i = 0; i < n; i++) {
        cout << v[i] << " ";
    }
    cout << "\n";
}

int32_t main() {
    int t = 1;
    cin >> t;
    while (t--)
        solve();

}
