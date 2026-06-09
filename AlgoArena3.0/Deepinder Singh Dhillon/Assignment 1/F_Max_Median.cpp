#include<bits/stdc++.h>
using namespace std;
# define vecin(n,a) vector<int> a(n); for(int i=0;i<n;i++){cin>>a[i];}
# define vecout(a)  for(auto i: a){cout<<i<<" ";} cout<<endl;
# define int long long int
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,k;
    cin>>n>>k;
    vector<int> vec(n);
    for (int i = 0; i < n; i++)
    {
        cin>>vec[i];   
    }
    int up=n;int lo=0;int ans;
    while(up>=lo){
        int mid=lo+(up-lo)/2;
        vector<int> copy=vec;
        for (int i = 0; i < n; i++)
        {
            if(copy[i]>=mid){
                copy[i]=1;
            }
            else{copy[i]=-1;}
        }
        vector<int> pre(n+1);
        for (int i = 1; i < n+1; i++)
        {
            pre[i]=copy[i-1]+pre[i-1];
        }
        vector<int> least(n+1);
        for (int i = 1; i < n+1; i++)
        {
            least[i]=min(least[i-1],pre[i]);
        }
        
        int flag=0;
        for (int i = k; i < n+1; i++)
        {
            if(pre[i]>least[i-k]){flag=1;break;}
        }
        
        if(flag){
            ans=mid;
            lo=mid+1;
        }
        else{
            up=mid-1;
        }
    }
    cout<<ans<<endl;
    return 0;
}
