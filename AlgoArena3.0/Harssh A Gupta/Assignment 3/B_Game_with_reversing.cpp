#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#define loop(i, start, end) for(long long int i = start; i <= end; ++i)
typedef std::string st;
typedef long long int ll;
const ll inf = 9e18;

using namespace std;

void solve(st& s, st& t, ll n){
    ll mismatches = 0, mismatches_rev = 0;
    loop(i, 0, n-1) if(s[i] != t[i]) mismatches++;
    loop(i, 0, n-1) if(s[i] != t[n-i-1]) mismatches_rev++;
    if(mismatches == 0){
        cout << "0\n";
        return;
    }
    if(mismatches_rev == 0){
        cout << "2\n";
        return;
    }
    cout << min(2*mismatches-mismatches%2, 2*mismatches_rev+mismatches_rev%2-1) << "\n";
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    ll t,n;
    st a,b;
    cin >> t;
    while(t--){
        cin >> n;
        cin >> a;
        cin >> b;
        solve(a,b,n);
    }

    return 0;
}