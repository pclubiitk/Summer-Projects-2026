#include<bits/stdc++.h>
using namespace std;
#define M 998244353
# define int long long int
int power(int l,int  r){
    int a=1;
    int exp=l;
    while(r){
        if(r%2){
            a*=exp;a%=M;
        }
        exp*=exp;exp%=M;
        r/=2;
    }
    return a;
}
int inv(int r){
    return power(r,M-2);
}
int ncr(int n,int j){
    if(j==0){return 1;}
    int num=((n%M)*ncr(n-1,j-1))%M;
    int ans=(num)*inv(j);ans%=M;
    return ans;
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin>>T;
    for(int t=0;t<T;t++){
        int n,k;
        cin>>k>>n;
        vector<vector<int>> dp(k+1,vector<int> (31));
        for (int i = 2; i <= k; i++)
        {
            dp[i][1]=1;
        }
        
        for (int j = 1; j < 30 ; j++)
        {
           for (int i = 2; i < k+1; i++)
           {    
                for (int h = 2; i*h<=k; h++)
                {
                    dp[i*h][j+1]+=dp[i][j];dp[i*h][j+1]%=M;
                }
           }
        }
        // for (int i = 2; i < k+1; i++)
        // {   int ans=0;
        //     for (int j = 1; j < 31; j++)
        //     {
        //             ans+=dp[i][j];
        //     }
        //     cout<<ans<<endl;
        // }
        
        vector<int> perm(32);
        for (int i = 0; i <= min(31ll,n+1); i++)
        {
            perm[i]=ncr(n+1,i);
        }
        cout<<n<<" ";
        for (int i = 2; i < k+1; i++)
        {   int ans=0;
           for (int j = 1; j < min(31ll,n+1); j++)
           {
            int inc=((perm[j+1])*dp[i][j])%M;inc%=M;
            // inc*=power(2,n-j);inc%=M;
            ans+=inc;ans%=M;
           }
           cout<<ans<<" ";
        }
        cout<<endl;
        
    }
    return 0;
}

