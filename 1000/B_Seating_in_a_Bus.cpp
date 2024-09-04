#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define pb push_back
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define fi first
#define se second
#define mp make_pair
#define sz(x) ((int)(x).size())
#define vi vector<int>
#define pii pair<int, int>
#define vii vector<pii>

typedef long long ll;
typedef vector<ll> vll;
typedef vector<string> vs;
const ll INF = 1e18;
const ll MOD = 1e9 + 7;

void solve() {
    ll n;
    cin >> n;
    vector<ll> arr(n);
    for (ll i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    vector<bool> occupied(n + 1, false);
    bool valid = true;
    
    for (ll i = 0; i < n; i++) {
        ll seat = arr[i];
        if (i == 0 || (seat > 1 && occupied[seat - 1]) || (seat < n && occupied[seat + 1])) {
            occupied[seat] = true;
        } else {
            valid = false;
            break;
        }
    }
    
    cout << (valid ? "YES\n" : "NO\n");
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