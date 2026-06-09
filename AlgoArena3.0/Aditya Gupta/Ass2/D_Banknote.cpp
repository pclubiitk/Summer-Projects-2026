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

        string v; cin >> v;
        int ans = 0;
        int n = v.size();
        
        vi down(n + 1,0);
        vi up(n + 1, 0);
        up[0] = 1;
        for(int i = 1; i < v.size() + 1; i++){
            int x = v[i - 1] - '0';
            down[i] = min(down[i - 1] + x, up[i - 1] + 10 - x);
            up[i] = min(down[i - 1] + x + 1, up[i - 1] + 9 - x);
            //cerr << v[i] << '\n';
        }
        cout << down[n] << '\n';
    }
    return 0;
}