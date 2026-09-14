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
    vector<ll> u(n); // university that ith student is enrolled at
    vector<ll> s(n); // programming skill of ith student
    for(ll i = 0; i < n; i++){
        cin >> u[i];
    }
    for(ll i = 0; i < n; i++){
        cin >> s[i];
    }

    vector<vector<ll>> skills(n);
    for(ll i = 0; i < n; i++){
        skills[u[i]-1].push_back(s[i]);
    }

    for(auto &v : skills){
        sort(all(v));
    }

    vector<vector<ll>> pre(n, vector<ll>(1, 0)); // pre[i][j] = sum of first j skills (ascending) for uni i
    for(ll i = 0; i < n; i++) {
        for(ll j = 0; j < sz(skills[i]); j++) {
            pre[i].push_back(pre[i].back() + skills[i][j]);
        }
    }

    vector<ll> ans(n+1);

    for(ll i = 0; i < n; i++){
        ll nums = skills[i].size();
        for(ll k = 1; k <= nums; k++) {
            ans[k] += pre[i].back() - pre[i][nums%k];
        }
    }`

    for(ll i = 1; i <= n; i++){
        cout << ans[i] << " ";
    }

    cout << endl;
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