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
        int n,m;
        cin>>n>>m;
        vector<int> a(n);
        vector<int> b(m);
        for (int i = 0; i < n; i++)
        {
            cin>>a[i];
        }
        for (int i = 0; i < m; i++)
        {
            cin>>b[i];
        }
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        auto cmp=[](pair<int,int> a,pair<int,int> b){
            if(a.first!=b.first){return a.first>b.first;}
            else{return a.second>b.second;}
        };
        
        multiset<pair<int,int>,decltype(cmp)> diff(cmp);
        vector<int> diff0,diff1;
        int i1=0;int i2=n-1;
        while(i1<i2){
            diff.emplace(a[i2]-a[i1],1);
            diff1.emplace_back(a[i2]-a[i1]);
            i1++;i2--;
        }
        i1=0;i2=m-1;
        while(i1<i2){
            diff.emplace(b[i2]-b[i1],0);
            diff0.emplace_back(b[i2]-b[i1]);
            i1++;i2--;
        }
       
        vector<int> pre0(diff0.size()+1),pre1(diff1.size()+1);
        for (int i = 1; i < diff0.size()+1; i++)
        {
            pre0[i]=pre0[i-1]+diff0[i-1];
        }
        for (int i = 1; i < diff1.size()+1; i++)
        {
            pre1[i]=pre1[i-1]+diff1[i-1];
        }
        // for(auto i: pre0){
        //     cout<<i<<" ";
        // }
        // cout<<endl;
        // for( auto i: pre1){
        //     cout<<i<<" ";
        // }
        // cout<<endl;
        int kmax=min((m+n)/3,min(m,n));
        vector<int> ans;
        vector<int> v(2);
        auto itr=diff.begin();
        int p=diff.size();
        vector<int> v0(p+1),v1(p+1),sum(p+1),pre(p+1);
        pre[0]=0;v0[0]=0;v1[0]=0;
        int idx=1;
        while(itr!=diff.end()){
            if((*itr).second==0){
                v0[idx]=v0[idx-1]+1;
                v1[idx]=v1[idx-1];
            }
            else{
                v1[idx]=v1[idx-1]+1;
                v0[idx]=v0[idx-1];
            }
            pre[idx]=(*itr).first+pre[idx-1];
            idx++;itr++;
        }
        for (int i = 0; i < p+1; i++)
        {
            sum[i]=v0[i]+v1[i];
        }
        // for( auto i: v0){
        //     cout<<i<<" ";
        // }
        // cout<<endl;
        // for(auto i : v1){
        //     cout<<i<<" ";
        // }
        // cout<<endl;


        for (int i = 1; i <= kmax; i++)
        {
            auto itr1=upper_bound(sum.begin(),sum.end(),i);
            itr1--;
            // auto itr2=upper_bound(v0.begin(),v0.end(),m-i);
            // itr2--;
            // auto itr3=upper_bound(v1.begin(),v1.end(),n-i);
            // itr3--;
            int j=itr1-sum.begin();
            if(v0[j]>m-i){
                ans.push_back(pre0[m-i]+pre1[2*i-m]);
            }
            else if(v1[j]>n-i){
                ans.push_back(pre1[n-i]+pre0[2*i-n]);
            }
            else{
            ans.push_back(pre[j]);
            }
        }
        cout<<kmax<<endl;
        for (int i = 1; i <= kmax; i++)
        {
            cout<<ans[i-1]<<" ";
        }
        cout<<endl;
        
        
    }
    return 0;
}

