#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    ll n, k;
    cin >> n >> k;
    vector<ll> arr(n);
    for (ll i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // If k >= 3, we can always achieve 0
    if (k >= 3) {
        cout << 0 << "\n";
        return;
    }

    sort(arr.begin(), arr.end());

    ll ans = arr[0];
    for (ll i = 0; i < n - 1; i++) {
        ans = min(ans, arr[i + 1] - arr[i]);
    }

    if (k == 1) {
        cout << ans << "\n";
        return;
    }

    // For k == 2: O(n^2 log n)
    for (ll i = 0; i < n; i++) {
        for (ll j = 0; j < i; j++) {
            ll d = arr[i] - arr[j];
            ans = min(ans, d);

            // Find closest element to d in arr
            auto it = lower_bound(arr.begin(), arr.end(), d);
            if (it != arr.end()) {
                ans = min(ans, abs(*it - d));
            }
            if (it != arr.begin()) {
                ans = min(ans, abs(*prev(it) - d));
            }
        }
    }

    cout << ans << "\n";
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