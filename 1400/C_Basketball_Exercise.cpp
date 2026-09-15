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

vector<vector<ll>> dp;

ll help(int ind, vector<int> &a, vector<int> &b, bool in_A){
    if(ind == a.size()){
        return 0;
    }

    if(dp[ind][in_A] != -1){
        return dp[ind][in_A];
    }

    if(in_A){
        ll skip = help(ind + 1, a, b, true);
        ll take = a[ind] + help(ind + 1, a, b, false);
        return dp[ind][in_A] = max(skip, take);
    } else{
        ll skip = help(ind + 1, a, b, false);
        ll take = b[ind] + help(ind + 1, a, b, true);
        return dp[ind][in_A] = max(skip, take);
    }
}


void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }

    dp.assign(n, vector<ll>(2, -1));

    cout << max(help(0, a, b, true), help(0, a, b, false)) << endl;
}

int main() {
    fastio;

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}