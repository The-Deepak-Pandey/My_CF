#include <iostream>
using namespace std;

typedef long long ll;

ll xor_upto_n(ll n) {
    if (n % 4 == 0) return n;
    if (n % 4 == 1) return 1;
    if (n % 4 == 2) return n + 1;
    return 0;
}

void solve() {
    ll a, b;
    cin >> a >> b;
    ll x = xor_upto_n(a - 1);
    
    if (x == b) {
        cout << a << endl;
        return;
    }
    if ((x ^ b) != a) {
        cout << a + 1 << endl;
        return;
    }
    cout << a + 2 << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}