#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#define loop(i, start, end) for(long long int i = start; i <= end; ++i)
typedef std::string st;
typedef long long int ll;
const ll inf = 9e18;

using namespace std;

bool check(st& t, st& p, vector<ll>& a, ll query){
    ll n = t.size();
    vector<bool> removed(n);
    loop(i, 0, query-1) removed[a[i]-1]=true;
    ll j = 0;
    ll m = p.size();
    loop(i, 0, n-1){
        if(!removed[i] && t[i]==p[j]){
            ++j;
            if(j == m) return true;
        }
    }
    return j==m;
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    st t,p;
    cin >> t >> p;
    ll n = t.size();
    vector<ll> a(n);
    loop(i, 0, n-1) cin >> a[i];
    ll low = 0, high = n;
    ll res = 0;
    while(low <= high){
        ll mid = low + (high-low)/2;
        if(check(t,p,a,mid)){
            res = mid;
            low = mid+1;
        } else high = mid-1;
    }
    cout << res << "\n";

    return 0;
}