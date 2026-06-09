#include<bits/stdc++.h>
using namespace std;
# define int long long int


void getdig(int n,vector<int> & dig){
    while(n){
        dig.emplace_back(n%10);
        n/=10;
    }
    reverse(dig.begin(),dig.end());
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin>>T;
    for(int t=0;t<T;t++){
        int n;
        cin>>n;
        vector<int> dig_n;
        getdig(n,dig_n);
        int m=dig_n.size();
    
        vector<vector<int>> dp(m,vector<int>(2));
        dp[0][0]=min(dig_n[0],11-dig_n[0]);
        
        dp[0][1]=min(dig_n[0]+1,10-dig_n[0]);
        
        for (int i = 1; i < m; i++)
        {   if(dig_n[i]==0){
            dp[i][0]=dp[i-1][0];
            int nd=dig_n[i]+1;
            dp[i][1]=min(dp[i-1][0]+nd,dp[i-1][1]+10-nd);
            continue;
            }
            dp[i][0]=min(dp[i-1][0]+dig_n[i],dp[i-1][1]+10-dig_n[i]);
            if(dig_n[i]==9){
                dp[i][1]=dp[i-1][1];
                continue;
            }
            int nd=dig_n[i]+1;
            dp[i][1]=min(dp[i-1][0]+nd,dp[i-1][1]+10-nd);
        }
        cout<<dp[m-1][0]<<endl;
    }
    return 0;
}

