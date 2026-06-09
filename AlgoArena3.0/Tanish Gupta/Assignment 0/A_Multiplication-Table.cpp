#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define vi vector<int>
#define si set<int>
#define vll vector<ll>
#define ivec input_to_a_vector
#define binsrc binary_search
#define pii pair<int,int>
#define pb push_back
const ll MOD = 1000000007;

// Include factorial & sieve in templates



bool comp(pii p1, pii p2){
    if (p1.first<p2.first || p1.first==p2.first && p1.second<p2.second) return true;
    return false;   
}

vi input_to_a_vector(int n){
    vi vec(n+1);
    for (int i=1; i<=n; i++) cin>>vec[i];
    return vec;
}
void swap(int &a, int&b){
    int t = a; a=b; b=t;
}

void solve(){
    ll n,m,k; cin>>n>>m>>k;

    
    ll l = 1, r = n*m, ans=0;
    while (l <= r) {
        ll mid = l + (r-l)/2;
        ll cnt=0;
        for (int i=1; i<=n; i++) cnt+= min(m,mid/i);

        if (cnt<k) l=mid+1;
        else {
            r = mid-1; ans=mid;
        }
    }
    cout<<ans;
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; t=1;
    while(t--){
        solve();
    }
    
}

/*
cout<<"Check1"<<endl;
cout<<"Check2"<<endl;
cout<<"Check3"<<endl;
cout<<"Check4"<<endl;
*/
