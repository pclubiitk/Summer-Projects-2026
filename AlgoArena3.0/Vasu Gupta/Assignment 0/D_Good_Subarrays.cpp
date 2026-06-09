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
        string s;
        cin>>s;
        vector<ll> num(n+1);
        for (int i=1;i<=n;i++) {
            num[i]=s[i-1]-'0';
        }
        vector<ll> prefix(n+1,0);
        prefix[1]=num[1];
        for (int i=2;i<=n;i++) {
            prefix[i]=prefix[i-1]+num[i];
        }
        map<ll,ll> counter;
        counter[0]++;
        for (int i=1;i<=n;i++) {
            counter[prefix[i]-i]++;
        }
        ll ans{0};
        for (auto x:counter) {
            if (x.second>=2) {
                ans+=(x.second*(x.second-1))/2;
            }
        }
        cout<<ans<<'\n';
    }

    int main() {
        ios::sync_with_stdio(false);
        cin.tie(NULL);
        int t = 1;
        cin >> t;
        while (t--) {
            solve();
        }

        return 0;
    }
