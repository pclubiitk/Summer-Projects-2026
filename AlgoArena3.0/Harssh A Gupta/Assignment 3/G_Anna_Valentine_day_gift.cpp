#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#define loop(i, start, end) for(long long int i = start; i <= end; ++i)
typedef std::string st;
typedef long long int ll;
const ll inf = 9e18;

using namespace std;

void solve(vector<ll>& a, ll n, ll m){
    ll total_digits = 0;
    vector<ll> ending_zeroes;
    loop(i, 0, n-1){
        ll curr = a[i];
        total_digits += to_string(curr).size();
        ll zeroes = 0;
        while(curr%10 == 0){
            curr /= 10;
            zeroes++;
        }
        if(zeroes) ending_zeroes.push_back(zeroes);
    }
    ll removed_cnt = 0;
    sort(ending_zeroes.rbegin(), ending_zeroes.rend());
    loop(i, 0, (ll)ending_zeroes.size()-1){
        if(i%2 == 0) removed_cnt += ending_zeroes[i];
    }
    ll remaining = total_digits-removed_cnt;
    if(remaining > m) cout << "Sasha\n";
    else cout << "Anna\n";
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    ll t,n,m;
    cin >> t;
    while(t--){
        cin >> n >> m;
        vector<ll> a(n);
        loop(i, 0, n-1) cin >> a[i];
        solve(a,n,m);
    }

    return 0;
}