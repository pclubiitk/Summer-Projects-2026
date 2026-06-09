#include<bits/stdc++.h>
using namespace std;

# define int long long int
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    vector<int> vec(n);
    for (int i = 0; i < n; i++)
    {
            cin>>vec[i];
    }
    
    vector<vector<int>> dp(n,vector<int>(n,1e9));
    for (int i = 0; i < n; i++)
    {
        dp[i][i]=1;
    }
    for (int i = 0; i < n-1; i++)
    {
        dp[i][i+1]=1+(vec[i]!=vec[i+1]);
    }
    
    for (int len = 3; len <= n; len++)
    {
        for (int i = 0; i < n-len+1; i++)
        {  
            dp[i][i+len-1]=min(dp[i][i+len-1],dp[i+1][i+len-1]+1);
            if(vec[i]==vec[i+1]){
            dp[i][i+len-1]=min(dp[i][i+len-1],1+dp[i+2][i+len-1]);
            }
            for (int j = i+2; j < i+len-1; j++)
            {
                if(vec[j]==vec[i]){
                    dp[i][i+len-1]=min(dp[i][i+len-1],dp[i+1][j-1]+dp[j+1][i+len-1]);
                }
            }
            if(vec[i+len-1]==vec[i]){
                dp[i][i+len-1]=min(dp[i][i+len-1],dp[i+1][i+len-2]);
            }
        }
        
    }
    cout<<dp[0][n-1]<<endl;
    return 0;
}

