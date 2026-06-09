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
        string str;
        cin>>str;
        vector<int> vec(n);
        for (int i = 0; i < n; i++)
        {
            vec[i]=(str[i])-'0';
        }
        vector<int> pre(n+1),suf(n+1);
        for (int i = 1; i < n+1; i++)
        {
            pre[i]=vec[i-1]+pre[i-1];
        }
        for (int i = n-1; i >-1; i--)
        {
            suf[i]=vec[i]+suf[i+1];
        }
        
        vector<int> chng(n);
        for (int i = 0; i < k; i++)
        {
            chng[i]=(vec[i]!=1)+pre[i];
        }
        for (int i = k; i < n; i++)
        {
            chng[i]=chng[i-k]+(vec[i]!=1)+pre[i]-pre[i-k+1];
        }
        vector<int> most(n);
        for (int i = 0; i < k; i++)
        {
            most[i]=chng[i]-pre[i]-(vec[i]!=1);
        }
        for (int i = k; i < n; i++)
        {
            most[i]=max(most[i-k],chng[i]-pre[i]-(vec[i]!=1));
        }
        int ans=pre[n];
        for (int i = 0; i < n; i++)
        {
            ans=min(ans,chng[i]+suf[i+1]-most[i]);
        }
        cout<<ans<<endl;
    }
    return 0;
}

