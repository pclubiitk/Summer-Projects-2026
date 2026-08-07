#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
//hakuna matata
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t=1; cin>>t;
    while(t--){
        int n,m; cin>>n>>m;
        vector<string> a(n);
        vector<int> b;
        int sum = 0;
        for(int i=0;i<n;i++){
            cin>>a[i];
            int c = 0,j;
            for(j=a[i].size()-1;j>=0;j--) if(a[i][j]!='0') break;
            c = a[i].size() - 1 - j;
            b.push_back(c);
            sum += a[i].size();
        }
        sort(b.rbegin(),b.rend());
        for(int i=0;i<n;i+=2) sum -= b[i];
        if(sum>=m+1) cout<<"Sasha"<<'\n';
        else cout<<"Anna"<<'\n';
    }
}
