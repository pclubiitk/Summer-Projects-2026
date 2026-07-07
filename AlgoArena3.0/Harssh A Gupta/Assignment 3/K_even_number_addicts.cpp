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
    ll odd_cnt = 0, even_cnt = 0;
    loop(i, 0, n-1){
        if(a[i]%2) odd_cnt++;
        else even_cnt++;
    }
    if(odd_cnt%4 == 0) cout << "Alice\n";
    else if(odd_cnt%4 == 1){
        if(even_cnt%2 == 1) cout << "Alice\n";
        else cout << "Bob\n";
    } else if(odd_cnt%4 == 2) cout << "Bob\n";
    else cout << "Alice\n";
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    ll t, n;
    cin >> t;
    while(t--){
        cin >> n;
        vector<ll> a(n);
        loop(i, 0, n-1) cin >> a[i];
        solve(a, n);
    }

    return 0;
}