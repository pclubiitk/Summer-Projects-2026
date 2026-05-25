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

bool checker(string k, string p, int mid, vi &nums){
    for(int i = 0; i < mid; i++){
        int q = nums[i];
        k[q - 1] = '~';
    }
    int j = 0;
    for(int i = 0; i < k.size() && j < p.size(); i++){
        if(k[i] == p[j]) j++;
    }
    return j == p.size();
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string k,p; cin >> k >> p;
    vi nums;

    int ans = 0, c;
    while(cin >> c){
        nums.push_back(c);
    }

    int l = 0, r = k.size();
    while(l <= r){
        int mid = l + (r - l)/2;
        if(checker(k,p,mid,nums)){
            l = mid + 1;
            ans = max(mid,ans);
        }else{
            r = mid - 1;
        }
    }
    cout << ans << '\n';
    return 0;
}