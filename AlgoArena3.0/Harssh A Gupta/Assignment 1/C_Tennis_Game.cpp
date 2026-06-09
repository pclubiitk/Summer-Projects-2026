#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#define loop(i, start, end) for(long long int i = start; i <= end; ++i)
typedef std::string st;
typedef long long int ll;
const ll inf = 9e18;

using namespace std;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    ll n;
    cin >> n;
    vector<ll> a(n);
    loop(i, 0, n-1) cin >> a[i];
    vector<ll> one_idx, two_idx;
    loop(i, 0, n-1){
        if(a[i] == 1) one_idx.push_back(i);
        else two_idx.push_back(i);
    }
    vector<pair<ll,ll>> res;
    loop(t, 1, n){
        ll p1_pts = 0, p2_pts = 0;
        ll p1_sets = 0, p2_sets = 0;
        ll last_winner = -1;
        ll curr_idx = -1;
        bool valid = true;
        while(curr_idx < n-1){
            ll t1 = p1_pts+t;
            ll t2 = p2_pts+t;
            ll next1 = (t1 <= (ll) one_idx.size()) ? one_idx[t1-1]:inf;
            ll next2 = (t2 <= (ll) two_idx.size()) ? two_idx[t2-1]:inf;
            if(next1 == inf && next2 == inf){
                valid = false;
                break;
            }
            if(next1 < next2){
                p1_sets++;
                curr_idx = next1;
                last_winner = 1;
                p1_pts = t1;
                p2_pts = curr_idx+1-t1;
            } else {
                p2_sets++;
                curr_idx = next2;
                last_winner = 2;
                p2_pts = t2;
                p1_pts = curr_idx+1-t2;
            }
        }
        if(valid && curr_idx == n-1){
            if(last_winner == 1 && p1_sets > p2_sets) res.push_back({p1_sets,t});
            else if(last_winner == 2 && p2_sets > p1_sets) res.push_back({p2_sets,t});
        }
    }
    sort(res.begin(), res.end());
    cout << res.size() << "\n";
    for(auto p: res){
        cout << p.first << " " << p.second << "\n";
    }
    return 0;
}