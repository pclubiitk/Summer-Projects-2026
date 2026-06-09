#include<bits/stdc++.h>
using namespace std;
# define vecin(n,a) vector<int> a(n); for(int i=0;i<n;i++){cin>>vec[i];}
# define vecout(a)  for(auto i: a){cout<<i<<" ";} cout<<endl;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin>>T;
    for(int t=0;t<T;t++){
        int n;
        cin>>n;
        string str;
        cin>>str;
        vector<int> vec(n);
        vector<int> pre(n);
        for (int i = 0; i < n; i++)
        {
            vec[i]=str[i]-'1';
        }
        pre[0]=vec[0];
        for (int i = 1; i < n; i++)
        {
            pre[i]=vec[i]+pre[i-1];
        }
        vector<int> num(9*(1e5)+1);num[1e5]=1;
        long long int ans=0;
        for (int i = 0; i < n; i++)
        {   int a=pre[i];
            a+=(1e5);
            ans+=(num[a]);
            num[a]++;
        }
        cout<<ans<<endl;
    }
    return 0;
}

