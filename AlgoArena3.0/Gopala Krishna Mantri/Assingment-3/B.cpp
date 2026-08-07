#include<bits/stdc++.h>
#include<vector>
 
using namespace std;

void solve()
{

    int n; cin >> n;
    string s, t; cin >> s >> t;
    //string s_ = s; reverse(s_.begin(), s_.end());
    
    int ret1 = 0; int ret2 = 0;
    for(int i = 0; i < n; i++){
        if(s[i] != t[i]){ret1++;}
        if(s[n-1-i] != t[i]){ret2++;}
    }
    int r1;
    if((ret1%2)){r1 = (ret1*2) - 1;}
    else{r1 = ret1*2;}
    int r2;
    if(!(ret2%2)){if(ret2){r2 = ret2*2 - 1;}else{r2 = 2;}}
    else{r2 = ret2*2;}
    //cout << ret1 << " " << ret2 << " " << r1 << " " << r2 << "\n";
    cout << min(r1,r2) << "\n";
}
 
int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);    

    //int t = 1;
    int t; cin >> t;
    for(int i = 0; i < t; i++) {solve();}

    return 0;

}