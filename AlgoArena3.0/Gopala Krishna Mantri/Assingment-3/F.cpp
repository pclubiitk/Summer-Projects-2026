#include<bits/stdc++.h>
#include<vector>
 
using namespace std;

int z(int n){

    int cur = n;
    int ret = 0;
    while(!(cur%10)){ret++; cur/=10;}
    return ret;

}

int dig(int n){

    return (int)(log10(n) + 1);

}

void solve()
{

    vector<int> del;
    int n; cin >> n;
    int t = 0;
    int m; cin >> m; m++;
    int temp;
    for(int i = 0; i < n; i++){
        cin >> temp;
        t += dig(temp);
        del.push_back(z(temp));
    }
    sort(del.begin(), del.end());
    reverse(del.begin(), del.end());
    for(int i = 0; i < del.size(); i += 2){
        t -= del[i];
    }
    cout << ((t >= m) ? "Sasha" : "Anna") << "\n";

}
 
int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);    

    //int t = 1;
    int t; cin >> t;
    for(int i = 0; i < t; i++) {solve();}

    return 0;

}