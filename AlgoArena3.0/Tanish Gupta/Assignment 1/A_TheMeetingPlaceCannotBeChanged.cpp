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

bool check(double time, vi &x, vi&v){
    pair<double ,double > ex = {x[1]-v[1]*time,x[1]+v[1]*time};
    for (int i=2; i<x.size(); i++){
        pair<double ,double > hi = {x[i]-(ll)v[i]*time,x[i]+(ll)v[i]*time};
        if (ex.second<hi.first || hi.second<ex.first) return false;
        else ex.second=min(ex.second,hi.second), ex.first= max(ex.first,hi.first);                
    }
    return true;
}

void solve(){
    int n; cin>>n;
    vi x = ivec(n);
    vi v = ivec(n);

    //Change float ->double
    /*
    double l = 0, r = 1e9, ans = -1;
    while (l <= r) {
        
        double mid = l + (r-l)/2;
        mid = floor(mid * 1e6) / 1e6;  

        //cout<<l<<" "<<r<<" ";
        //cout << fixed << setprecision(6) << mid<<" ";
        
        if (check(mid,x,v)) {
            //cout << fixed << setprecision(6) << r<<" ";
            ans = mid, r = mid-pow(10,-6); 
            //cout<<"Yes"<<" ";
            //cout << fixed << setprecision(6) << r<<endl;
        }
        else {l = mid+pow(10,-6);} //cout<<"No"<<endl;}
    }
    cout << fixed << setprecision(6) << ans;
    */

    /*
    double l = 0, r = 1e9, ans = -1;   
    while (l <= r) {
        double mid = l + (r-l)/2;
        mid = floor(mid * 1e6) / 1e6;  
        if (check(mid,x,v)) ans = mid, r = mid-pow(10,-6);
        else {l = mid+pow(10,-6);}
    }
    cout << fixed << setprecision(6) << ans;
    */


    double l = 0, r = 1e9;
    for (int iter = 0; iter < 200; iter++) {
        double mid = (l + r) / 2;
        if (check(mid, x, v)) r = mid;
        else l = mid;
    }
    cout << fixed << setprecision(6) << r;
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
