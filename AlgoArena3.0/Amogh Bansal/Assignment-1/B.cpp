#include <bits/stdc++.h>

using namespace std;

int possible(const string& t, const string& p, const vector<int>& removed){
    int i = 0;
    for(int j = 0; j < t.length(); j++){
        if(removed[j]) continue;
        if(t[j]==p[i]) i++;
        if(i==p.length()) return 1;
    }
    return 0;
}


int main(){
    string p,t;
    int a;
    cin >> t >> p;
    int tlen = t.length();
    vector<int> perm;
    for(int i = 0; i < tlen; i++){
        cin >> a;
        perm.push_back(a);
    }
    int l = 0, r = tlen-1;
    while (l < r){
        int mid = l + (r-l)/2 ;
        vector<int> removed(tlen,0);
        for(int i = 0; i <= mid; i++){
            removed[perm[i]-1] = 1;
        }
        if(possible(t,p,removed)) l = mid+1;
        else r = mid;
    }

    cout << r;

}
