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
        ll sum = 0;
        int odd = 0;
        for(int i = 1; i <= n; i++){
            int c; cin >> c;
            sum += c;

            if(c % 2) odd++;
            int sub = 0;
            if(odd % 3 == 1 && i > 1) sub = 1;
            cout << sum - (odd / 3) - sub << ' ';
        }
        cout << '\n';
    }
    return 0;
}