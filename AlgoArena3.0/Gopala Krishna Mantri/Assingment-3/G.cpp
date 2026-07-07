#include<bits/stdc++.h>
#include<vector>
 
using namespace std;

void solve()
{

    int n; cin >> n; int sum = 0; int m = 0;
    vector<int> a(n); for(int i = 0; i < n; i++){cin >> a[i]; sum +=a[i]; m =max(m, a[i]);}
    sort(a.begin(), a.end());
    if(n == 1){cout << "T" << "\n"; return;}
    if(n == 2){cout << ((a[0] == a[1]) ? "HL" : "T") << "\n"; return;}
    if(n == 3 && a[0] == 1 && a[1] == a[2]){cout << "T" << "\n"; return;}
    else{
        if(m > sum - m){cout << "T" << "\n"; return;}
        cout << ((sum%2) ? "T" : "HL") << "\n";
    }

}
 
int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);    

    //int t = 1;
    int t; cin >> t;
    for(int i = 0; i < t; i++) {solve();}

    return 0;

}