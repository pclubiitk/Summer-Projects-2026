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

int step = 0;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vi a (n,0);
        set <vi> apple;
        apple.insert({0,0,n - 1});
        for(int i = 1; i <= n; i++){
            vi k = *(apple.begin());
            apple.erase(k);
            int mid = (k[1] + k[2])/2;
            a[mid] = i;
            if(mid > k[1]) apple.insert({n - (mid - k[1]),k[1],mid - 1});
            if(k[2] > mid) apple.insert({n - (k[2] - mid),mid + 1,k[2]});
        }
        for(int i = 0; i < n; i++){
            cout << a[i] << ' ';
        }
        cout << '\n';
    }
    return 0;
}