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
        string s, t; cin >> s >> t;
        int c1 = 0, c2 = 0;
        for(int i = 0; i < n; i++){
            if(s[i] != t[i]) c1++;
            if(s[i] != t[n - i - 1]) c2++;
        }
        //cerr << c1 << c2;
        int a2 = 2 * c2 - 1 + (c2 % 2);
        if(c2 == 0) a2 = 2;
        cout << max(0,min(2* c1 - (c1 % 2), a2)) << '\n';
    }
    return 0;
}