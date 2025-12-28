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
    ll n, k, a, b;
    cin >> n >> k >> a >> b;
    vll x(n+1);
    vll y(n+1);
    for (ll i = 1; i <= n; i++) {
        cin >> x[i] >> y[i];
    }

    if(a<=k && b <= k){
        cout << 0 << "\n";
        return;
    }

    if(k == 0){
        cout << abs(x[a] - x[b]) + abs(y[a] - y[b]) << "\n";
        return;
    }

    ll dir_dist = abs(x[a] - x[b]) + abs(y[a] - y[b]);
    ll nearest_from_a = LLONG_MAX;
    ll nearest_from_b = LLONG_MAX;

    for(int i = 1; i <= k; i++) {
        ll dist_a = abs(x[a] - x[i]) + abs(y[a] - y[i]);
        ll dist_b = abs(x[b] - x[i]) + abs(y[b] - y[i]);
        nearest_from_a = min(nearest_from_a, dist_a);
        nearest_from_b = min(nearest_from_b, dist_b);
    }

    ll ans = min(dir_dist, nearest_from_a + nearest_from_b);
    cout << ans << "\n";
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