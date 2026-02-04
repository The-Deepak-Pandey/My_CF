#include <bits/stdc++.h>
using namespace std;
using int64 = long long;

// compute the smallest y in [L,R] such that (y & X)==0;
// if none exists, returns R+1.
int64 nextY(int64 X, int64 L, int64 R) {
    int64 y = L;
    // if L already ok, done
    if ((y & X) == 0) return y;
    // otherwise bump y past any forbidden 1‐bits of X
    // we iterate at most 64 times (one per bit)
    for (int b = 0; b < 64; b++) {
        int64 mask = (int64(1) << b);
        if ((X & mask) && (y & mask)) {
            // bit b is forbidden and y has it =1 ⇒ we must clear bits <b and
            // carry 1 into bit b
            y += mask;
            // clear all bits <b
            y &= ~((mask) - 1);
            // if we've jumped past R, no hope
            if (y > R) return R + 1;
            // start checking again from bit 0
            b = -1;
        }
    }
    // final check
    return ((y & X) == 0 ? y : R + 1);
}

// helper to print int64
void print64(int64 x) {
    cout << x;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int64 n, L, R, k;
        cin >> n >> L >> R >> k;

        // odd n ⇒ just take all = L
        if (n % 2 == 1) {
            print64(L);
            cout << "\n";
            continue;
        }
        // n=2 ⇒ no solution (would force x=y and x&x=x>0)
        if (n == 2) {
            cout << "-1\n";
            continue;
        }

        // even n>=4 ⇒ we look for the smallest x>=L such that we can find y>=L
        // with x&y==0.  Then the lex smallest array is
        //   [x,x,…,x, y, y]  (n-2 copies of x, then two y's).
        // We only need to probe a small window of x's starting at L.
        const int WINDOW = 200;  
        bool found = false;
        int64 bestX=0, bestY=0;
        int64 upper = min(R, L + WINDOW);

        for (int64 x = L; x <= upper; x++) {
            int64 y = nextY(x, L, R);
            if (y <= R) {
                bestX = x;
                bestY = y;
                found = true;
                break;
            }
        }

        if (!found) {
            cout << "-1\n";
        } else {
            // answer is a_k
            if (k <= n-2) {
                print64(bestX);
                cout << "\n";
            } else {
                print64(bestY);
                cout << "\n";
            }
        }
    }
    return 0;
}
