#include <bits/stdc++.h>
using namespace std;

const int MOD = 100000000;

int f[105][105];
int h[105][105];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n1, n2, k1, k2;
    cin >> n1 >> n2 >> k1 >> k2;

    f[0][0] = h[0][0] = 1;

    for (int i = 0; i <= n1; i++) {
        for (int j = 0; j <= n2; j++) {

            if (i == 0 && j == 0) continue;

            for (int t = 1; t <= k1; t++) {
                if (i - t < 0) break;
                f[i][j] = (f[i][j] + h[i - t][j]) % MOD;
            }

            for (int t = 1; t <= k2; t++) {
                if (j - t < 0) break;
                h[i][j] = (h[i][j] + f[i][j - t]) % MOD;
            }
        }
    }

    cout << (f[n1][n2] + h[n1][n2]) % MOD << '\n';
}
