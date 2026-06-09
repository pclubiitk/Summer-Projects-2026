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



bool comp(pair<int,int> p1, pair<int,int> p2){
    if (p1.first>p2.first || p1.first==p2.first && p1.second<p2.second) return true;
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
    vi a(n+1);
    //set<pair<int,int>,comp> zero={{n,1}};

    set<pair<int,int>, decltype(&comp)> zero(comp);
    zero.insert({n, 1});

    for (int i=1; i<=n; i++){
        pair<int,int> p = (*zero.begin());
        zero.erase(zero.begin());
        if (p.first%2==1){
            //odd length
            a[(p.first+2*p.second-1)/2]=i;
            //zero.erase(zero.begin());
            if (p.first>=3) {
                zero.insert({p.first/2, p.second});
                zero.insert({p.first/2, (p.first+2*p.second-1)/2+1});
            }
            
        }
        else{
            //even length
            a[(p.first+2*p.second-2)/2]=i;
            //zero.erase(zero.begin());
            if (p.first==2){
                zero.insert({1, p.second+1});
            }
            else if (p.first>=4) {
                zero.insert({p.first/2-1, p.second});
                zero.insert({p.first/2, p.second+p.first/2});
            }
        }
        /*
        for (int i=1; i<=n; i++) cout<<a[i]<<" ";
        cout<<endl;
        for (pii p : zero) cout<<"{"<<p.first<<" "<<p.second<<"}"<<" ";
        cout<<endl;
        cout<<endl;
        */
    }

    for (int i=1; i<=n; i++) cout<<a[i]<<" ";
    cout<<endl;
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
