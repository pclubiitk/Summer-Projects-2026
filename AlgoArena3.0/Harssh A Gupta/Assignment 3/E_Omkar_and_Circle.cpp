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
    vector<ll> b(2*n);
    loop(i, 0, n-1){
        b[i] = a[(2*i)%n];
        b[i+n] = b[i];
    }
    ll size = (n+1)/2;
    ll curr_sum = 0;
    loop(i, 0, size-1) curr_sum += b[i];
    ll res = curr_sum;
    loop(i,size,n+size-1){
        curr_sum += b[i]-b[i-size];
        res = max(res, curr_sum);
    }
    cout << res << "\n";
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll t, n;
    t=1;
    while(t--){
        cin >> n;
        vector<ll> a(n);
        loop(i, 0, n-1) cin >> a[i];
        solve(a, n);
    }
    
    return 0;
}