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
    int n,k; cin>>n>>k;


    if (k%3==0){
        int i = (n/(k+1));
        int ind = n-(i*k+i);
        if (ind%3==0 && ind!=k) cout<<"Bob"<<endl; //tick
        else cout<<"Alice"<<endl; //cross

        /*
        int i = n/k;
        n=n-i*k;

        if(n>=i){
            if ((n-i)%3==0) cout<<"Bob"<<endl;
            else cout<<"Alice"<<endl;
        }
        else{
            if (n>(i-4)) cout<<"Alice"<<endl;
            else if (((i-4)-n)%3==0) cout<<"Bob"<<endl;
            else cout<<"Alice"<<endl;
        }
        */
    }
    else if (k%3==1){
        if (n%3==0) cout<<"Bob"<<endl;//tick
        else cout<<"Alice"<<endl;//cross
    }
    else{
        if (n%3==0) cout<<"Bob"<<endl;//tick
        else cout<<"Alice"<<endl;//cross
    }


    /*    if (k%3==1){
        if (n<k) {
            if (n%3==0) cout<<"Bob"<<endl;
            else cout<<"Alice"<<endl;
        }
        else{
            n-=k;
            if (n%3==2) cout<<"Bob"<<endl;
            else cout<<"Alice"<<endl;
        }
    }
    else if (k%3==2){
        if (n<k) {
            if (n%3==0) cout<<"Bob"<<endl;
            else cout<<"Alice"<<endl;
        }
        else{
            n-=k;
            if (n%3==1) cout<<"Bob"<<endl;
            else cout<<"Alice"<<endl;
        }
    }
    */

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
