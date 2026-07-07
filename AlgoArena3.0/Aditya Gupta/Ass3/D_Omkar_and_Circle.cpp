#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9 + 7;
const int MOD = 1000000007;

#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define per(i, a, b) for (int i = (b); i >= (a); i--)

#define ll long long
#define vi vector<ll>
#define vvi vector<vi>
#define ii pair<int, int>
#define pb push_back
#define mp make_pair
#define F first
#define S second

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    vi a(2 * n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
        a[i + n] = a[i];
    }
    vi pre(2 * n + 1, 0);
    for(int i = 2; i <= 2 * n; i++){
        pre[i] = pre[i - 2] + a[i - 2];
    }

    ll ans = 0;
    for (int s = 0; s < n; s++){
        ll cur = pre[s + n + 1] - pre[s];
        ans = max(ans, cur);
    }
    cout << ans << '\n';
    return 0;
}