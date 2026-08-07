#include<bits/stdc++.h>
#include<vector>
 
using namespace std;

long long int sq(long long int n){

    return n*n;

}

void solve()
{

    long long int d, k; cin >> d >> k;

    long long int x= 0, y = 0;
    bool a = true;
    while(sq(d) >= sq(k)*(sq(x) + sq(y))){
        if(a){x++;}
        else{y++;}
        a = !a;
    }
    //cout << x << " " << y << "\n";
    cout << ((!a) ? "Utkarsh" : "Ashish") << "\n";

}
 
int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);    

    //int t = 1;
    int t; cin >> t;
    for(int i = 0; i < t; i++) {solve();}

    return 0;

}