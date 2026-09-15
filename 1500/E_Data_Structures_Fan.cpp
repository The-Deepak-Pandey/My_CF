#include <iostream>
#include <vector>
#include <string>

using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n + 1);
    vector<int> pref(n + 1, 0);

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        pref[i] = pref[i - 1] ^ a[i];
    }

    string s;
    cin >> s;

    int xor0 = 0, xor1 = 0;
    for (int i = 1; i <= n; i++) {
        if (s[i - 1] == '0') {
            xor0 ^= a[i];
        } else {
            xor1 ^= a[i];
        }
    }

    int q;
    cin >> q;

    while (q--) {
        int tp;
        cin >> tp;
        if (tp == 1) {
            int l, r;
            cin >> l >> r;
            int range_xor = pref[r] ^ pref[l - 1];
            xor0 ^= range_xor;
            xor1 ^= range_xor;
        } else {
            int g;
            cin >> g;
            if (g == 0) {
                cout << xor0 << " ";
            } else {
                cout << xor1 << " ";
            }
        }
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}