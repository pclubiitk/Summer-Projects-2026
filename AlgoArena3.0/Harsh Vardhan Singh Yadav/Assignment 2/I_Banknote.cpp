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

void solve() {
    int n;
    cin>>n;
    vector<int> v;
    for(int i =n;i>0;i/=10){
        v.push_back(i%10);
    }
    v.push_back(0);
    // reverse(v.begin(),v.end());
    int ans=0;
    int carry=0;
    for(int i = 0;i<v.size();i++){
        v[i]+=carry;
        carry=0;
        if((v[i])<5){
            ans+=v[i];
        }
        else if(v[i]>5){
            ans+=10-v[i];
            carry=1;
        }
        else{
            if(v[i+1]>=5){
                carry=1;
                ans+=10-v[i];
            }
            else{
                ans+=v[i];
            }
        }
    }
    cout<<ans<<"\n";
    

}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}