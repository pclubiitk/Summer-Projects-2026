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
        int n, m; cin >> n >> m;
        vi a (n);
        vector <ii> dig (n);
        for(int i = 0; i < n; i++){
            int c; cin >> c;
            int k = 1;
            while(c / 10){
                if(c % 10 == 0 && k){
                    dig[i].F++;
                }else k = 0;
                dig[i].S++;
                c /= 10;
            }
            dig[i].S++;
        }
        sort(all(dig));
        int ans = 0;
        for(int i = 0; i < n; i++) ans += dig[i].S;     
        for(int i = n - 1; i >= 0; i -= 2) ans -= dig[i].F;

        if(ans > m) cout << "Sasha" << '\n';
        else cout << "Anna" << '\n';
    }
    return 0;
}