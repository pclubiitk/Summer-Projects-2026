#include<bits/stdc++.h>
using namespace std;
# define vecin(n,a) vector<int> a(n); for(int i=0;i<n;i++){cin>>a[i];}
# define vecout(a)  for(auto i: a){cout<<i<<" ";} cout<<endl;
# define int long long int

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    cin>>n>>m;
    vector<int> vec(n);
    for (int i = 0; i < n; i++)
    {
        cin>>vec[i];
    }
    sort(vec.begin(),vec.end());
    vector<int> suf(n+1);
    for (int i = n-1; i >-1; i--)
    {
        suf[i]=vec[i]+suf[i+1];
    }
    
    int up=2*vec[n-1];int lo=0;int ans;int acnt;
    while(up>=lo){
        int mid=lo+(up-lo)/2;
        int cnt=0;
        int itr1=0;int itr2=n-1;
        while(itr1<n&&itr2>-1){
            if(vec[itr1]+vec[itr2]>=mid){
                cnt+=(n-itr1);
                itr2--;
            }
            else{
                itr1++;
            }
        }
        if(cnt>=m){
            acnt=cnt;
            ans=mid;
            lo=mid+1;
        }
        else{
            up=mid-1;
        }
    }
    int sum=0;
    int itr1=0;int itr2=n-1;
        while(itr1<n&&itr2>-1){
            if(vec[itr1]+vec[itr2]>=ans){
                sum+=(n-itr1)*(vec[itr2]);
                sum+=(suf[itr1]);
                itr2--;
            }
            else{
                itr1++;
            }
        }
        sum-=((acnt-m)*ans);
        cout<<sum<<endl;
    return 0;
}

