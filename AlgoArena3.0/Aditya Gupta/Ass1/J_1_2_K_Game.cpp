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
        int k; cin >> k;
        int c = 0;
        
        int q = 1;
        if(k % 3 == 0){
            int b = n % (k + 1);
            if(b % 3 == 0 && b != k) q = 0;
        }else{
            if(n % 3 == 0) q = 0;
        }

        if(q) cout << "Alice" << '\n';
        else cout << "Bob" << '\n';
    }
    return 0;
}