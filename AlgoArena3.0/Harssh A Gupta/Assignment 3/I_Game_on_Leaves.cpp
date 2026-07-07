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
    
    ll t,n,x;
    cin >> t;
    while(t--){
        cin >> n >> x;
        vector<ll> degree(n+1);
        loop(i, 1, n-1){
            ll a,b;
            cin >> a >> b;
            degree[a]++;
            degree[b]++;
        }
        if(degree[x] == 1) cout << "Ayush\n";
        else {
            if(n%2) cout << "Ashish\n";
            else cout << "Ayush\n";
        }
    }

    return 0;
}