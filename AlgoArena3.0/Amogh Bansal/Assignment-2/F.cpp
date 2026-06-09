#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    int a;
    vector<int> arr;
    for(int i = 0; i < n; i++){
        cin >> a;
        arr.push_back(a);
    }
    vector<int> temp = arr;
    sort(temp.begin(), temp.end());
    temp.erase(unique(temp.begin(), temp.end()), temp.end());

    for(int& x:arr){
        x = lower_bound(temp.begin(), temp.end(), x) - temp.begin();
    }
    vector<int> pre(n+1,0);
    pre[arr[0]] = 1;
    for(int i = 1; i < n; i++){
        if(arr[i] && (temp[arr[i]-1] + 1 == temp[arr[i]])){
            pre[arr[i]] = pre[arr[i]-1]+1;
        }
        else pre[arr[i]] = 1;
    }
    int d = 0;
    int idx;
    for(int i = 0; i < n; i++){
        if (d < pre[i]){
            d = pre[i];
            idx = i;
        }
    }
    //cout << "idx " << idx << "d " << d << '\n';
    vector<int> ans;
    int cur_idx = idx;
    for(int i = n-1; i >= 0; i--){
        if(arr[i] == cur_idx){
            ans.push_back(i+1);
            cur_idx--;
        }
        if(cur_idx == idx-d) break;
    }   
    cout << d << '\n';
    reverse(begin(ans), end(ans));
    for(int i : ans){
        cout << i << " ";
    }


}
