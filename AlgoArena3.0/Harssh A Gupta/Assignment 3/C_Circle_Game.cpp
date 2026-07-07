#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#define loop(i, start, end) for(long long int i = start; i <= end; ++i)
typedef std::string st;
typedef long long int ll;
const ll inf = 9e18;

using namespace std;

void solve(ll d, ll k){
    ll low = 0, high = d/k;
    ll M = 0;
    while(low <= high){
        ll mid = low + (high-low)/2;
        if(2*k*k*mid*mid <= d*d){
            M = mid;
            low = mid+1;
        } else high = mid-1;
    }
    if(k*k*M*M + k*k*(M+1)*(M+1) > d*d) cout << "Utkarsh\n";
    else cout << "Ashish\n";
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    ll t,d,k;
    cin >> t;
    while(t--){
        cin >> d >> k;
        solve(d,k);
    }

    return 0;
}