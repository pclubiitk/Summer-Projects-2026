#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <queue>
#define loop(i, start, end) for(long long int i = start; i <= end; ++i)
typedef std::string st;
typedef long long int ll;
const ll inf = 9e18;

using namespace std;

ll pairs(vector<ll>& a, ll n, ll threshold){
    ll res = 0;
    loop(i, 0, n-1){    
        ll j = lower_bound(a.begin(), a.end(), threshold-a[i])-a.begin();
        res += n-j;
    }
    return res;
}

void solve(vector<ll>& a, ll n, ll m){
    sort(a.begin(), a.end());
    vector<ll> prefix(n+1);
    loop(i, 0, n-1) prefix[i+1] = prefix[i]+a[i];

    ll low = 2, high = 200000;
    ll x = 2;
    while(low <= high){
        ll mid = low + (high-low)/2;
        ll P = pairs(a,n,mid);
        if(P >= m){
            x = mid;
            low = mid+1;
        } else high = mid-1;
    }
    ll res = 0, res_cnt = 0;
    loop(i, 0, n-1){
        ll j = lower_bound(a.begin(), a.end(), x+1-a[i])-a.begin();
        ll len = n-j;
        res_cnt += len;
        res += a[i]*len+prefix[n]-prefix[j];
    }
    res += (m-res_cnt)*x;
    cout << res << "\n";
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    ll n,m;
    cin >> n >> m;
    vector<ll> a(n);
    loop(i, 0, n-1) cin >> a[i];
    solve(a,n,m);

    return 0;
}