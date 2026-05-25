#include<bits/stdc++.h>
#include<vector>
 
using namespace std;

void solve()
{

    int n; cin >> n;

    vector<pair<long long int, long long int>> people(n);

    for(int i = 0; i < n; i++){cin >> people[i].first;}
    for(int i = 0; i < n; i++){cin >> people[i].second;}

    double l = -1e18f;
    double r = 1e18f;

    while(r - l >= 1e-6){

        double mid = l + (r - l)/2;

        double lmax = -1e18f;

        for(int i = 0; i < n; i++){

            lmax = max(lmax, ((double)(people[i].first - (mid)*(people[i].second))));

        }

        double rmin = 1e18f;

        for(int i = 0; i < n; i++){

            rmin = min(rmin , ((double)(people[i].first + (mid)*(people[i].second))));

        }

        if(rmin > lmax){

            r = mid;

        }

        else{

            l = mid;

        }

    }

    cout << fixed << setprecision(9) << l << "\n";

}
 
int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);    

    int t = 1;
    //int t; cin >> t;
    for(int i = 0; i < t; i++) {solve();}

    return 0;

}