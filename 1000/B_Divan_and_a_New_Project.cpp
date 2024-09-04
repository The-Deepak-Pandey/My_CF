#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define vi vector<int>
#define vll vector<ll>

void solve() {
    ll n;
    cin >> n;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].first;
        a[i].second = i+1;
    }
    sort(a.begin(), a.end(), greater<pair<int, int>>());
    
    // Debug: Print sorted array
    // cout << "Sorted array: ";
    // for (int i = 0; i < n; i++) {
    //     cout << a[i] << " ";
    // }
    // cout << endl;
    
    vll ans(n + 1);
    ans[0] = 0;
    ll sum = 0;
    int l = -1, r = 1;
    for (int i = 0; i < n; i++) {
        int index = a[i].second;
        if (i % 2 == 0) {
            ans[index] = r++;
        } else {
            ans[index] = l--;
        }
        sum += 2ll * abs(ans[index]) * a[i].first;
        
        // Debug: Print current position and sum
        // cout << "Position: " << ans[index] << ", Sum: " << sum << endl;
    }
    cout << sum << endl;
    for (int i = 0; i <= n; i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
}

int main() {
    fastio;

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}