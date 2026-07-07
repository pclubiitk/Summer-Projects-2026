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
    vector<ll> odd_cnt(n), even_cnt(n), sum(n);
    odd_cnt[0] = a[0]%2;
    even_cnt[0] = 1-odd_cnt[0];
    sum[0] = a[0];
    loop(i, 1, n-1){
        odd_cnt[i] = odd_cnt[i-1];
        even_cnt[i] = even_cnt[i-1];
        sum[i] = sum[i-1]+a[i];
        if(a[i]%2) odd_cnt[i]++;
        else even_cnt[i]++;
    }
    loop(i, 0, n-1){
        if(odd_cnt[i]%3 == 0 || odd_cnt[i]%3 == 2) cout << sum[i]-odd_cnt[i]/3 << " ";
        else {
            if(i == 0) cout << a[0] << " ";
            else cout << sum[i]-odd_cnt[i]/3-1 << " ";
        } 
    }
    cout << "\n";
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
