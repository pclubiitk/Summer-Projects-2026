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
    ll n,k;
    cin>>n>>k;
    if (k==3) {
        if (n%4==0) {
            cout<<"Bob"<<'\n';
        }
        else {
            cout<<"Alice"<<'\n';
        }
    }
    else {
        if (k%3==0) {
            if ((n%(k+1))%3!=0 || (n%(k+1))==k) {
                cout<<"Alice"<<'\n';
            }
            else {
                cout<<"Bob"<<'\n';
            }
        }
        else {
            if (n%3==0) {
                cout<<"Bob"<<'\n';
            }
            else {
                cout<<"Alice"<<'\n';
            }
        }

    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t=1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
