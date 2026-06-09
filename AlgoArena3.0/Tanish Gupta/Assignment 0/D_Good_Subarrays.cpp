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
    int n; 
    string s; cin>>n>>s;
    
    vi a(n);
    for (int i=0; i<n; i++) a[i]=s[i]-49;
    //cout<<a[2]<<" ";
    vi sum(n+1);
    for (int i=1; i<=n; i++) sum[i]=sum[i-1]+a[i-1];
    //cout<<sum[2]<<" ";


    map<int,int>freq;
    for (int i=0; i<=n; i++) freq[sum[i]]++;
    ll cnt=0;
    //cout<<freq.size()<<" ";
    for (auto p:freq){
        cnt+=((ll)p.second*(p.second-1))/2;
    }
    cout<<cnt<<endl;



}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin>>t;
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
