#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
    int t;
    cin >> t;

    while (t--) {
        ll h, w, xA, yA, xB, yB;
        cin >> h >> w >> xA >> yA >> xB >> yB;
        bool win = false;
        string winner;
        if ((xA - xB) % 2 == 0) {
            winner = "Bob";
            if (xA >= xB) {
                win = false;
            }
            else if (yA == yB) {
                win = true;
            }
            else {
                ll n_turns;
                if (yA < yB)
                    n_turns = yB - 1;
                else
                    n_turns = w - yB;
                win = (xB - 2 * n_turns >= xA);
            }
        }
        else {
            winner = "Alice";
            xA++;
            if (yB > yA)
                yA++;
            else if (yB < yA)
                yA--;
            if (xA > xB) {
                win = false;
            }
            else if (yA == yB) {
                win = true;
            }
            else {
                ll n_turns;
                if (yA < yB)
                    n_turns = w - yA;
                else
                    n_turns = yA - 1;
                win = (xB - 2 * n_turns >= xA);
            }
        }
        if (win)
            cout << winner <<endl;
        else
            cout << "Draw"<<endl;
    }

    return 0;
}