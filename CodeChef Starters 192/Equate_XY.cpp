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

ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }

// Function to get all divisors of a number
vector<ll> getDivisors(ll n) {
    vector<ll> divs;
    for (ll i = 1; i * i <= n; ++i) {
        if (n % i == 0) {
            divs.pb(i);
            if (i != n / i) divs.pb(n / i);
        }
    }
    return divs;
}

void solve() {
    ll x, y, z, c;
    cin >> x >> y >> z >> c;

    if (x == y) {
        cout << 0 << "\n";
        return;
    }

    ll ans = LLONG_MAX;

    // Try direct single and double operations (op1 then op1, op2 then op2)
    {
        ll a = gcd(x, z), b = lcm(y, z);
        if (a == b) ans = min(ans, c);
        else {
            ll aa = lcm(a, z), bb = gcd(b, z);
            if (aa == bb) ans = min(ans, 2 * c);
        }
    }
    {
        ll a = lcm(x, z), b = gcd(y, z);
        if (a == b) ans = min(ans, c);
        else {
            ll aa = gcd(a, z), bb = lcm(b, z);
            if (aa == bb) ans = min(ans, 2 * c);
        }
    }

    // Try adjusting Z to each divisor of X and Y respectively
    vector<ll> divsX = getDivisors(x);
    vector<ll> divsY = getDivisors(y);

    for (ll d : divsX) {
        ll cost = abs(z - d) + c;
        ll a = gcd(x, d), b = lcm(y, d);
        if (a == b) ans = min(ans, cost);
    }
    for (ll d : divsY) {
        ll cost = abs(z - d) + c;
        ll a = lcm(x, d), b = gcd(y, d);
        if (a == b) ans = min(ans, cost);
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
