#include<bits/stdc++.h>
#include<vector>
 
using namespace std;

void solve()
{

    
    int n; cin >> n;
    vector<int> a(n); for(int i = 0; i < n; i++){cin >> a[i];}
    
    map<int, int> dp;
    int last = a[0];
    int ret = 1;
    dp[a[0]] = 1;

    for(int i = 1; i < n; i++){

        dp[a[i]] = dp[a[i] - 1] + 1;
        if(dp[a[i]] > ret){

            ret = dp[a[i]];
            last = a[i]; 

        }

    }

    stack<int> out;
    
    for(int i = n - 1; i >= 0; i--){

        if(a[i] == last){out.push(i); last--;}

    }

    cout << out.size() << "\n";
    while(!out.empty()){cout << out.top() + 1 << " "; out.pop();}cout << "\n"; 

}
 
int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);    

    int t = 1;
    //int t; cin >> t;
    for(int i = 0; i < t; i++) {solve();}

    return 0;

}