#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <numeric>
#define loop(i, start, end) for(long long int i = start; i <= end; ++i)
typedef std::string st;
typedef long long int ll;
const ll inf = 9e18;

using namespace std;

struct cmp{
    bool operator() (const pair<ll,ll>& a, const pair<ll,ll>& b) const {
        ll a_len = a.second-a.first+1;
        ll b_len = b.second-b.first+1;
        if(a_len == b_len) return a.first > b.first;
        return a_len < b_len;
    }
};

void solve(ll n){
    priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, cmp> pq;
    pq.push({0,n-1});
    vector<ll> a(n);
    loop(i, 1, n){
        pair<ll,ll> p = pq.top(); pq.pop();
        ll l = p.first, r = p.second;
        ll len = r-l+1;
        ll idx = (l+r)/2;
        a[idx] = i;
        if(l != idx) pq.push({l,idx-1});
        if(r != idx) pq.push({idx+1,r});
    }
    for(ll t: a) cout << t << " ";
    cout << "\n";
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    ll t,n;
    cin >> t;
    while(t--){
        cin >> n;
        solve(n);
    }

    return 0;
}