#include<bits/stdc++.h>
#include<vector>
 
using namespace std;

vector<int> dp(101);

void solve()
{

    int ret = 0;
    long long int n; cin >> n;
    while(n){

        int cur = n%100;
        ret += dp[cur];
        n/=100;
        n += (cur >= 55);

    }
    cout << ret << "\n";

}
 
int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);    

    for(int i = 0; i < 10; i++){

        dp[i] = min(i, 10 - i);

    }

    for(int i = 10; i <= 100; i += 10){

        dp[i] = dp[i/10];

    }

    for(int i = 11; i < 100; i++){

        int l = (i/10)*10;
        int r = l + 10;

        //cout << r << " " << l << "\n";

        dp[i] = min(i - l + dp[l], r - i + dp[r]);

        if(!(i%10)){

            i++;

        }

    }

    int t; cin >> t;
    for(int i = 0; i < t; i++) {solve();}

    return 0;

}