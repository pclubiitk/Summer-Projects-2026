#include<bits/stdc++.h>
#include<vector>
 
using namespace std;

void solve()
{

    int n; cin >> n;
    int temp;
    int cnt[] = {0, 0};
    for(int i = 0; i < n; i++){cin >> temp; cnt[((temp%2)+2)%2]++;}
    
    int j = cnt[1]%4;
    if(j == 1){
        cout << ((cnt[0]%2) ? "Alice" : "Bob") << "\n"; return;
    }
    if(j == 2){
        cout << "Bob" << "\n"; return;
    }
    if(j == 3){
        cout << "Alice" << "\n"; return;
    }
    if(j == 0){
        cout << "Alice" << "\n"; return;
    }

}
 
int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);    

    //int t = 1;
    int t; cin >> t;
    for(int i = 0; i < t; i++) {solve();}

    return 0;

}