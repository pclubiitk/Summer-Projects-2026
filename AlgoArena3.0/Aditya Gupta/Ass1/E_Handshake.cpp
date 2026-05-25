#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9 + 7;
const int MOD = 1000000007;

#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define per(i, a, b) for (int i = (b); i >= (a); i--)

#define ll long long
#define vi vector<int>
#define vvi vector<vi>
#define ii pair<int, int>
#define pb push_back
#define mp make_pair
#define F first
#define S second

bool checker(int mid, vi &peps, ll m){
    ll made = 0;
    int n = peps.size();
    int j = n - 1;

    for(int i = 0; i < n; i++){
        while(j >= 0 && peps[i] + peps[j] >= mid){
            j--;
        }
        made += n - j - 1;
    }

    if(made >= m) return 1;
    return 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, m; cin >> n >> m;
    vi peps (n);
    for(int i = 0; i < n; i++){
        cin >> peps[i];
    }
    sort(peps.begin(),peps.end());

    int l = 0, r = 2 * peps[n - 1];
    int ans = 0;
    
    while(l <= r){
        int mid = l + (r - l) / 2;
        if(checker(mid,peps,m)){
            ans = max(ans,mid);
            l = mid + 1;
        }else{
            r = mid - 1; 
        }
    }
    
    ll ans1 = 0;
    ll made = 0;
    int j = n - 1;

    vector <ll> suf (n + 1);
    for(int i = n - 1; i >= 0; i--){
        suf[i] = suf[i+1] + peps[i];
    }

    //ans = 90;
    
    for(int i = 0; i < n; i++){
        while(j >= 0 && peps[i] + peps[j] >= ans){
            j--;
        }
        made += n - j - 1 ;
        //cerr << i << ' ' << j << ' ' << made <<  '\n';
        ans1 += suf[j + 1] + 1LL*(n - j - 1)*peps[i];
    }
    
    ans1 -= (made - m) * ans;
    cout << ans1 << '\n';
    return 0;
}