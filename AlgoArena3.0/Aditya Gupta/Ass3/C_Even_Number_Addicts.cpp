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
        int n; cin >> n;
        int even = 0, odd = 0;
        for(int i = 0; i < n; i++){
            int x; cin >> x;
            if(abs(x) % 2) odd++;
            else even++;
        }
        int k = odd % 4;
        if(k == 0 || k == 3) cout << "Alice" << '\n';
        else if(k == 2) cout << "Bob" << '\n';
        else{
            if(even % 2) cout << "Alice" << '\n';
            else cout << "Bob" << '\n';
        }
    }
    return 0;
}