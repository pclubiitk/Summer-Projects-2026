#include<bits/stdc++.h>
using namespace std;

# define int long long int
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;

    vector<int> vec(n);map<int,int> freq;
    for (int i = 0; i < n; i++)
    {
        cin>>vec[i];
        freq[vec[i]]++;
    }
    int m=freq.size();
    vector<int> dp(m);
    auto itr=freq.begin();
    auto prev1=itr;
    int idx=0;
    dp[0]=((itr->first)*(itr->second));
    itr++;idx++;
    while(itr!=freq.end()){
        if(itr->first!=(prev1->first)+1){
            dp[idx]=dp[idx-1];
            dp[idx]+=((itr->first)*(itr->second));
            itr++;
            prev1++;
            idx++;
            continue;
        }
        dp[idx]=max((idx==1?0:dp[idx-2])+((itr->first)*(itr->second)),dp[idx-1]);
        itr++;
        prev1++;
        idx++;
    }
    
    cout<<dp[m-1]<<endl;

    return 0;
}

