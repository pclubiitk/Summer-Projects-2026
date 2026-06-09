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

    int n; cin >> n;
    vi cost (n);
    for(int i = 0; i < n; i++){
        cin >> cost[i];
    }
    vector <ll> prefix (n + 1);
    prefix[0] = 0;
    for(int i = 1; i < n + 1; i++){
        prefix[i] = prefix[i - 1] + cost[i - 1];
    }
    int m; cin >> m;
    sort(all(cost));

    vector <ll> prefix2 (n + 1);
    prefix2[0] = 0;
    for(int i = 1; i < n + 1; i++){
        prefix2[i] = prefix2[i - 1] + cost[i - 1];
    }

    for(int i = 0; i < m; i++){
        int t,x,y;
        cin >> t >> x >> y;
        //cout << t << '\n';
        if(t == 1){
            cout << prefix[y] - prefix[x - 1] << '\n';
        }else{
            cout << prefix2[y] - prefix2[x - 1] << '\n';
        }
    }
    return 0;
}