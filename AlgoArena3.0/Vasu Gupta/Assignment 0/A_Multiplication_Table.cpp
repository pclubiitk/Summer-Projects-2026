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
        ll n,m,k;
        cin>>n>>m>>k;
        ll min1=1;
        ll max1=m*n;
        while (min1<=max1) {
            ll mid = (min1+max1)/2;
            ll countlower{0};
            ll countexact{0};
            for (int i=1;i<=n;i++) {
                if (mid>1) {
                    countlower+=min((mid-1)/i,m);
                    countexact+=min(mid/i,m);
                }
                else {
                    if (k==1) {
                        cout<<1<<'\n';
                        return;
                    }
                    else {
                        min1=mid+1;
                    }
                }
            }
            if (countlower>=k) {
                max1=mid-1;
            }
            else {
                if (countexact>=k) {
                    cout<<mid<<'\n';
                    return;
                }
                else {
                    min1=mid+1;
                }
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
