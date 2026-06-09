#include<bits/stdc++.h>
using namespace std;
# define vecin(n,a) vector<int> a(n); for(int i=0;i<n;i++){cin>>a[i];}
# define vecout(a)  for(auto i: a){cout<<i<<" ";} cout<<endl;
# define int long long int
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N,Q;
    cin>>N>>Q;
    map<int,int> m1;
    m1[0]=0;
    for (int i = 0; i < N; i++)
    {
        int l,r,v;
        cin>>l>>r>>v;
        m1[l]+=v;m1[r]-=v;
    }
    int val=0;
    map<int,int> m2;
    for(auto i: m1){
        val+=(i.second);
        m2.emplace(i.first,val);
    }
    // for(auto i: m2){
    //     cout<<i.first<<" "<<i.second<<endl;
    // }
    cout<<endl;
    map<int,int> m3;
    m3[0]=0;
    int prefix=0;
    auto itr=m2.begin();
    pair<int,int> prev=*itr;
    itr++;
    while(itr!=m2.end()){
        prefix+=((itr->first)-(prev.first))*prev.second;
        m3[itr->first]=prefix;
        prev = *itr;
        itr++;
    }
    for (int i = 0; i < Q; i++)
    {
        int l,r;
        cin>>l>>r;
        auto itrl=m3.upper_bound(l);itrl--;
        auto itrr=m3.upper_bound(r);itrr--;
        int ans=itrr->second-itrl->second;
        ans+=(r-itrr->first)*(m2[itrr->first]);
        ans-=(l-itrl->first)*(m2[itrl->first]);
        cout<<ans<<endl;
    }
    return 0;
    
}
