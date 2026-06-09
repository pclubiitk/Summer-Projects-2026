#include<bits/stdc++.h>
#include<vector>
 
using namespace std;

void solve()
{

    int n, m; cin >> n >> m;
    long long int a[n][m];

    for(int i = 0; i < n; i++){

        for(int j = 0; j < m; j++){

            cin >> a[i][j];

        }

    }

    long long int u[n][m];
    u[0][0] = a[0][0];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(!j){
                if(!i){continue;}
                u[i][j] = u[i-1][j] + a[i][j];
                continue;
            }
            if(!i){
                if(!j){continue;}
                u[i][j] = u[i][j-1] + a[i][j];
                continue;
            }
            u[i][j] = max(u[i-1][j], u[i][j-1]) + a[i][j];
        }
    }
    long long int u_[n][m];
    u_[n-1][m-1] = a[n-1][m-1];
    for(int i = n - 1; i >= 0; i--){
        for(int j = m - 1; j >= 0; j--){
            if(j == m - 1){
                if(i == n - 1){continue;}
                u_[i][j] = u_[i+1][j] + a[i][j];
                continue;
            }
            if(i == n - 1){
                if(j == m - 1){continue;}
                u_[i][j] = u_[i][j+1] + a[i][j];
                continue;
            }
            u_[i][j] = max(u_[i+1][j], u_[i][j+1]) + a[i][j];
        }
    }
    long long int d[n][m];
    d[n-1][0] = a[n-1][0];
    for(int i  = n - 1; i >= 0; i--){
        for(int j = 0; j < m; j++){
            if(!j){
                if(i == n - 1){continue;}
                d[i][j] = d[i+1][j] + a[i][j];
                continue;
            }
            if(i == n - 1){
                if(!i){continue;}
                d[i][j] = d[i][j-1] + a[i][j];
                continue;
            }
            d[i][j] = max(d[i][j-1], d[i+1][j]) + a[i][j];
        }
    }
    long long int d_[n][m];
    d_[0][m-1] = a[0][m-1];
    for(int i = 0; i < n; i++){
        for(int j = m - 1; j >= 0; j--){
            if(j == m - 1){
                if(!i){continue;}
                d_[i][j] = d_[i-1][j] + a[i][j];
                continue;
            }
            if(!i){
                if(j == m - 1){continue;}
                d_[i][j] = d_[i][j+1] + a[i][j];
                continue;
            }
            d_[i][j] = max(d_[i-1][j], d_[i][j+1]) + a[i][j];
        }
    }

    long long int ret = 0LL;
    for(int i = 1; i < n - 1; i++){
        for(int j = 1; j < m - 1; j++){
            long long int cur = max(u[i-1][j] + u_[i+1][j] + d[i][j-1] + d_[i][j+1], d_[i-1][j] + d[i+1][j] + u[i][j-1] + u_[i][j+1]);
            ret = max(cur, ret);
        }
    }
    cout << ret << "\n";

}
 
int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);    

    int t = 1;
    //int t; cin >> t;
    for(int i = 0; i < t; i++) {solve();}

    return 0;

}