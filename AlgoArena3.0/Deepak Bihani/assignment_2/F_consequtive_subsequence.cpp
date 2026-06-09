#include <bits/stdc++.h>

#include <cstdint>

using namespace std;
typedef long long ll;
typedef vector <int> vi;

int cmp (vector<int>&a, vector<int>&b) {
    return a[0]<b[0];
}

ll mod1 = 1000000007;

void solve() {
    int n;
    cin >> n;
    vi a(n);
    for (int i=0; i<n; i++) {
        cin >> a[i];
    }
    std::map<int, int> m;
    m.insert({a[0], 1});
    for (int i=1; i<n; i++) {
        m.insert({a[i], 1});
        if (m.find(a[i]-1) != m.end()) m[a[i]] = max(m[a[i]], m[a[i]-1]+1);
        // cout << i <<" "<<m[a[i]] << "\n";
    }
    int last = a[0];
    for (int i=0; i<n; i++) {
        if (m[a[i]] > m[last]) {
            last = a[i];
        }
    }
    std::stack<int> indx;
    
    cout << m[last]<<"\n";
    
    for (int i=n-1; i>=0; i--) {
        if (last == a[i]){
            indx.push(i);
            last--;
        }
    }
    
    while(!indx.empty()) {
        cout << indx.top() +1 << " ";
        indx.pop();
    }
    
    
}

int32_t main() {
    int t = 1;
    // cin >> t;
    while (t--)
        solve();

}
