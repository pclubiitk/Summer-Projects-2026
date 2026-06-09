#include <bits/stdc++.h>

using namespace std;

int main(){
    long long n,m,a;
    cin >> n >> m;
    vector<vector<int>> gym(n+1,vector<int>(m+1));
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> a;
            gym[i][j] = a;
        }
    }
    vector<vector<vector<long long>>> dpm(n+1,vector<vector<long long>>(m+1, vector<long long>(2)));
    vector<vector<vector<long long>>> dpw(n+1,vector<vector<long long>>(m+1, vector<long long>(2)));

    dpm[1][1][0] = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(i == 1 && j == 1) continue;
            if(i==1){
                dpm[i][j][0] = dpm[i][j-1][0] + gym[i][j-1];
                continue;
            } 
            if(j==1){
                dpm[i][j][0] = dpm[i-1][j][0] + gym[i-1][j];
                continue;
            }
            dpm[i][j][0] = max(dpm[i][j-1][0] + gym[i][j-1], dpm[i-1][j][0] + gym[i-1][j]);
        }
    }
    dpm[n][m][1] = 0;
    for(int i = n; i > 0; i--){
        for(int j = m; j > 0; j--){
            if(i == n && j == m) continue;
            if(i==n){
                dpm[i][j][1] = dpm[i][j+1][1] + gym[i][j+1];
                continue;
            } 
            if(j==m){
                dpm[i][j][1] = dpm[i+1][j][1] + gym[i+1][j];
                continue;
            }
            dpm[i][j][1] = max(dpm[i][j+1][1] + gym[i][j+1], dpm[i+1][j][1] + gym[i+1][j]);
        }
    }
    dpw[n][1][0] = 0;
    for(int i = n; i > 0; i--){
        for(int j = 1; j <= m; j++){
            if(i == n && j == 1) continue;
            if(i==n){
                dpw[i][j][0] = dpw[i][j-1][0] + gym[i][j-1];
                continue;
            } 
            if(j==1){
                dpw[i][j][0] = dpw[i+1][j][0] + gym[i+1][j];
                continue;
            }
            dpw[i][j][0] = max(dpw[i][j-1][0] + gym[i][j-1], dpw[i+1][j][0] + gym[i+1][j]);
        }
    }
    dpw[1][m][1] = 0;
    for(int i = 1; i <= n; i++){
        for(int j = m; j > 0; j--){
            if(i == 1 && j == m) continue;
            if(i==1){
                dpw[i][j][1] = dpw[i][j+1][1] + gym[i][j+1];
                continue;
            } 
            if(j==m){
                dpw[i][j][1] = dpw[i-1][j][1] + gym[i-1][j];
                continue;
            }
            dpw[i][j][1] = max(dpw[i][j+1][1] + gym[i][j+1], dpw[i-1][j][1] + gym[i-1][j]);
        }
    }
    long long ans = 0;
    for(int i = 2; i < n; i++){
        for(int j = 2; j < m; j++){
        long long A = (dpm[i-1][j][0] + gym[i-1][j]) + (dpm[i+1][j][1] + gym[i+1][j])
                    + (dpw[i][j-1][0] + gym[i][j-1]) + (dpw[i][j+1][1] + gym[i][j+1]);
        
        long long B = (dpm[i][j-1][0] + gym[i][j-1]) + (dpm[i][j+1][1] + gym[i][j+1])
                    + (dpw[i+1][j][0] + gym[i+1][j]) + (dpw[i-1][j][1] + gym[i-1][j]);
        ans = max(ans, max(A, B));
        }
    }

    cout << ans;

}
