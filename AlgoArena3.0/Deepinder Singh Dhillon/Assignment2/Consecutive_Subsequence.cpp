#include<bits/stdc++.h>
using namespace std;
# define int long long int

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    vector<int> vec(n);
    for (int i = 0; i < n; i++)
    {
        cin>>vec[i];
    }
    map<int,int> ml;

    for (int i = 0; i < n; i++)
    {   
        if(ml.count(vec[i])==0){ml[vec[i]]=1;}
        ml[vec[i]]=max(ml[vec[i]],(ml.count(vec[i]-1)==1?ml[vec[i]-1]:0)+1);
    }
    int le=-1;
    int most=-1;
    
    for( auto &[l,r]: ml){

        if(r>most){
            le=l;
            most=r;
        }
    }
    cout<<most<<endl;
    vector<int> ans;
    for (int i = n-1; i >-1; i--)
    {
        if(vec[i]==le){
            ans.emplace_back(i+1);
            le--;
        }
    }
    reverse(ans.begin(),ans.end());
    for(int i: ans){
        cout<<i<<" ";
    }
    cout<<endl;
    return 0;
}

