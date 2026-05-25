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

bool checker(vi &a, int mid, int k){
    int n = a.size();
    vi b ( n + 1);
    for(int i = 0; i < a.size(); i++){
        if(a[i] >= mid) b[i] = 1;
        else b[i] = -1;
    }
    vi pref (n + 1);
    for(int i = 0; i < n; i++){
        pref[i + 1] = pref[i] + b[i];
    }
    vi least_pref (n + 1);
    for(int i = 0; i < n; i++){
        least_pref[i + 1] = min(least_pref[i],pref[i + 1]);
    }
    for(int i = k ; i <= n; i++){
        if(pref[i] - least_pref[i - k] > 0){
            cerr << pref[i] << ' ' << least_pref[i] << '\n';
            cerr << i;
            return 1;
        }  
    }
    return 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k; cin >> n >> k;
    vi a (n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    int ans = 0;
    int l = 0, r = *max_element(all(a));
    while(l <= r){
        int mid = l + (r - l)/2;
        if(checker(a,mid,k)){
            ans = max(ans,mid);
            l = mid + 1;
        }else{
            r = mid - 1;
        }
    }
    cout << ans << '\n';
    return 0;
}