#include <bits/stdc++.h>
using namespace std;
using ll = long long;

long double min(long double a, long double b) {
    if (a<b) {
        return a;
    }
    else {
        return b;
    }
}

long double max(long double a, long double b) {
    if (a>b) {
        return a;
    }
    else {
        return b;
    }
}

void solve() {
    ll n,m;
    cin>>n>>m;
    vector<ll> num(n+1,0);
    vector<ll> counter(100001,0);
    for (int i=1;i<=n;i++) {
        cin>>num[i];
        counter[num[i]]++;
    }
    num[0]=-1e18;
    sort(num.begin(),num.end());
    /*for (int i=1;i<=n;i++) {
        for (int j=1;j<=n;j++) {
            cout<<i<<","<<j<<": "<<num[i]+num[j]<<" ";
        }
        cout<<'\n';
    }*/
    vector<ll> prefixfromright(n+2,0);
    for (int i=n;i>=1;i--) {
        prefixfromright[i]=prefixfromright[i+1]+num[i];
    }
    ll min=1;
    ll max=1e10;
    ll best=1;
    while (min<=max) {
        ll mid = (min+max)/2;
        ll count{0};
        ll score{0};
        ll mintermtaken=1e18;
        ll countofminterm=0;
        for (int i=1;i<=n;i++) {
            ll mintotake;
            mintotake=mid-num[i];
            auto it = lower_bound(num.begin(),num.end(),mintotake);
            auto index = it-num.begin();
            if (index<=n && index>=1) {
                count+=(n+1)-index;
                score+=(n+1-index)*num[i]+prefixfromright[index];
                if (num[index]+num[i]<mintermtaken) {
                    mintermtaken=num[index]+num[i];
                }
            }
        }
        map<ll,ll> countertemp;
        for (int i=1;i<=n;i++) {
            countofminterm+=2*countertemp[(mintermtaken-num[i])];
            countertemp[num[i]]++;
            if ((mintermtaken-num[i])%2==0 && (mintermtaken-num[i])==num[i]) {
                countofminterm++;
            }
        }
        if (countofminterm>0) {
            if (count-countofminterm<=m) {
                max=mid-1;
                if (count>m) {
                    ll normalterms = count-countofminterm;
                    score-=countofminterm*mintermtaken;
                    score+=(m-normalterms)*mintermtaken;
                    if (score>best) {
                        best=score;
                    }
                }
                else {
                    if (score>best) {
                        best=score;
                    }
                }
            }
            else {
                min=mid+1;
            }
        }
        else {
            if (count<=m) {
                max=mid-1;
                if (score>best) {
                    best=score;
                }
            }
            else {
                min=mid+1;
            }
        }
    }
    cout<<best<<'\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t=1;
    //cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
