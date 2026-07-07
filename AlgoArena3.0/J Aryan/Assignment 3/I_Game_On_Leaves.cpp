#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
//hakuna matata
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t=1; cin>>t;
    while(t--){
        int n,x; cin>>n>>x;
        vector<vector<int>> adj(n+1);
        for(int i=1;i<n;i++){
            int u,v; cin>>u>>v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        if(adj[x].size()<=1) cout<<"Ayush"<<'\n';
        else{
            cout<<((n-1)%2==0 ? "Ashish" : "Ayush")<<'\n';
        }
    }
}
