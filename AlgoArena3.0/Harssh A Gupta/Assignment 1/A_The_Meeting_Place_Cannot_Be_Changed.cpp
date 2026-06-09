#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#define loop(i, start, end) for(long long int i = start; i <= end; ++i)
typedef std::string st;
typedef long long int ll;
typedef long double ld;
const ll inf = 9e18;

using namespace std;

bool check(vector<ll>& x, vector<ll>& v, ld t){
    ld max_l = -inf, min_r = inf;
    ll n = x.size();
    loop(i, 0, n-1){
        max_l = max(max_l, x[i]-t*v[i]);
        min_r = min(min_r, x[i]+t*v[i]);
    }
    return min_r >= max_l;
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    ll n;
    cin >> n;
    vector<ll> x(n), v(n);
    loop(i, 0, n-1) cin >> x[i];
    loop(i, 0, n-1) cin >> v[i];

    ld low = 0, high = 1e9;
    ld res;
    loop(i, 1, 1000){
        ld mid = low + (high-low)/2;
        bool valid = check(x,v,mid);
        if(valid){
            res = mid;
            high = mid;
        } else low = mid;
    }
    cout << fixed << setprecision(9) << res << "\n";
    return 0;
}
