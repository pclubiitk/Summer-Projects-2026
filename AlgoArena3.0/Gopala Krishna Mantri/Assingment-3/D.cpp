#include<bits/stdc++.h>
#include<vector>
 
using namespace std;

struct DSU{

    vector<int> parent;
    vector<int> idx;
    vector<bool> looped;
    DSU(int n){
        parent.resize(n);
        idx.assign(n, -1);
        looped.assign(n, false);
        for(int i = 0; i < n; i++){parent[i] = i;}
    }
    int find(int i){
        if(parent[i] == i){return i;}
        parent[i] = find(parent[i]);
        return parent[i];
    }
    int merge(int i, int j){
        int ri = find(i);
        int rj = find(j);
        if(ri != rj){parent[ri] = rj;}
        else{looped[rj] = true;}
        looped[rj] = looped[rj] | looped[ri];
        if(looped[rj]){return 2;}
        int ret = 0;
        if(idx[ri] != -1){ret = idx[ri] + 1;}
        if(idx[rj] != -1){ret = idx[rj] + 1;}        
        return ret;
    }

};

void solve()
{

    int n; cin >> n;
    vector<pair<pair<int, int>, int>> a(n);
    for(int i = 0; i < n; i++){cin >> a[i].first.first;}
    for(int i = 0; i < n; i++){cin >> a[i].first.second;}
    sort(a.begin(),a.end());
    a[n-1].second = n-1;
    for(int i = n - 2; i >= 0; i--){
        if(a[i].first.second > a[a[i+1].second].first.second){a[i].second = i;}
        else{a[i].second = a[i+1].second;}
    }
    
    int m; cin >> m;
    vector<pair<pair<int, int>, int>> b(m);
    for(int i = 0; i < m; i++){cin >> b[i].first.first;}
    for(int i = 0; i < m; i++){cin >> b[i].first.second;}
    sort(b.begin(),b.end());
    b[m-1].second = m-1;
    for(int i = m - 2; i >= 0; i--){ 
        if(b[i].first.second > b[b[i+1].second].first.second){ b[i].second = i;}
        else{b[i].second = b[i+1].second;}
    }

    DSU dsu(n+m);
    vector<int> ret(3, 0);
    for(int i = 0; i < n; i++){
        
        if(dsu.idx[dsu.find(i)] != -1){
            continue;
        }

        bool turn = true;
        int cur = i;
        while(true){
            if(turn){
               
                pair<pair<int , int> , int> temp = {{a[cur].first.second, INT_MAX}, 0};
                auto it = upper_bound(b.begin(), b.end(), temp);
                if(it == b.end()){dsu.idx[dsu.find(cur)] = 0; break;}
                else{
                    int nxt = n + (*it).second;
                    int isp = dsu.merge(cur, nxt);
                    if(isp){dsu.idx[dsu.find(cur)] = isp - 1; break;}
                    cur = nxt;
                }

            }
            else{

                pair<pair<int , int> , int> temp = {{b[cur-n].first.second, INT_MAX}, 0};
                auto it = upper_bound(a.begin(), a.end(), temp);
                if(it == a.end()){dsu.idx[dsu.find(cur)] = 2; break;}
                else{
                    int nxt = (*it).second;
                    int isp = dsu.merge(cur, nxt);
                    if(isp){dsu.idx[dsu.find(cur)] = isp - 1; break;}
                    cur = nxt;
                }

            }
            turn = !turn;

        }

    }
    for(int i = 0; i < n; i++){ret[dsu.idx[dsu.find(i)]]++;}
    cout << ret[0] << " " << ret[1] << " " << ret[2] << "\n";

}
 
int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);    

    //int t = 1;
    int t; cin >> t;
    for(int i = 0; i < t; i++) {solve();}

    return 0;

}