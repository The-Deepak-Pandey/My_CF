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
    string s;
    cin >> s;

    ll total_balance = 0;
    for (char c : s) {
        total_balance += (c == '(' ? 1 : -1);
    }
    if (total_balance != 0) {
        cout << -1 << "\n";
        return;
    }

    vector<ll> color(n, 0);
    ll bal = 0;
    ll current_color = 0;
    bool has1 = false, has2 = false;

    for (ll i = 0; i < n; i++) {
        if (bal == 0) {
            current_color = (s[i] == '(' ? 1 : 2);
        }

        color[i] = current_color;
        if (current_color == 1) has1 = true;
        if (current_color == 2) has2 = true;

        bal += (s[i] == '(' ? 1 : -1);
    }

    if (has1 && has2) {
        cout << 2 << "\n";
        for (ll i = 0; i < n; i++) {
            cout << color[i] << (i + 1 == n ? "" : " ");
        }
    } else {
        cout << 1 << "\n";
        for (ll i = 0; i < n; i++) {
            cout << 1 << (i + 1 == n ? "" : " ");
        }
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