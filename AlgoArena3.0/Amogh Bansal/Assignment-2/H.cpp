#include <bits/stdc++.h>

using namespace std;

const long long MOD = 1e9 + 7;
const long long inv2 = (MOD+1)/2;

map<int,int> pairs;
map<int,int> apairs;
map<pair<pair<int,int>,int>, long long> memo;

long long pos(int i, int j, int flag){
    pair<pair<int,int>,int> key = {{i,j},flag};
    if(memo.count(key)) return memo[key];
    long long res = 0;
    if(j == i+1){
        memo[key] = 2;
        return 2;
    }
    if(flag == 0){
        vector<long long> ans(2,0);
        ans[1] = 2;
        int k = i+1;
        while(k < j){
            long long c0 = pos(k,pairs[k],0);
            long long c1 = pos(k,pairs[k],1);
            long long n0 = (ans[0]*c0 + (ans[1]*c0 % MOD)*inv2) % MOD;
            long long n1 = (ans[0]*c1 + ans[1]*c1) % MOD;
            ans[0] = n0;
            ans[1] = n1;
            k = pairs[k] + 1;
        }
        res = (ans[0] + ans[1]) % MOD;
    }
    if(flag == 1){
        vector<long long> ans(2,0);
        ans[0] = 1;
        int k = i+1;
        while(k < j){
            long long c0 = pos(k,pairs[k],0);
            long long c1 = pos(k,pairs[k],1);
            long long n0 = (ans[0]*c0 + (ans[1]*c0 % MOD)*inv2) % MOD;
            long long n1 = (ans[0]*c1 + ans[1]*c1) % MOD;
            ans[0] = n0;
            ans[1] = n1;
            k = pairs[k] + 1;
        }
        res = (ans[0]*2 + (ans[1]*2) % MOD * inv2) % MOD;
    }
    memo[key] = res;
    return res;
}

int main(){
    string s;
    cin >> s;
    int n = s.size();
    vector<int>open;
    for(int i = 1; i <= n; i++){
        if (s[i-1]=='('){
            open.push_back(i);
        }
        else{
            int op = open.back();
            open.pop_back();
            pairs[op] = i;
            apairs[i] = op;
        }
    }
    vector<long long> ans(2,0);
    ans[0] = 1;
    int k = 1;
    while(k <= n){
        long long c0 = pos(k,pairs[k],0);
        long long c1 = pos(k,pairs[k],1);
        long long n0 = (ans[0]*c0 + (ans[1]*c0 % MOD)*inv2) % MOD;
        long long n1 = (ans[0]*c1 + ans[1]*c1) % MOD;
        ans[0] = n0;
        ans[1] = n1;
        k = pairs[k] + 1;
    }
    cout << (ans[0] + ans[1]) % MOD;
}
