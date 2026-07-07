#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#define loop(i, start, end) for(long long int i = start; i <= end; ++i)
typedef std::string st;
typedef long long int ll;
const ll inf = 9e18;

using namespace std;

const ll M = 1e8;

void solve(ll n1, ll n2, ll k1, ll k2){
    vector<vector<vector<ll>>> dp(n1+1, vector<vector<ll>>(n2+1, vector<ll>(2)));
    loop(i,1,min(n1,k1)) dp[i][0][0] = 1;
    loop(j,1,min(n2,k2)) dp[0][j][1] = 1;
    loop(i, 0, n1){
        loop(j, 0, n2){
            loop(x,1,min(i,k1)) dp[i][j][0] = (dp[i][j][0]+dp[i-x][j][1])%M;
            loop(y,1,min(j,k2)) dp[i][j][1] = (dp[i][j][1]+dp[i][j-y][0])%M;
        }
    }
    cout << (dp[n1][n2][0]+dp[n1][n2][1])%M << "\n";
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    ll n1,n2,k1,k2;
    cin >> n1 >> n2 >> k1 >> k2;
    solve(n1,n2,k1,k2);

    return 0;
}