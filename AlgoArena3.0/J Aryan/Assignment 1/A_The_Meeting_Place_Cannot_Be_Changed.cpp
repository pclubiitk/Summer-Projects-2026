#include <bits/stdc++.h>
using ll = long long;
using namespace std;

bool pos(double maxm, vector<double> &x, vector<double> &v){
    double r1 = x[0] + maxm*v[0], l1 = max(x[0] - maxm*v[0], 1.0);
    
    bool b1=true;
    for(int i=1;i<x.size() && b1;i++){
        double ux = x[i];
        if(l1<=ux && ux<=r1){
            l1 = max(l1,ux-maxm*v[i]);
            r1 = min(r1,ux+maxm*v[i]);
        }
        if(r1<ux){
            ux = ux - maxm*v[i];
            if(r1<ux) b1=false;
            else l1 = max(l1,ux);
        }
        else if(ux<l1){
            ux = ux + maxm*v[i];
            if(ux<l1) b1=false;
            else r1 = min(r1,ux);
        }
    }
    return b1;
}
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin>>n;
    vector<double> x(n), v(n);
    double l=1e9, r=0;
    for(auto &t : x){
        cin>>t;
        l = min(l,t);
        r = max(r,t);
    }
    for(auto &t : v) cin>>t;
    
    double s=0, e = (r-l);
    double ans = e;
    for(int i=0;i<100;i++){
        double mid = s + (e-s)/2;
        if(pos(mid,x,v)){
            e = mid;
            ans = mid;
        }
        else {
            s = mid;
        }
    }
    cout << fixed << setprecision(7) << ans;
    return 0;
}
