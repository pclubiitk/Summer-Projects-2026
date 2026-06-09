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


vll input_to_a_vector(ll n){
    vll vec(n+1);
    for (ll i=1; i<=n; i++) cin>>vec[i];
    return vec;
}
void swap(int &a, int&b){
    int t = a; a=b; b=t;
}

void solve(){
    ll n,m; cin>>n>>m;
    vll a = ivec(n);
    vll prefix(n+1);
    sort(a.begin(),a.end());
    for (ll i=1; i<=n; i++) prefix[i]=prefix[i-1]+a[i];
    
    if (m==n*n) {cout<<2*n*prefix[n]; return;}

    ll k = n*n-m;
    //cout<<endl<<k;
    ll l = a[1]+a[1], r = a[n]+a[n], ans=0;
    while (l <= r) {
        ll mid = l + (r-l)/2;

        ll cnt=0;
        
        for (int i=1; i<=n; i++) {
            cnt+=upper_bound(a.begin()+1,a.end(),mid-a[i])-a.begin()-1;
        }
 
        if (cnt<k) l=mid+1;
        else {
            r = mid-1; ans=mid;
        }
    }
    vll num(n+1); 
    ll cnt=0;
    ll sum=0;
    for (int i=1; i<=n; i++) {
        num[i]=upper_bound(a.begin()+1,a.end(),ans-a[i])-a.begin()-1;
        cnt+=num[i];
        sum+=num[i]*a[i] + prefix[num[i]];
        //cout<<a[i]<<" ";
    }
    //cout<<endl<<ans<<endl;

    sum-=(cnt-k)*ans;
    cout<<2*n*prefix[n] - sum; 

    //cout<<endl<<ans;
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
