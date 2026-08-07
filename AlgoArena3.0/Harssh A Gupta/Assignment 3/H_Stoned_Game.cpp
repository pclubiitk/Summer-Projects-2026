#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#define loop(i, start, end) for(long long int i = start; i <= end; ++i)
typedef std::string st;
typedef long long int ll;
const ll inf = 9e18;

using namespace std;

void solve(vector<ll>& a, ll n){
    ll sum = accumulate(a.begin(), a.end(), 0LL);
    ll M = *max_element(a.begin(), a.end());
    if(sum%2 || 2*M > sum) cout << "T\n";
    else cout << "HL\n";
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    ll t, n;
    cin >> t;
    while(t--){
        cin >> n;
        vector<ll> a(n);
        loop(i, 0, n-1) cin >> a[i];
        solve(a, n);
    }

    return 0;
}