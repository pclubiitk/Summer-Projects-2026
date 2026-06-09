#include <bits/stdc++.h>

using namespace std;

int main(){
    int n,a;
    cin >> n;
    vector<int> arr;
    for(int i = 0; i < n; i++){
        cin >> a;
        arr.push_back(a);
    }
    vector<vector<int>> dp(n+1, vector<int>(n+1,0));
    for(int i = 0; i < n; i++){
        dp[i][i] = 1;
        dp[i][i+1] = (i == n-1) ? 0 : (arr[i] == arr[i+1]) ? 1 : 2;
    }
    for(int j = 2; j < n; j++){
        for(int i = 0; (i+j) < n; i++){
            int k = INT_MAX;
            for(int t = 0; t < j; t++){
                k = min(k,dp[i][i+t] + dp[i+t+1][i+j]);
            }
            if(arr[i] == arr[i+j]) k = min(k,dp[i+1][i+j-1]);
            dp[i][i+j] = k;
            
        }
    }
    int ans = dp[0][n-1];
    cout << ans;

}
