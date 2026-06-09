#include <bits/stdc++.h>

using namespace std;

int f(vector<int> arr, int m, int k){
    int n = arr.size();
    vector<int> parr(n+1);
    for(int i = 0; i < n; i++){
        arr[i] = (arr[i] < m) ? -1:1;
        if(i) parr[i] = parr[i-1] + arr[i];
        else parr[i] = arr[i];
    }
    int mvl = 0;
    int vmin = 0;
    if(parr[k-1] > 0) return 1;
    for(int i = k; i < n; i++){
        vmin = min(vmin, parr[mvl]);
        mvl++;
        if((parr[i] - vmin) > 0){
            return 1;
        }
    }
    return 0;

}

int main(){
    int n,k,a;
    cin >> n >> k;
    vector<int> arr;
    for(int i = 0; i < n; i++){
        cin >> a;
        arr.push_back(a);
    }
    int l = 0,r = *max_element(arr.begin(), arr.end()) + 1;
    while (l < r){
        int mid = l + (r-l)/2;
        if(f(arr, mid, k)) l = mid+1;
        else r = mid;
    }
    cout << r-1;


}
