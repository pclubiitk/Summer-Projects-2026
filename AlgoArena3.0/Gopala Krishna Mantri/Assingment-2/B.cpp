#include<bits/stdc++.h>
#include<vector>
 
using namespace std;

const int MOD = 1e8;
 
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

int ncr(int n, int r){

    r = min(r, n - r);

    if(r < 0 || r > n){return 0;}

    int ret = 1;
    for(int i = 1; i <= r; i++){

        ret = mul(ret, n + 1 - i);
        ret = div_(ret, i);

    }

    return ret;

}

void solve()
{

    int n1, n2, k1, k2; cin >> n1 >> n2 >> k1 >> k2;

    int temp = n2;
    n2 = min(n1, n2);
    vector<vector<vector<int>>> dp(n1 + 1, vector<vector<int>>(n2 + 1, vector<int>(2, 0)));
    dp[n1][n2][1] = 1;
    dp[n1][n2][0] = 1;

    for(int i = n1 + n2; i > 0; i--){

        //for(int j = max(0, i - n2); j >= max(0, i - n2);

    }

}
 
int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);    

    int t = 1;
    //int t; cin >> t;
    for(int i = 0; i < t; i++) {solve();}

    return 0;

}