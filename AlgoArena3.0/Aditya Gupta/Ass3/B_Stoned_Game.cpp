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
        int max1 = 0;
        int sum = 0;
        for(int i = 0; i < n; i++){
            int c; cin >> c;
            max1 = max(max1,c);
            sum += c;
        }
        if(max1 * 2 > sum){
            cout << "T" << '\n';
            continue;
        }
        //cerr << max1 << '\n';
        if(sum % 2 == 0) cout << "HL" << '\n';
        else cout << "T" << '\n';
    }
    return 0;
}