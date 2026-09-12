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


ll help(ll x){
    return x*(x+1)/2;
}

void solve() {
    ll k, x;
    cin >> k >> x;
    // if(k*(k+1) - 1 <= x){
    //     cout << 2*k-1 << endl;
    //     return;
    // }
    // cout<< "DEEPAK" << endl;

    ll l = 1, r = 2*k-1, ans = 2*k-1;

    while(l <= r) {
        ll mid = l + (r - l) / 2;
        ll cnt;

        if(mid >= k){
            cnt = help(k) + help(k-1) - help(2*k-1-mid);
        } else{
            cnt = help(mid);
        }

        if(cnt >= x){
            ans = mid;
            r = mid-1;
        } else l = mid+1;
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