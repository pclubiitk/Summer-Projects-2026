

#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
	int t;
    cin>>t;
    while(t--){
        ll n; 
        cin>>n;
        ll ar[n];
        for(int i=0;i<n; i++) cin>>ar[i];
        vector<array<int,2>> v(n);
        if(ar[0]%2==0)v[0][1]=1;
        else v[0][0]=1;
        for(int i=1; i<n; i++){
            v[i][0]=v[i-1][0];
            v[i][1]=v[i-1][1];
            if(ar[i]%2==0)v[i][1]+=1;
            else v[i][0]+=1;
        }
        ll sum[n]={};
        sum[0]=ar[0];
        for(int i=1; i<n; i++){
           sum[i]=sum[i-1]+ar[i];
        }
        for(int i=0; i<n; i++){
            if(v[i][0]%3==0 ||  v[i][0]%3==2){
             
                    cout<<sum[i]-(v[i][0]/3)<<" ";
             
            }
            else if(v[i][0]%3==1){
                if(v[i][0]==1 && v[i][1]==0) cout<<sum[i]<<" ";
              
                else    cout<<sum[i]-(v[i][0]/3)-1<<" ";
                
            }
        }
        cout<<endl;
    }
}
