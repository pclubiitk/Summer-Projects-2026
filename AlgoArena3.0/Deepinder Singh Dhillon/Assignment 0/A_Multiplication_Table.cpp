#include<bits/stdc++.h>
using namespace std;

pair<long long int,long long int> find_pos(long long int n,long long int m,long long int t){
    vector<long long int> small;
   
    long long pos=0;
    long long int r=1;long long int c=m;
    while(r<n+1&&c>0){
        if(r*c<=t){
            pos+=c;
            small.emplace_back(r*c);
            r++;
        }
        else if(r*c>t){
            c--;
        }
    }
    sort(small.begin(),small.end());
    long long a=*(small.rbegin());
    return {pos,a};
}
int main(){
    long long n,m,k;
    cin>>n>>m>>k;
    long long l=0;
    long long u=n*m+1;
    while(u-l>1){
        long long int mid=(u+l)/2;
        pair<long long ,long long > pp=find_pos(n,m,mid);
        if(pp.first<k){
            l=mid;
        }
        else {
            u=mid;
        }
    }
    cout<<u<<endl;
    return 0;
}
