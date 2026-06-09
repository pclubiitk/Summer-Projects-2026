#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string t,p; cin>>t>>p;
    int n = t.size();
    vector<int> a(n);

    for(int &x : a) cin>>x;
    vector<int> freq(n+1,0);
    for(int i=0;i<n;i++) freq[a[i]] = i+1;

    int s=1,e = n - p.size();
    int ans = 0;
    while(s<=e){
        int mid = s + (e-s)/2;
        int i=0,j=0;
        while(j<p.size() && i<n){
            if(freq[i+1]<=mid) i++;
            else if(p[j]==t[i]){
                i++;j++;
            }
            else i++;
        }
        if(j==p.size()){
            ans = mid;
            s = mid+1;
        }
        else e = mid-1;
    }
    cout<<ans;
}
