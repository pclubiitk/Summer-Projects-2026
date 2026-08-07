#include<bits/stdc++.h>
using namespace std;

# define int long long int
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,k;
    cin>>n>>k;
    vector<int> vec(n);
    for (int i = 0; i < n; i++)
    {
        cin>>vec[i];
    }
    vector<vector<int>> exp(n,vector<int> (2));
    for (int i = 0; i < n; i++)
    {
        while(vec[i]%2==0){
            vec[i]/=2;
            exp[i][0]++;
        }
        while(vec[i]%5==0){
            vec[i]/=5;
            exp[i][1]++;
        }
    }
    const int p=30*200;
    vector<vector<int>> dp(k+1,vector<int>(p,-1));
    dp[0][0]=0;
    
    for (int i = 1; i < n+1; i++)
    {
        for (int l = k; l >0; l--)
        {
            for (int m = p-1; m >-1 ; m--)
            {   if(m-exp[i-1][1]>=0&&dp[l-1][m-exp[i-1][1]]!=-1){
                dp[l][m]=max(dp[l][m],dp[l-1][m-exp[i-1][1]]+exp[i-1][0]);
                }
                else{
                    dp[l][m]=dp[l][m];
                }
            }
        }
    }
    int ans=-1;
    for (int i = 0; i < p; i++)
    {
        ans=max(ans,min(dp[k][i],i));
    }
    cout<<ans<<endl;
    
    return 0;
}