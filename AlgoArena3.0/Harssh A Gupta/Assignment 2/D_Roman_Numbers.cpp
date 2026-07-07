#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#define loop(i, start, end) for(long long int i = start; i <= end; ++i)
typedef std::string st;
typedef long long int ll;
const ll inf = 9e18;

using namespace std;

vector<ll> factorials(){
    vector<ll> fac(20);
    fac[0] = 1;
    loop(i, 1, 19) fac[i] = i*fac[i-1];
    return fac;
}

void solve(ll n, ll m){
    st s = to_string(n);
    ll len = s.size();
    vector<vector<ll>> dp((1<<len), vector<ll>(m));
    dp[0][0] = 1;
    loop(mask, 0, (1<<len)-1){
        loop(mod, 0, m-1){
            if(dp[mask][mod] == 0) continue;
            loop(i, 0, len-1){
                ll digit = s[i]-'0';
                if(mask == 0 && digit == 0) continue;
                if(mask&(1<<i)) continue;
                ll u = mask|(1<<i);
                ll v = (mod*10+digit)%m;
                dp[u][v] += dp[mask][mod];
            }
        }
    }
    vector<ll> freq(10);
    for(char c: s) freq[c-'0']++;
    ll res = dp[(1<<len)-1][0];
    vector<ll> fac = factorials();
    loop(i, 0, 9) res /= fac[freq[i]];
    cout << res << "\n";
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    ll n,m;
    cin >> n >> m;
    solve(n,m);

    return 0;
}