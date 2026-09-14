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

// Common Functions
ll gcd(ll a, ll b) { while (b) { a %= b; swap(a, b); } return a; }
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }
bool is_prime(ll n) { if (n <= 1) return false; if (n <= 3) return true; if (n % 2 == 0 || n % 3 == 0) return false; for (ll i = 5; i * i <= n; i += 6) { if (n % i == 0 || n % (i + 2) == 0) return false; } return true; }
vector<ll> sieve(ll n) { vector<ll> primes; vector<bool> is_prime(n + 1, true); for (ll p = 2; p <= n; p++) { if (is_prime[p]) { primes.pb(p); for (ll i = p * p; i <= n; i += p) { is_prime[i] = false; } } } return primes; }




void solve() {
    ll n;
    cin >> n;
    vector<ll> a(n+1);
    for (ll i = 1; i <= n; i++) {
        cin >> a[i];
    }

    vector<vector<ll>> pref(n + 1, vector<ll>(31, 0));

    for (ll i = 1; i <= n; i++) {
        for (ll b = 0; b < 31; b++) {
            pref[i][b] = pref[i - 1][b] + ((a[i] >> b) & 1);
        }
    }

    ll q;
    cin >> q;
    for(ll i = 0; i < q; i++) {
        ll l, k;
        cin >> l >> k;
        ll low = l, high = n;
        ll ans = -1;

        while(low <= high) {
            ll mid = low + (high - low) / 2;
            ll andAns = 0;
            for(ll b = 0; b < 31; b++) {
                ll count = pref[mid][b] - pref[l-1][b];
                if(count == (mid - l + 1)) {
                    andAns |= (1 << b);
                }
            }

            if(andAns >= k){
                ans = mid;
                low = mid + 1;
            } else{
                high = mid - 1;
            }
        }

        cout << ans << " ";

    }
    cout << "\n";
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