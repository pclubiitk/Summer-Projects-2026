#include<bits/stdc++.h>
#include<vector>
 
using namespace std;

struct seg{

    int l;
    int r;

    seg(int L, int R){

        l = L;
        r = R;

    }

    bool operator<(const seg& a) const {
        
        if(r - l != a.r - a.l){

            return ((r - l) - (a.r - a.l) > 0 ); 

        }
        else{

            return ((l - a.l) < 0);

        }

    }

};

void solve()
{

    int n; cin >> n;
    vector<int> out(n);


    seg cur(0, n);
    set<seg> q = {cur};
    auto it = q.begin();

    for(int i = 1; i <= n; i++){

        seg temp = *it;
        int idx = (temp.l + temp.r - 1)/2;
        out[idx] = i;

        if(temp.l != idx){

            seg cur1(temp.l, idx);
            q.insert(cur1);

        }

        if(temp.r != idx + 1){

            seg cur1(idx + 1, temp.r);
            q.insert(cur1);

        }

        //for(auto some = q.begin(); some != q.end(); some++){cout << some->l << " " << some->r << "\n";}cout << "--\n";

        it++;

    }

    for(int i = 0; i < n; i++){

        cout << out[i] << " ";

    }cout << "\n";

}
 
int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);    

    //int t = 1;
    int t; cin >> t;
    for(int i = 0; i < t; i++) {solve();}

    return 0;

}