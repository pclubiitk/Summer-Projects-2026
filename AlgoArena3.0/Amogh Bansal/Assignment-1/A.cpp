#include <bits/stdc++.h>

using namespace std;


double time(vector<int>& pos, vector<int>& speeds, double t, int n){
    double ans = 0;
    for(int i = 0; i < n; i++){
        ans = max(ans, abs(pos[i] - t) / (double) speeds[i]);
    }
    return ans;
}

int deriv(vector<int>& pos, vector<int>& speeds, int t, int n){
    return (time(pos, speeds, t+1, n) >= time(pos, speeds, t, n) ? 1 : -1);
}

int s_deriv(vector<int>& pos, vector<int>& speeds, double t, int n){
    double maxval = 0;
    int  idx = 0;
    //double slope = 0;
    for(int i = 0; i < n; i++){
        double val = abs(pos[i] - t) / (double) speeds[i];
        if (val > maxval){
            maxval = val; 
            idx = i;
        }
    }
    return (t >= pos[idx]) ? 1:-1;
}


int main(){
    int n;
    int x,v;
    int a;
    cin >> n;
    vector<int> pos;
    vector<int> speeds;
    for(int i = 0; i < n; i++){
        cin >> a;
        pos.push_back(a);
    }
    for(int i = 0; i < n; i++){
        cin >> a;
        speeds.push_back(a);
    }
    /*
    for(int i = *min_element(pos.begin(), pos.end()); i <= *max_element(pos.begin(), pos.end()); i++){
        cout << deriv(pos, speeds, i, n) << ' ';
    }
    */
    //cout << endl;
    double l = *min_element(pos.begin(), pos.end()),  r = *max_element(pos.begin(), pos.end());
    while (r - l > 1e-9){
        double mid = l + (r-l)/2 ;
        if(mid == l || mid == r) break;
        if(s_deriv(pos, speeds, mid, n) < 0) l = mid;
        else r = mid;
    }
    //cout << r << endl;
    cout << fixed << setprecision(9) << min(time(pos, speeds, r, n), time(pos, speeds, l, n));

}
