#include <bits\stdc++.h>
using namespace std;

const int MAX_PRIME = 1000000;
vector<bool> is_prime(MAX_PRIME + 1, true);

void sieve() {
    is_prime[0] = is_prime[1] = false;
    for (int p = 2; p * p <= MAX_PRIME; p++) {
        if (is_prime[p]) {
            for (int i = p * p; i <= MAX_PRIME; i += p) {
                is_prime[i] = false;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    sieve();

    int n; cin>>n;
        while (n--) {
            long long x;
            cin >> x;

            long long r = round(sqrt(x));

            if (r * r == x && is_prime[r]) {
                cout << "YES\n";
            } else {
                cout << "NO\n";
            }
        }

    return 0;
}
