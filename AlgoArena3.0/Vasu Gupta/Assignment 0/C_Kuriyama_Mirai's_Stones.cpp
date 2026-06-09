    #include <bits/stdc++.h>
    using namespace std;

    using ll = long long;

    vector<pair<ll,ll>> path;

    ll max(ll a,ll b) {
        if (a>b) {
            return a;
        }
        else {
            return b;
        }
    }

    void search(ll x, ll y, vector<vector<ll>>& grid, vector<pair<ll,ll>> temppath, ll& n, ll& m) {
        if (x==n && y==m) {
            path=temppath;
            return;
        }
        else {
            if (x==n) {
                if (grid[x][y+1]==0) {
                    temppath.push_back({x,y+1});
                    search(x,y+1,grid,temppath,n,m);
                    temppath.pop_back();
                }
            }
            else if (y==m) {
                if (grid[x+1][y]==0) {
                    temppath.push_back({x+1,y});
                    search(x+1,y,grid,temppath,n,m);
                    temppath.pop_back();
                }
            }
            else {
                if (grid[x][y+1]==0) {
                    temppath.push_back({x,y+1});
                    search(x,y+1,grid,temppath,n,m);
                    temppath.pop_back();
                }
                if (grid[x+1][y]==0) {
                    temppath.push_back({x+1,y});
                    search(x+1,y,grid,temppath,n,m);
                    temppath.pop_back();
                }
            }
        }
    }

    void solve() {
        ll n;
        cin>>n;
        vector<ll> stones(n+1,0);
        for (int i=1;i<=n;i++) {
            cin>>stones[i];
        }
        auto stonessorted=stones;
        sort(stonessorted.begin(),stonessorted.end());
        vector<ll> prefixstones(n+1,0);
        vector<ll> prefixsorted(n+1,0);
        for (int i=1;i<=n;i++) {
            prefixstones[i]=prefixstones[i-1]+stones[i];
            prefixsorted[i]=prefixsorted[i-1]+stonessorted[i];
        }
        ll m;
        cin>>m;
        while (m--) {
            ll a,b,c;
            cin>>a>>b>>c;
            if (a==1) {
                cout<<prefixstones[c]-prefixstones[b-1]<<'\n';
            }
            else {
                cout<<prefixsorted[c]-prefixsorted[b-1]<<'\n';
            }
        }
    }

    int main() {
        ios::sync_with_stdio(false);
        cin.tie(NULL);
        int t = 1;
        //cin >> t;
        while (t--) {
            solve();
        }

        return 0;
    }
