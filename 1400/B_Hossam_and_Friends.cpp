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
    vector<vector<ll>> enemies(n + 1);
    vector<ll> maxL(n+1, 0);
    for (ll i = 0; i < m; i++) {
        ll u, v;
        cin >> u >> v;
        enemies[u].pb(v);
        enemies[v].pb(u);

        if(u > v) swap(u, v);
        maxL[v] = max(maxL[v], u);
    }


    ll ans = 0;

    // for(ll r = 1; r <= n; r++) {
    //     // let's see what min l can we have
    //     ll l = r;
    //     while(l > 1){
    //         // before expanding l, we'll check if any enemy of (l-1) is in the range [l, r]
    //         bool can_expand = true;
    //         for(auto enemy : enemies[l-1]) {
    //             if(enemy >= l && enemy <= r) {
    //                 can_expand = false;
    //                 break;
    //             }
    //         }
    //         if(!can_expand) break;
    //         l--;
    //     }
    //     ans += (r - l + 1);
    // }

    ll currL = 1;
    for(ll r = 1; r <= n; r++) {
        currL = max(currL, maxL[r] + 1);
        ans += (r - currL + 1);
    }

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