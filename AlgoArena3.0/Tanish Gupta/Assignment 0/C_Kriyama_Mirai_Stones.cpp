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
    int n; cin>>n;
    vi v = ivec(n);
    vi u = v;
    sort(u.begin(),u.end());

    vll sumv(n+1);
    for (int i=1; i<=n; i++) sumv[i]=sumv[i-1]+v[i];

    vll sumu(n+1);
    for (int i=1; i<=n; i++) sumu[i]=sumu[i-1]+u[i];

    int m; cin>>m;
    while(m--){
        int l,r,t; cin>>t>>l>>r;
        if (t==1) cout<<sumv[r]-sumv[l-1]<<endl;
        else cout<<sumu[r]-sumu[l-1]<<endl;
    }

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
