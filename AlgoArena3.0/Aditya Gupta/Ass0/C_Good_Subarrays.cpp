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
        int n; cin >> n;
        string k; cin >> k;
        vi prefix (n + 1);
        prefix[0] = 0;
        for(int i = 0; i < n; i++){
            prefix[i + 1] = prefix[i] + k[i] - '0';
        }
        
        ll ans = 0;
        map <ll,ll> apple;
        apple[0] = 1;
        for(int i = 1; i < n + 1; i++){
            int v = prefix[i] - i;
            ans += apple[v]++;
        }
        cout << ans << '\n';
    }
    return 0;
}