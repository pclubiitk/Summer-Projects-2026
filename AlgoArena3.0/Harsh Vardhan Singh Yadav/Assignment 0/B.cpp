#include "bits/stdc++.h"
using namespace std;
#define int long long
#define vi vector<int>
#define vvi vector<vector<int>>


bool isPrime(long long n) {
    if(n < 2) return false;
    for(long long i = 2; i * i <= n; i++) {
        if(n % i == 0) return false;
    }
    return true;
}

void solve() {
    int n;
    cin>>n;
    
    if((int)sqrt(n)*(int)sqrt(n)==n && n!=1 && isPrime((int)sqrt(n)) ){
        cout<<"YES\n";
    }
    else{
        cout<<"NO\n";
    }
   
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}