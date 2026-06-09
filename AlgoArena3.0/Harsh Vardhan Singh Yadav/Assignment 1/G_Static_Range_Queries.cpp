#include "bits/stdc++.h"
using namespace std;
#define int long long
#define vi vector<int>
#define vvi vector<vector<int>>
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
#define ff first
#define ss second
typedef pair<int,int> pii;
typedef vector<pii> vpii;

const int MOD = 1e9 + 7;
const int INF = 1e18;
const int NEG_INF = -1e18;


// ─── Solve ────────────────────────────────────────────────
void solve() {
    int n,q;
    cin>>n>>q;
    vvi v(n,vi (3));
    vvi v2(q,vi (2));
    vi a;
    unordered_map<int,int> mp,mp2;
    for(int i = 0 ; i<n;i++){
        cin>>v[i][0]>>v[i][1]>>v[i][2];
        if(mp[v[i][0]]==0)
        {a.push_back(v[i][0]);
            mp[v[i][0]]++;
        }
        if(mp[v[i][1]]==0)
        {a.push_back(v[i][1]);
        mp[v[i][1]]++;
        }
    }
    for(int i = 0 ; i<q;i++){
        cin>>v2[i][0]>>v2[i][1];
        if(mp[v2[i][0]]==0)
        {a.push_back(v2[i][0]);
            mp[v2[i][0]]++;
        }
        if(mp[v2[i][1]]==0)
        {a.push_back(v2[i][1]);
        mp[v2[i][1]]++;
        }
    }
    sort(a.begin(),a.end());
    vi width(a.size()),val(a.size());

    vi diff(a.size()+1);
    for(int i = 0 ; i<a.size();i++){
        mp2[a[i]]=i;
    }
    for(int i = 0 ;  i<n;i++){
        diff[mp2[v[i][0]]]+=v[i][2];
        diff[mp2[v[i][1]]]-=v[i][2];
    }
    for(int i = 0 ; i<a.size()-1;i++){
        width[i+1]=a[i+1]-a[i];
    }
    val[0]=0;
    for(int i = 1;i<a.size();i++){
        val[i]=val[i-1]+diff[i-1];
    }
    int pref[400001];
    pref[0]=0;
    for(int i =1;i<a.size();i++){
        pref[i]=pref[i-1]+val[i]*width[i];
    }
    for(int i = 0 ;i<q;i++){
        cout<<pref[mp2[v2[i][1]]]-pref[mp2[v2[i][0]]]<<"\n";
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

   
    solve();
    

    return 0;
}