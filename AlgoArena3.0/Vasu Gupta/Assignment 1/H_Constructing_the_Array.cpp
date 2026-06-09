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

struct cmp {
    bool operator()(pair<ll,ll> a, pair<ll,ll> b) const {
        if (a.second-a.first+1>b.second-b.first+1) {
            return true;
        }
        else if (a.second-a.first+1<b.second-b.first+1) {
            return false;
        }
        else {
            if (a.second<b.second) {
                return true;
            }
            else {
                return false;
            }
        }
    }
};

void solve() {
    ll n;
    cin>>n;
    vector<ll> num(n+1,0);
    set<pair<ll,ll>,cmp> aura;
    aura.insert({1,n});
    ll i=1;
    while (!aura.empty()) {
        pair<ll,ll> curr = (*aura.begin());
        aura.erase(aura.begin());
        if ((curr.second-curr.first+1)%2==1) {
            num[(curr.second+curr.first)/2]=i;
            if ((curr.second+curr.first)/2-1>=curr.first) {
                aura.insert({curr.first,(curr.second+curr.first)/2-1});
            }
            if ((curr.first+curr.second)/2+1<=curr.second) {
                aura.insert({(curr.first+curr.second)/2+1,curr.second});
            }
        }
        else {
            num[(curr.second+curr.first-1)/2]=i;
            if ((curr.second+curr.first-1)/2-1>=curr.first) {
                aura.insert({curr.first,(curr.second+curr.first-1)/2-1});
            }
            if ((curr.first+curr.second-1)/2+1<=curr.second) {
                aura.insert({(curr.first+curr.second-1)/2+1,curr.second});
            }
        }
        i++;
    }
    for (int i=1;i<=n;i++) {
        cout<<num[i]<<" ";
    }
    cout<<'\n';
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
