#include <bits\stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<long long> v(n + 1, 0);
    vector<long long> u(n + 1, 0);
    vector<long long> prefsum_v(n + 1, 0);
    vector<long long> prefsum_u(n + 1, 0);

    for (int i = 1; i <= n; i++)
    {
        cin >> v[i];
        u[i] = v[i];
        prefsum_v[i] = prefsum_v[i - 1] + v[i];
    }

    sort(u.begin() + 1, u.end());

    for (int i = 1; i <= n; i++)
    {
        prefsum_u[i] = prefsum_u[i - 1] + u[i];
    }

    int m;
    cin >> m;
    while (m--)
    {
        int type, l, r;
        cin >> type >> l >> r;
        if (type == 1){
            cout << prefsum_v[r] - prefsum_v[l - 1] << "\n";
        }
        else{
            cout << prefsum_u[r] - prefsum_u[l - 1] << "\n";
        }
    }

    return 0;
}
