#include<bits/stdc++.h>
#include<vector>
 
using namespace std;

void solve()
{

    int n, m, x1, y1, x2, y2;
    cin >> n >> m >> y1 >> x1 >> y2 >> x2;
    if(y1 >= y2){cout << "Draw" << "\n"; return;}
    if((y2 - y1)%2){
        if(abs(x1 - x2) <= 1){cout << "Alice" << "\n"; return;}
        if(x1 > x2){
            if((x1 - 1) <= (((y2 - y1) + 1)/2)){cout << "Alice" << "\n"; return;}
        }
        else if(x2 > x1){
            //cout << (m - x1) << " " << (((y2 - y1) + 1)/2) << "\n";
            if((m - x1) <= (((y2 - y1) + 1)/2)){cout << "Alice" << "\n"; return;}
        }
    }
    else{
        if(x1 == x2){cout << "Bob" << "\n"; return;}
        if(x2 > x1){
            if((x2 - 1) <= (((y2 - y1))/2)){cout << "Bob" << "\n"; return;}
        }
        else if(x2 < x1){
            if((m - x2) <= (((y2 - y1))/2)){cout << "Bob" << "\n"; return;}
        }
    }
    cout << "Draw" << "\n";

}
 
int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);    

    //int t = 1;
    int t; cin >> t;
    for(int i = 0; i < t; i++) {solve();}

    return 0;

}