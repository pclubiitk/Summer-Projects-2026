#include<bits/stdc++.h>
#include<vector>
 
using namespace std;

void solve()
{

    int n, s; cin >> n >> s; s--;
    vector<vector<int>> adj(n);
    int x, y; 
    for(int i = 0; i < n - 1; i++){
        cin >> x >> y; x--; y--;
        adj[x].push_back(y); adj[y].push_back(x);
    }
    if(adj[s].size() == 1 || adj[s].size() == 0){cout << "Ayush" << "\n"; return;}
    cout << ((n%2) ? "Ashish" : "Ayush") << "\n";

}
 
int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);    

    //int t = 1;
    int t; cin >> t;
    for(int i = 0; i < t; i++) {solve();}

    return 0;

}