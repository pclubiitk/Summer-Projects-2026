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
        int n, k; cin >> n >> k;
        int cnt = 0;
        for(int i = 0; i < n - 1; i++){
            int u, v; 
            cin >> u >> v;
            if(u == k) cnt++;
            if(v == k) cnt++;
        }
        if(cnt < 2) cout << "Ayush" << '\n';
        else{
            if(n % 2) cout << "Ashish" << endl;
            else cout << "Ayush" << '\n';
        }
    }
    return 0;
}