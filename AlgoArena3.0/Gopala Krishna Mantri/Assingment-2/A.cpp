#include<bits/stdc++.h>
#include<vector>
 
using namespace std;

void solve()
{

    int n; cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++){cin >> a[i];}

    vector<vector<int>> dp(n, vector<int>(n));

    dp[n-1][n-1] = 1;
    
    for(int i = n - 2; i >= 0; i--){

        dp[i][i] = 1;

        for(int j = i + 1; j < n; j++){

            dp[i][j] = dp[i+1][j] + 1;

            if(a[i+1] == a[i]){
                
                if(i + 1 == n - 1){

                    dp[i][j] = 1;

                } 

                else{

                    dp[i][j] = min(dp[i][j], 1 + dp[i+2][j]);

                }
            
            }

            for(int k = i + 2; k <= j; k++){

                if(a[i] == a[k]){

                    if(k == j){dp[i][j] = min(dp[i][j], dp[i+1][k-1] );}
                    else{dp[i][j] = min(dp[i][j], dp[i+1][k-1] + dp[k+1][j]);} 

                }

            }

        }

    }

    cout << dp[0][n-1] << "\n";


}
 
int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);    

    int t = 1;
    //int t; cin >> t;
    for(int i = 0; i < t; i++) {solve();}

    return 0;

}