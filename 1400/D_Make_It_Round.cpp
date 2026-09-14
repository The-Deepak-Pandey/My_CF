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
    ll n, m;
    cin >> n >> m;

    ll nCount2 = 0, nCount5 = 0;
    ll tempn = n;
    while (tempn % 2 == 0) {
        nCount2++;
        tempn /= 2;
    }
    tempn = n;
    while (tempn % 5 == 0) {
        nCount5++;
        tempn /= 5;
    }

    // Increased search bound from 10 to 30
    for (ll target = 30; target >= 0; target--) {
        ll more2 = max(0ll, target - nCount2);
        ll more5 = max(0ll, target - nCount5);

        // Compute need using safe integer multiplication instead of pow()
        ll need = 1;
        bool overflow = false;

        for (ll i = 0; i < more2; i++) {
            if (need > m / 2) { overflow = true; break; }
            need *= 2;
        }
        for (ll i = 0; i < more5 && !overflow; i++) {
            if (need > m / 5) { overflow = true; break; }
            need *= 5;
        }

        if (!overflow && need <= m) {
            // Find the largest multiple of 'need' that is <= m
            ll k = (m / need) * need;
            if (k == 0) k = m; // edge case safety
            cout << n * k << "\n";
            return;
        }
    }

    cout << n * m << "\n";
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