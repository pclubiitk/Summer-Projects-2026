#include<bits/stdc++.h>
using namespace std;
# define vecin(n,a) vector<int> a(n); for(int i=0;i<n;i++){cin>>a[i];}
# define vecout(a)  for(auto i: a){cout<<i<<" ";} cout<<endl;
# define int long long int
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    vector<pair<double,double>> vec(n);
    for (int i = 0; i < n; i++)
    {
        cin>>vec[i].first;
    }
    double slow=1e9;
    for (int i = 0; i < n; i++)
    {
        cin>>vec[i].second;
        slow=min(slow,vec[i].second);
    }
    sort(vec.begin(),vec.end());
    double up=(vec[n-1].first-vec[0].first)/(slow);
    double lo=0;
    for (int i = 0; i < 100; i++)
    {
        double mid=lo+(up-lo)/2;
        vector<double> left(n),right(n);
        left[0]=vec[0].first+mid*vec[0].second;
        right[n-1]=vec[n-1].first-mid*vec[n-1].second;
        for (int j = 1; j< n; j++)
        {
            left[j]=min(left[j-1],vec[j].first+mid*vec[j].second);
        }
        for (int j = n-2; j >-1; j--)
        {
            right[j]=max(right[j+1],vec[j].first-mid*vec[j].second);
        }
        int flag=0;
        for (int j = 0; j < n-1; j++)
        {
            if((right[j+1]<=vec[j+1].first)&&(left[j]>=vec[j].first)&&(left[j]>=right[j+1])){
                flag=1;
                break;
            }
        }
        if(flag==1){
            up=mid;
        }
        else{
            lo=mid;
        }
    }
    
    cout<<setprecision(16)<<lo<<endl;
}
