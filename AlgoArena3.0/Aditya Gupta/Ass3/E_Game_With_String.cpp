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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while(t--){
        int a, b; cin >> a >> b;
        string s; cin >> s;
        vi len;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == 'X'){
               continue; 
            }
            int j = i + 1;
            while(j < s.size() && s[j] == '.') j++;
            len.pb(j - i);
            i = j;
        }
        int c1 = 0, c2 = 0, c3 = 0, c4 = 0; 
        int k = 0;
        for(int i = 0; i < len.size(); i++){
            if(len[i] < b) c1++;
            else if(len[i] < a ) c2++;
            else if(len[i] < 2 * b) c3++;
            else{
                c4++;
                k = len[i];
            }
        }
        if(c2 || c4 > 1){
            cout << "NO" << '\n';
            continue;
        }
        if(c4 == 0){
            if(c3 % 2) cout << "YES" << '\n';
            else cout << "NO" << '\n';
            continue;
        }
        bool ok = 0;
        for(int i = 0; i + a <= k; i++) {
            int r = k - a - i;
            if ((i >= b && i < a) || (r >= b && r < a)) continue;
            if (i >= 2 * b || r >= 2 * b) continue;

            int cur = c3;
            if(i >= a) cur++;
            if(r >= a) cur++;

            if(cur % 2 == 0){
                ok = 1;
                break;
            }
        }   
        if(ok) cout << "YES" << '\n';
        else cout << "NO" << '\n';
    }
    return 0;
}