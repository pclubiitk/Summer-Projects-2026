#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#define loop(i, start, end) for(long long int i = start; i <= end; ++i)
typedef std::string st;
typedef long long int ll;
const ll inf = 9e18;

using namespace std;

void solve(ll h, ll w, ll xa, ll ya, ll xb, ll yb){
    if(xa >= xb){
        cout << "Draw\n";
        return;
    }
    ll dx = xb-xa;
    if(dx%2){
        ll step_a = (dx+1)/2;
        ll step_b = (dx-1)/2;
        if(max(1LL, ya-step_a) <= max(1LL, yb-step_b) && min(w, ya+step_a) >= min(w, yb+step_b)) cout << "Alice\n";
        else cout << "Draw\n";
    } else {
        ll step_a = dx/2;
        ll step_b = dx/2;
        if(max(1LL, yb-step_b) <= max(1LL, ya-step_a) && min(w, yb+step_b) >= min(w, ya+step_a)) cout << "Bob\n";
        else cout << "Draw\n";
    }
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    ll t,h,w,xa,ya,xb,yb;
    cin >> t;
    while(t--){
        cin >> h >> w >> xa >> ya >> xb >> yb;
        solve(h,w,xa,ya,xb,yb);
    }

    return 0;
}