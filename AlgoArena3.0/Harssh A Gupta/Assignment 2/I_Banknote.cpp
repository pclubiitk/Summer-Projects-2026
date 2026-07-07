#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#define loop(i, start, end) for(long long int i = start; i <= end; ++i)
typedef std::string st;
typedef long long int ll;
const ll inf = 9e18;

using namespace std;

void solve(st& s){
    ll n = s.size();
    vector<pair<ll,ll>> dp(n+1);
    dp[0].second = inf;
    loop(i, 1, n){
        ll d = s[n-i]-'0';
        dp[i].first = min(dp[i-1].first+d, dp[i-1].second+d+1);
        dp[i].second = min(dp[i-1].first+(10-d), dp[i-1].second+(9-d));
    }
    cout << min(dp[n].first, dp[n].second+1) << "\n";
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    ll t;
    st s;
    cin >> t;
    while(t--){
        cin >> s;
        solve(s);
    }

    return 0;
}