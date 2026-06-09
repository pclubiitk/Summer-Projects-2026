#include<bits/stdc++.h>
using namespace std;
void sieve(vector<bool>& primes){
    for (int i = 2; i <1e6+1 ; i++)
    {
        if(primes[i]==1){continue;}
        for (int j = 2*i; j < 1e6+1; j+=i)
        {
            primes[j]=1;
        }
    }
}
int main(){
    int n;
    cin>>n;
    vector<long long int> vec(n);
    for (int i = 0; i < n; i++)
    {
        cin>>vec[i];
    }
    vector<bool> primes(1e6+1);
    sieve(primes);primes[1]=1;
    for (int i = 0; i < n; i++)
    {   if(vec[i]<4){cout<<"NO"<<endl;continue;};
        long long int a=pow(vec[i],0.5);
        // cout<<a<<endl;
        if((primes[a]==0)&&(a*a==vec[i])){
            cout<<"YES"<<endl;
        }
        else if(a!=1e6&&(primes[a+1]==0)&&((a+1)*(a+1)==vec[i])){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
    }
    return 0;
}
