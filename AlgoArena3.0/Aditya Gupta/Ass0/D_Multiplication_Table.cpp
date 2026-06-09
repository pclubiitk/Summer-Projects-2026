#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9 + 7;
const int MOD = 1000000007;

#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define per(i, a, b) for (int i = (b); i >= (a); i--)

#define ll long long
#define vi vector<int>
#define vvi vector<vi>
#define ii pair<int, int>
#define pb push_back
#define mp make_pair
#define F first
#define S second

ll checker(ll check, ll n, ll m){
    ll ans = 0;
    for(int i = 1; i <= n; i++){
        ans += min(m, check / i);
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, m , k; cin >> n >> m >> k;
    ll l = 1, r = n * m;
    ll mid = 0;
    while(l <= r){
        mid = l + (r - l)/2;
        if(checker(mid,n,m) < k) l = mid + 1; 
        else r = mid - 1;
    }
    cout << l << '\n';
    return 0;
}