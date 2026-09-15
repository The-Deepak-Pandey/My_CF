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

ll help(ll currNum, ll len, ll n, ll k){
    if(currNum > n) return 0;
    if(len == k) return 1;

    if(dp[currNum][len] != -1) return dp[currNum][len];

    // next number could be either
    // same number
    ll sameNum = help(currNum, len + 1, n, k) % MOD;

    // or next number could be a multiple of currNum
    ll nextNum = 0;
    for(ll i = 2; i * currNum <= n; i++){
        nextNum += help(i * currNum, len + 1, n, k) % MOD;
    }

    return dp[currNum][len] = (sameNum + nextNum)%MOD;
}


void solve() {
    ll n, k;
    cin >> n >> k;
    ll ans = 0;
    dp.assign(n + 1, vector<ll>(k + 1, -1));
    for(ll i = 1; i <= n; i++){
        ans += help(i, 1, n, k)%MOD;
    }
    cout << ans%MOD << "\n";
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