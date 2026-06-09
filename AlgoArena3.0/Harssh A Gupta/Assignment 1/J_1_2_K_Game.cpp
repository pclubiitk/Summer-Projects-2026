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
    
    ll t,n,k;
    cin >> t;
    while(t--){
        cin >> n >> k;
        bool alice_win = true;
        if(k%3 == 0){
            ll c = n%(k+1);
            if(c%3 == 0 && c != k) alice_win = false;
        } else if(n%3 == 0) alice_win = false;
        if(alice_win) cout << "Alice\n";
        else cout << "Bob\n";
    }

    return 0;
}