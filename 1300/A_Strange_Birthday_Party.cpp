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


ll help(ll ind, vector<ll> &k, vector<ll> &c, vector<ll> &used){
    if(ind == k.size()) return 0;

    // Option 1: Give c[k[ind]] dollars to the friend at index ind
    ll option1 = c[k[ind]] + help(ind + 1, k, c, used);

    // Option 2: Buy a present j <= k[ind] which costs c[j] dollars and give it to the friend at index ind if it is not used yet
    ll option2 = LLONG_MAX-1e18;

    for(ll j = 0; j <= k[ind]; j++) {
        if(used[j] == 0) {
            used[j] = 1; // Mark present j as used
            option2 = min(option2, c[j] + help(ind + 1, k, c, used));
            used[j] = 0; // Backtrack: unmark present j
        }
    }

    return min(option1, option2);
}

void solve() {
    ll n, m;
    cin >> n >> m;
    vector<ll> k(n), c(m);
    for(ll i = 0; i < n; i++) {
        cin >> k[i];
        // k[i]--;
    }
    for(ll i = 0; i < m; i++) {
        cin >> c[i];
    }

    // vector<ll> used(m, 0); // To keep track of used presents
    // cout << help(0, k, c, used) << endl;

    sort(k.begin(), k.end());
    ll ans = 0;
    ll p = 0;

    for(ll i = n-1; i >= 0; i--){
        if(p < m && c[p] < c[k[i]-1]){
            ans += c[p];
            p++;
        } else {
            ans += c[k[i]-1];
        }
    }

    cout << ans << endl;
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