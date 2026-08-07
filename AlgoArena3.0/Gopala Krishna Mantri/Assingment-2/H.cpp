#include<bits/stdc++.h>
#include<vector>
 
using namespace std;

const int MOD = 1e9 + 7;
 
int add(int x, int y)
{
    x += y;
    if(x >= MOD) x -= MOD;
    if(x < 0) x += MOD;
    return x;
}
 
int sub(int x, int y)
{
    return add(x, -y);
}
 
int mul(int x, int y)
{
    return (x * 1ll * y) % MOD;
}   
 
int binpow(int x, int y)
{
    int z = 1;
    while(y > 0)
    {
        if(y % 2 == 1) z = mul(z, x);
        x = mul(x, x);
        y /= 2;
    }
    return z;
}    

int inv(int b){

    return binpow(b, MOD - 2)%MOD;

}

int div_(int a, int b){

    int inverse = inv(b);
    return mul(a, inverse);

}

vector<int> c1(701);
vector<int> c2(701);

void df(int curidx, vector<vector<int>> &children, vector<int> &dp, bool start){

    if(start){

        if(children[curidx].size() == 1){
            df(children[curidx][0], children, dp, false);
            dp[curidx] = mul(3, div_(dp[children[curidx][0]], 2));  
        }

        else{

            int cur = 1;
            for(int child : children[curidx]){
                df(child, children, dp, false);
                cur = mul(cur, dp[child]);
                dp[curidx] = mul(add(c1[children[curidx].size()] , c2[children[curidx].size()]), mul(cur, 3));
            }

        }

        return;

    }

    if(children[curidx].size() == 0){
        dp[curidx] = 2;
    }

    if(children[curidx].size() == 1){
        df(children[curidx][0], children, dp, false);
        dp[curidx] = mul(2, dp[children[curidx][0]]);  
    }

    else{

        int cur = 1;
        for(int child : children[curidx]){
            df(child, children, dp, false);
            cur = mul(cur, dp[child]);
            dp[curidx] = mul(add(c1[children[curidx].size()] , c2[children[curidx].size()]), cur);
        }

    }

    return;

}

void solve()
{

    string s; cin >> s;
    int n = s.size();

    vector<vector<int>> children(n + 1);
    stack<int> q; q.push(n);
    vector<int> dp(n+1);
    for(int i = 0; i < n; i++){

        if(s[i] == '('){

            children[q.top()].push_back(i);
            q.push(i);

        }
        else{

            q.pop();

        }

    }
    df(n, children, dp, true);
    cout << dp[n] << "\n";

}
 
int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);    

    c1[1] = 2;
    c2[1] = 0;
    c1[2] = 2;
    c2[2] = 1;
    c1[3] = 4;
    c2[3] = 2;
    for(int i = 4; i <= 700; i++){

        c1[i] = mul(2, add(c2[i-2], c1[i-2]));
        c2[i] = mul(2, add(div_(c1[i-2], 2), mul(div_(c2[i-2], 2), 3)));

    }

    int t = 1;
    //int t; cin >> t;
    for(int i = 0; i < t; i++) {solve();}

    return 0;

}