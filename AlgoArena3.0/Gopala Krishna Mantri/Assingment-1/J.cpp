#include<bits/stdc++.h>
#include<vector>
 
using namespace std;

void solve()
{

    long long int n, k;
    cin >> n >> k;

    bool out = false;

    if(n%3 && k%3){out = true;}

    if(!(k%3)){

        n %= (k+1);

        if(n%3){out = true;}

        if(n == k){

            out = true;

        }

    }

    cout << (out ? "Alice" : "Bob") << "\n";


}
 
int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);    

    //int t = 1;
    int t; cin >> t;
    for(int i = 0; i < t; i++) {solve();}

    return 0;

}