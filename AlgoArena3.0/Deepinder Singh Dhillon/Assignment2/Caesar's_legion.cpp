#include<bits/stdc++.h>
using namespace std;

# define int long long int

# define M 100000000

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n1,n2,k1,k2;
    cin>>n1>>n2>>k1>>k2;
    vector<vector<int>> f(n1+1,vector<int>(n2+1)),h(n1+1,vector<int> (n2+1));
    f[0][0]=1;h[0][0]=1;
    for (int i = 0; i <= n1; i++)
    {
        for (int j = 0; j <= n2; j++)
        {
            for (int l = 1; l <= k1; l++)
            {   if(i-l<0){break;}
                f[i][j]+=(h[i-l][j]);f[i][j]%=M;
            }
            
            for (int l = 1; l <= k2; l++)
            {   if(j-l<0){break;}
                h[i][j]+=f[i][j-l];h[i][j]%=M;
            }
            
        }
        
    }
    cout<<(f[n1][n2]+h[n1][n2])%M<<endl;
    

    return 0;
}
