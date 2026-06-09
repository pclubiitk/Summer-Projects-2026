#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#define loop(i, start, end) for(long long int i = start; i <= end; ++i)
typedef std::string st;
typedef long long int ll;
const ll inf = 9e18;

using namespace std;

ll best_sum(vector<ll>& diff_a, vector<ll>& diff_b, ll l1, ll r1, ll k){
    ll n = diff_a.size()-1;
    ll m = diff_b.size()-1;
    ll left = l1, right = r1;
    while(left < right){
        ll mid = left + (right-left)/2;
        if(diff_a[mid]+diff_b[k-mid] < diff_a[mid+1]+diff_b[k-mid-1]) left = mid+1;
        else right = mid;
    }
    return diff_a[left]+diff_b[k-left];
}

void solve(vector<ll>& a, vector<ll>& b, ll n, ll m){
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    vector<ll> pref_a(n+1), suff_a(n+1), pref_b(m+1), suff_b(m+1);
    loop(i, 0, n-1) pref_a[i+1] = pref_a[i]+a[i];
    loop(i, 0, m-1) pref_b[i+1] = pref_b[i]+b[i];
    loop(i, 0, n-1) suff_a[i+1] = suff_a[i]+a[n-i-1];
    loop(i, 0, m-1) suff_b[i+1] = suff_b[i]+b[m-i-1];
    vector<ll> diff_a(n+1), diff_b(m+1);
    loop(i, 0, n) diff_a[i] = suff_a[i]-pref_a[i];
    loop(i, 0, m) diff_b[i] = suff_b[i]-pref_b[i];
    vector<ll> res;
    loop(k, 1, n){
        ll l1 = max(0LL, 2*k-m);
        ll r1 = min(k, n-k);
        if(r1 < l1) break;
        res.push_back(best_sum(diff_a,diff_b,l1,r1,k));
    }
    cout << res.size() << "\n";
    for(ll t: res) cout << t << " ";
    cout << "\n";
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    ll t,n,m;
    cin >> t;
    while(t--){
        cin >> n >> m;
        vector<ll> a(n), b(m);
        loop(i, 0, n-1) cin >> a[i];
        loop(i, 0, m-1) cin >> b[i];
        solve(a,b,n,m);
    }

    return 0;
}