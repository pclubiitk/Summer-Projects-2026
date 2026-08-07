#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
    int t;
    cin>>t;
    while(t--){
        int n,x;
        cin>>n>>x;
        int num=0;
        vector<array<int,2>> v(n);
        for(int i=0; i<n-1; i++){
            cin>>v[i][0]>>v[i][1];
            if (v[i][0]==x || v[i][1]==x) {
                num++;
            }
        }
        if(n==1){ cout<<"Ayush"<<endl; continue;}
        if(num==1) cout<<"Ayush"<<endl;
        else if((n-2)%2==0){
            cout<<"Ayush"<<endl;
        }
        else cout<<"Ashish"<<endl;

    }
}