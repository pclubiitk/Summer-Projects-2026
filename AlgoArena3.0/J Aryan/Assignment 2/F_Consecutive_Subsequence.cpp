#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin>>n;
    vector<int> a(n);
    map<int,int> m;
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(m.find(a[i]-1)!=m.end()) m[a[i]] = m[a[i]-1] + 1;
        else m[a[i]] = 1;
    }
    int best = 0, r = 0;
    for(auto p : m){
        if(p.second>best){
            best = p.second;
            r = p.first;
        }
    }
    int l = r - best + 1;
    cout<<r-l+1<<'\n';
    for(int i=0;i<n && l<=r;i++){
        if(a[i]==l){
            cout<<i+1<<' ';
            l++;
        }
    }
}
