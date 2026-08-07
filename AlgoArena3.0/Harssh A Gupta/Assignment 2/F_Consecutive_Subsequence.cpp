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
    map<ll, ll> dp;
    ll max_len = 0;
    ll last_val = 0;
    loop(i, 0, n-1){
        dp[a[i]] = max(dp[a[i]], dp[a[i]-1]+1);
        if(dp[a[i]] > max_len){
            max_len = dp[a[i]];
            last_val = a[i];
        }
    }
    ll curr = last_val-max_len+1;
    vector<ll> res;
    loop(i, 0, n-1){
        if(a[i] == curr){
            res.push_back(i+1);
            curr++;
            if(curr > last_val) break;
        }
    }
    cout << max_len << "\n";
    for(ll t: res) cout << t << " ";
    cout << "\n";
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