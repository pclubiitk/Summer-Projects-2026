#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <numeric>
#define loop(i, start, end) for(long long int i = start; i <= end; ++i)
typedef std::string st;
typedef long long int ll;
const ll inf = 9e18;

using namespace std;

void solve(vector<ll>& a, ll n){
    sort(a.begin(), a.end());
    map<ll, ll> freq;
    for(ll t: a) freq[t]++; 
    a.erase(unique(a.begin(), a.end()), a.end());
    ll m = a.size();
    vector<vector<ll>> dp(m+1, vector<ll>(2));
    loop(i, 1, m){
        dp[i][0] = max(dp[i-1][0], dp[i-1][1]);
        dp[i][1] = dp[i-1][0]+(a[i-1]*freq[a[i-1]]);
        if(i >= 2 && a[i-1]-a[i-2] != 1) dp[i][1] = max(dp[i][1], dp[i-1][1]+(a[i-1]*freq[a[i-1]]));
    }
    cout << max(dp[m][0], dp[m][1]) << "\n";
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    ll n;
    cin >> n;
    vector<ll> a(n);
    loop(i, 0, n-1) cin >> a[i];
    solve(a,n);

    return 0;
}