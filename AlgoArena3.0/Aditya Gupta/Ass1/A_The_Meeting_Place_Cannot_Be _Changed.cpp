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

bool checker(double t, vi &loc, vi &speed, int n){
    double L = 0;
    double R = INF;
    for(int i = 0; i < n; i++) {
        L = max(L, loc[i] - t*speed[i]);
        R = min(R, loc[i] + t*speed[i]);
    }
    return L <= R;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;
    vi loc (n);
    for(int i = 0; i < n; i++){
        cin >> loc[i];
    }
    vi speed (n);
    for(int i = 0; i < n; i++){
        cin >> speed[i];
    }
    double l = 0; double r = *max_element(all(loc));
    double ans = INF;
    while(r >= l){
        double mid = l + (r - l)/2;
        if(checker(mid, loc, speed,n)){
            ans = min(ans,mid);
            r = mid - 1e-7;
        }else{
            l = mid + 1e-7;
        }
    }
    cout << setprecision(10) << ans<< '\n';
    return 0;
}
