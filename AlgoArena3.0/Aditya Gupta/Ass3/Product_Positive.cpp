#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector <int> a (n);
        int k = 0;
        int last = 0;
        for(int i = 0; i < n; i++) {
            cin >> a[i];
            if(a[i] == -1){
                last = i;
                k++;
            }
        }
        if(n == 1){
            if(a[0] == 1){
                std::cout << "Alice" << std::endl;
                std::cout << 1 << ' ' << 1 << std::endl;
            }else{
                std::cout << "Bob" << std::endl;
            }
            continue;
        }
        if(k == 1 && last == n - 1 - last){
            cout << "Bob" << '\n';
            continue;
        }
        if(k % 2){
            if(a[n - 1] == -1){
                std::cout << "Alice" << std::endl;
                std::cout << 1 << ' ' << n - 1 << std::endl;
            }else if(a[0] == -1){
                std::cout << "Alice" << std::endl;
                std::cout << 2 << ' ' << n << std::endl;
            }else{
                std::cout << "Alice" << std::endl;
                int first = 0;
                for(int i = 0; i < n; i++){
                    if(a[i] == -1){
                        first = i;
                        break;
                    }
                }
                int l = first;          
                int r = n - 1 - last;  
                int m = min(l, r);
                if(l <= r){
                    cout << l + 2 << ' ' << n - m << '\n';
                }else{
                    cout << m + 1 << ' ' << last << '\n';
                }
            }   
        }else{
            std::cout << "Alice" << std::endl;
            std::cout << 1 << ' ' << n << std::endl;
        }    
    }
}
