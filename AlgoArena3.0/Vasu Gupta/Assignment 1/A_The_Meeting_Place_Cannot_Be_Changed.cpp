#include <bits/stdc++.h>
using namespace std;
using ll = long long;

long double min(long double a, long double b) {
    if (a<b) {
        return a;
    }
    else {
        return b;
    }
}

long double max(long double a, long double b) {
    if (a>b) {
        return a;
    }
    else {
        return b;
    }
}

void solve() {
    ll n;
    cin>>n;
    vector<ll> pos(n+1);
    for (int i=1;i<=n;i++) {
        cin>>pos[i];
    }
    vector<ll> speed(n+1);
    for (int i=1;i<=n;i++) {
        cin>>speed[i];
    }
    long double min = 0.00000000;
    long double max = 1000000000.0000000000;
    long double best = 1000000000.000000000;

    while (min<=max) {
        long double mid = min+((max-min)/2);
        bool isitallowed=true;
        pair<long double,long double> allowed{1,1000000000};
        for (int i=1;i<=n;i++) {
            long double right = pos[i]+speed[i]*mid;
            long double left = pos[i]-speed[i]*mid;
            if (right>1000000000.00000) {
                right=1000000000.00000;
            }
            if (left<1) {
                left=1;
            }
            if (allowed.second>right) {
                allowed.second=right;
            }
            if (allowed.first<left) {
                allowed.first=left;
            }
            if (allowed.first>allowed.second) {
                isitallowed=false;
                break;
            }
        }
        if (isitallowed) {
            if (mid<best) {
                best=mid;
            }
            max=mid-0.0000001;
        }
        else {
            min=mid+0.0000001;
        }
    }
    cout<<fixed<<setprecision(10)<<best<<'\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t=1;
    //cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
