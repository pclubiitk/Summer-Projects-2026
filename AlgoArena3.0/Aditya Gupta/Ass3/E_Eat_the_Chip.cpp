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
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--){
        int h, w, xa, ya, xb, yb;
        cin >> h >> w >> xa >> ya >> xb >> yb;
        bool k = false;
        string winner;

        int diff = xb - xa;
        if(diff < 1){
            cout << "Draw" << '\n';
            continue;
        }

        if(diff % 2){
            xa++;
            if(yb > ya) ya++;
            else if(yb < ya) ya--;

            diff--;

            int wid = 0;
            if(ya < yb) wid = w - ya;
            else wid = ya - 1;
            if(ya == yb || diff >= 2 * wid){
                cout << "Alice" << '\n';
            }else{
                cout << "Draw" << '\n';
            }
        }else{
            int wid = 0;
            if(ya < yb) wid = yb - 1;
            else wid = w - yb;
            if(ya == yb || diff >= 2 * wid){
                cout << "Bob" << '\n';
            }else{
                cout << "Draw" << '\n';
            }
        }
    }

    return 0;
}