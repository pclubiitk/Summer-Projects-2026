#include <bits/stdc++.h>

using namespace std;

const long long MOD = 1e9 + 7;

int main(){
    int n,a;
    cin >> n;
    vector<int> arr;
    for(int i = 0; i < n; i++){
        cin >> a;
        arr.push_back(a);
    }
    sort(arr.begin(), arr.end());
    map<int,int> count;
    for(int a : arr){
        if (count.find(a) == count.end()){
            count[a] = 1;
        }
        else count[a]++;
    }
    for(int i = 0; i <= 1e5; i++){
        if (count.find(i) == count.end()) count[i] = 0;
    }
    vector<long long>dp(1e5+5,0);
    for(int i = arr[n-1]; i > 0; i--){
        dp[i] = max((long long)count[i] * i + dp[i+2], (long long)count[i+1] * (i+1) + dp[i+3]);
    }
    cout << dp[1];

}
