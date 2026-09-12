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


pair<ll, ll> dfs(ll node, const vector<vector<ll>>& adj, const string& colors, int &ans) {
    for (ll child : adj[node]) {
        auto [child_black, child_white] = dfs(child, adj, colors, ans);
        black_count += child_black;
        white_count += child_white;
    }

    if (colors[node] == 'W') {
        white_count++;
    } else {
        black_count++;
    }

    if (black_count == white_count) {
        ans++;
    }

    return {black_count, white_count};
}


void solve() {
    ll n;
    cin >> n;
    vector<ll> par(n, -1);
    for (ll i = 1; i < n; i++) {
        cin >> par[i];
        par[i]--;
    }
    string colors;
    cin >> colors;

    vector<vector<ll>> adj(n);
    for (ll i = 1; i < n; i++) {
        adj[par[i]].push_back(i);
    }

    int ans = 0;
    dfs(0, adj, colors, ans);

    cout << ans << '\n';

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