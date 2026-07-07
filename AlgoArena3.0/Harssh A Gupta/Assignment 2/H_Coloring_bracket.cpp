#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
#include <numeric>
#define loop(i, start, end) for(long long int i = start; i <= end; ++i)
typedef std::string st;
typedef long long int ll;
const ll inf = 9e18;

using namespace std;

const ll M = 1e9+7;

vector<vector<vector<vector<ll>>>> dp(705, vector<vector<vector<ll>>>(705, vector<vector<ll>>(3, vector<ll>(3,-1))));

ll solve(ll l, ll r, ll c1, ll c2, vector<ll>& match){
    if(dp[l][r][c1][c2] != -1) return dp[l][r][c1][c2];
    if(l+1 == r){
        if(c1 == c2 || c1*c2) return 0;
        return 1;
    }
    ll k = match[l];
    ll res = 0;
    if(k == r){
        if(c1 == c2 || c1*c2) return 0;
        loop(d1, 0, 2){
            loop(d2, 0, 2){
                if((c1 != 0 && d1 == c1) || (c2 != 0 && d2 == c2)) continue;
                res = (res+solve(l+1,r-1,d1,d2,match))%M;
            }
        }
    } else {
        loop(d1, 0, 2){
            loop(d2, 0, 2){
                if(d1 != 0 && d1 == d2) continue;
                res = (res+(solve(l,k,c1,d1,match)*solve(k+1,r,d2,c2,match))%M)%M;
            }
        }
    }
    dp[l][r][c1][c2] = res;
    return res;
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    st s;
    cin >> s;
    ll n = s.size();
    stack<ll> st;
    vector<ll> match(n);
    loop(i, 0, n-1){
        if(s[i] == '(') st.push(i);
        else {
            ll idx = st.top();
            st.pop();
            match[i] = idx;
            match[idx] = i;
        }
    }

    ll res = 0;
    loop(i, 0, 2){
        loop(j, 0, 2){
            res = (res+solve(0,n-1,i,j,match))%M;
        }
    }
    cout << res << "\n";

    return 0;
}