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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while(t--){
        ll n, k; cin >> n >> k;
        ll t = 0;
        while(2 * (t * k) * (t * k) <= n * n){
            t++;
        }
        t--;
        ll a = t * k;
        //cerr << a << '\n';
        ll z = a * a + (a + k)*(a + k);
        if(z <= n * n) cout << "Ashish" << '\n';
        else cout << "Utkarsh" << '\n';
    }
    return 0;
}