// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
	ll t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string f,s;
        cin>>f>>s;
        // cout<<f<<s<<endl;
        ll same=0, opp=0;
        for(int i=0;i<n; i++){
            if(f[i]==s[i]) same++;
        }
        for(int i=0;i<n; i++){
            if(f[i]==s[n-1-i]) opp++;
        }
        // cout<<same<<" "<<opp<<endl;
        ll h1,h2;
         if(n==same) h1=(n-same);
       else if((n-same)%2==0) h1=(n-same)*2;
        // else if(n==same) h1=(n-same);
        else h1=(n-same)*2-1;
        if(n==opp) h2=(n-opp)+2;
        else if((n-opp)%2==0) h2=(n-opp)*2-1;
        // else if(n==opp) h2=(n-opp)+2;
        else h2=(n-opp)*2;
        cout<<min(h1,h2)<<endl;

        

    }
}
