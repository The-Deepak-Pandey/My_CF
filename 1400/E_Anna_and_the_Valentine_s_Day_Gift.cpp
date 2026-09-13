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
    vector<ll> a(n);
    ll totalDigits = 0;
    for(ll i = 0; i < n; i++) {
        cin >> a[i];
        totalDigits += to_string(a[i]).length();
    }
    bool flag = false;
    vector<pair<ll, ll>> sorted_WRT_trailingZeroes;
    for(ll i = 0; i < n; i++) {
        ll trailingZeroes = 0;
        ll temp = a[i];
        while (temp % 10 == 0 && temp > 0) {
            trailingZeroes++;
            temp /= 10;
        }
        sorted_WRT_trailingZeroes.pb({trailingZeroes, a[i]});
    }
    sort(all(sorted_WRT_trailingZeroes), [](const pair<ll, ll>& a, const pair<ll, ll>& b) {
        return a.first > b.first; // Sort in descending order of trailing zeroes
    });

    ll totalTrailingZeroesAnnaCanRemove = 0;
    for(ll i = 0; i < n; i+=2){
        totalTrailingZeroesAnnaCanRemove += sorted_WRT_trailingZeroes[i].first;
    }

    totalDigits -= totalTrailingZeroesAnnaCanRemove;
    if(totalDigits <= m) {
        cout << "Anna\n";
    } else {
        cout << "Sasha\n";
    }

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