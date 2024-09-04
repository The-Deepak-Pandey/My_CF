#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;
typedef vector<ll> vll;

void solve() {
    ll n, k, b, s;
    cin >> n >> k >> b >> s;
    if (s < k * b || s > k * b + (k - 1) * n) {
        cout << -1 << endl;
        return;
    }
    vll ans(n, 0);
    ans[0] = k * b;
    s -= k * b;

    for (int i = 0; i < n && s > 0; i++) {
        ll add = min(s, k - 1);
        ans[i] += add;
        s -= add;
    }

    for (auto it : ans) cout << it << " ";
    cout << endl;
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