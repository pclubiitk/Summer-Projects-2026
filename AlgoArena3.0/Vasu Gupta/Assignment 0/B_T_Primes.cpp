#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    cin >> t;
    set<ll> primessquared;
    vector<bool> visited(1000001,true);
    for (ll i=2;i<1000001;i++) {
        if (visited[i]==true) {
            for (ll j=2*i;j<1000001;j=j+i) {
                visited[j]=false;
            }
        }
    }
    for (ll i=2;i<1000001;i++) {
        if (visited[i]) {
            primessquared.insert(i*i);
        }
    }
    while (t--) {
        ll a;
        cin>>a;
        if (primessquared.find(a)!=primessquared.end()) {
            cout<<"YES"<<'\n';
        }
        else {
            cout<<"NO"<<'\n';
        }
    }

    return 0;
}
