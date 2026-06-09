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
    int n; cin >> n;
    vi a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    map <int,int> dp; int max1 = 0; int max1_ind = 0;
    for(int i = 0; i < n; ++i){
        int cur = a[i];
        dp[cur] = dp[cur - 1] + 1;
        if(dp[cur] > max1){
            max1 = dp[cur];
            max1_ind = i;
        }
    }
    cout << max1 << '\n';
    int q = a[max1_ind];
    vi ans;
    while(max1_ind >= 0){
        //cout << max1_ind + 1<< ' ';
        ans.pb(max1_ind + 1);
        q--;
        while(max1_ind >= 0 && a[max1_ind] != q){
            max1_ind--;
        }
    }
    sort(all(ans));
    for(int i = 0; i < max1; i++){
        cout << ans[i] << ' ';
    }
    return 0;
}