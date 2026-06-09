#include<bits/stdc++.h>
using namespace std;
# define vecin(n,a) vector<int> a(n); for(int i=0;i<n;i++){cin>>a[i];}
# define vecout(a)  for(auto i: a){cout<<i<<" ";} cout<<endl;
# define int long long int
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin>>T;
    for(int t=0;t<T;t++){
        int n,k;
        cin>>n>>k;
        if(n==0){cout<<"Bob"<<endl;continue;}
        n++;
        if(k%3){
            if((n-1)%3==0){
                cout<<"Bob"<<endl;
            }
            else{
                cout<<"Alice"<<endl;
            }
        }
        else{
            int r=(n%(k+1));
            if(r==0){cout<<"Alice"<<endl;}
            else if((r-1)%3==0){
                cout<<"Bob"<<endl;
            }
            else{
                cout<<"Alice"<<endl;
            }
        }
    }
    return 0;
}

