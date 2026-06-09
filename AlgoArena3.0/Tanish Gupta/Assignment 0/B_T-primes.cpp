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
    int num; cin>>num;

    int n = 1e6;
    vi p (n+1); //0 for prime, 1 for non-prime
    p[1]=1;
    for (int i=2; i<=sqrt(n); i++){
        if (p[i]==0){
            for (int j=i*i; j<=n; j+=i) p[j]=1;
        }
    }
    while(num--){
        ll x; cin>>x;
        if (x==1) {cout<<"NO"<<endl; continue;}

        if (sqrt(x)!=floor(sqrt(x))) {cout<<"NO"<<endl; continue;}
        else{
            if (p[(int)sqrt(x)]==0) cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
        }
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
