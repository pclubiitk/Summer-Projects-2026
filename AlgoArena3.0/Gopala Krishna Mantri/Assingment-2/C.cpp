#include<bits/stdc++.h>
#include<vector>
 
using namespace std;

pair<int, int> f(long long int n){

    long long int k = n;
    pair<int, int> ret = {0 , 0};

    while(!(k%2)){

        k/=2;
        ret.first++;

    }

    while(!(k%5)){

        k/=5;
        ret.second++;

    }

}

void solve()
{

    int n, k; cin >> n >> k; 
    vector<long long int> a(n); for(int i = 0; i < n ; i++){cin >> a[i];}


}
 
int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);    

    //int t = 1;
    int t; cin >> t;
    for(int i = 0; i < t; i++) {solve();}

    return 0;

}