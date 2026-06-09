#include<bits/stdc++.h>
#include<vector>
 
using namespace std;

void solve()
{

    int n; cin >> n; int k; cin >> k;
    string s; cin >> s;

    int c = 0;
    int ret = n;
    for(int i = 0; i < n; i++){c += (s[i] - '0');}

    for(int j = 0; j < k; j++){

        int curc = 0;
        vector<int> a;
        for(int i = j; i < n; i += k){

            a.push_back(s[i] - '0');
            curc += a.back();

        }

        int l = a.size();
        vector<int> pref(l + 1, 0);
        for(int i = 1; i <= l; i++){pref[i] = pref[i-1] + a[i-1];}
        vector<int> f(l + 1);
        for(int i = 0; i <= l; i++){f[i] = i - 2*pref[i];}

        vector<int> minf(l + 1);
        minf[0] = f[0];
        for(int i = 1; i <= l; i++){minf[i] = min(f[i], minf[i-1]);}

        int del = INT_MAX;
        for(int i = 0; i <= l; i++){

            del = min(del, f[i]-minf[i]);

        }

        ret = min(curc + del + (c - curc), ret);

    }

    cout << ret << "\n";

}
 
int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);    

    //int t = 1;
    int t; cin >> t;
    for(int i = 0; i < t; i++) {solve();}

    return 0;

}