#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> vec(n);
    for (int i = 0; i < n; i++)
    {
        cin>>vec[i];
    }
    vector<int> srt=vec;
    sort(srt.begin(),srt.end());
    vector<long long int> p1(n+1),p2(n+1);
    for (int i = 0; i < n; i++)
    {
        p1[i+1]=vec[i]+p1[i];
        p2[i+1]=srt[i]+p2[i];
    }
    int m;
    cin>>m;
    for (int i = 0; i < m; i++)
    {
        int t,l,r;
        cin>>t>>l>>r;
        if(t==1){
            cout<<p1[r]-p1[l-1]<<endl;
        }
        else{
            cout<<p2[r]-p2[l-1]<<endl;
        }
    }
    return 0;
    
}
