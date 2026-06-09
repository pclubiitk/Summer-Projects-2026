#include <bits/stdc++.h>

using namespace std;


int main(){
    int t;
    cin >> t;
    while(t--){
        vector<vector<int>>dp(20,vector<int>(2));
        string s;
        cin >> s;
        int n = s.size();
        for(int i = n-1; i >= 0; i--){
            int d = s[i] - '0';
            if(i == n-1){
                dp[i][0] = d;
                dp[i][1] = 10-d+1;
                continue;
            }
            dp[i][0] = d + min(dp[i+1][0], dp[i+1][1]);
            dp[i][1] = min(10-d+1+dp[i+1][0], 10-d+1+dp[i+1][1] - 2);
        }
        cout << min(dp[0][0], dp[0][1]) << '\n';
    }    
}
