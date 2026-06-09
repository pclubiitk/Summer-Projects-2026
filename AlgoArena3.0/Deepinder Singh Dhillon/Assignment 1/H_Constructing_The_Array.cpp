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
        int n;
        cin>>n;
        vector<int> vec(n);
        auto cmp=[](pair<int,int> a,pair<int,int> b)
        {   if(a.first!=b.first){return a.first>b.first;}
            else{
                return ((a.second)<(b.second));
            }
        };
        set<pair<int,int>,decltype(cmp)> s(cmp);
        s.emplace(n,(n-1)/2);
        for (int i = 1; i <= n; i++)
        {
            auto itr=s.begin();
            auto p=*itr;
            vec[itr->second]=i;
            s.erase(itr);
            if(p.first%2==0){
                int l1=(p.first-1)/2;
                int m=p.second;
                s.emplace(l1,((m-l1)+(m-1))/2);
                s.emplace(l1+1,((m+1)+(m+l1+1))/2);
            }
            else{
                int l1=(p.first-1)/2;
                int m=p.second;
                s.emplace(l1,((m-l1)+(m-1))/2);
                s.emplace(l1,((m+l1)+(m+1))/2);
            }
        }
        for (int i = 0; i < n; i++)
        {
            cout<<vec[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}

