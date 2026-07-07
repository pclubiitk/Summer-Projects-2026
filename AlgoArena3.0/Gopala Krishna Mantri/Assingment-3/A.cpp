#include<bits/stdc++.h>
#include<vector>
 
using namespace std;

void solve()
{

    int n; cin >> n;
    vector<long long int> a(n); for(int i = 0; i < n; i++){cin >> a[i];}
    vector<long long int> pref(n); pref[0] = a[0]; for(int i = 1; i < n; i++){pref[i] = pref[i-1] + a[i];}

    cout << pref[0] << " ";
    int cnt = a[0]%2;
    for(int i = 1; i < n; i++){

        cnt += a[i]%2;
        if(cnt%3 == 2){cout << pref[i] - (cnt/3) << " ";}
        else if(cnt%3 == 1){cout << pref[i] - ((cnt/3) + 1) << " ";}
        else{cout << pref[i] - (cnt/3) << " ";}

    }cout << "\n";

}
 
int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);    

    //int t = 1;
    int t; cin >> t;
    for(int i = 0; i < t; i++) {solve();}

    return 0;

}