#include <bits/stdc++.h>

using namespace std;

long long count(vector<int>& arr, int v){
    int n = arr.size();
    long long cnt = 0;
    //long long s = 0;
    for(int a:arr){
        int l = 0, r = n;
        while(l < r){
            int mid = l + (r-l)/2;
            if (arr[mid] + a >= v) l = mid+1;
            else r = mid;
        }
        cnt += r;
    }
    return cnt;
}

int main(){
    int n,a;
    long long m;
    cin >> n >> m;
    vector<int> arr;
    for(int i = 0; i < n; i++){
        cin >> a;
        arr.push_back(a);
    }
    sort(arr.begin(), arr.end(), greater<int>());

    int l = arr[n-1] + arr[n-1], r = arr[0] + arr[0] + 1;
    while (l < r){
        int mid = l + (r-l)/2;
        if(count(arr,mid) < m) r = mid;
        else l = mid + 1;
    }

    vector<long long> parr(n);
    parr[0] = arr[0];
    for(int i = 1; i < n; i++){
        parr[i] = parr[i-1] + arr[i];
    }
    int p = r;
    long long ans = 0;
    long long t = 0;
    for(int a:arr){
        int l = 0, r = n;
        while(l < r){
            int mid = l + (r-l)/2;
            if(a + arr[mid] >= p) l = mid+1;
            else r = mid;
        }
        if(r > 0){
            ans += (long long)r * a + parr[r-1];
            t+=r;
        }
    }
    long long tt = m - t;
    ans += (tt * (long long)(p-1));
    cout << ans;
}
