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


bool isGood(const vi& a) {
    ll curSum = 0;
    for(auto it : a) {
        curSum += it;
        if(curSum % 3 == 0) return false;
    }
    return true;
}


void solve() {
    int n;
    cin >> n;
    vi a(n+1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    vector<int> pref(n+1, 0);
    pref[0] = 0;

    for (int i = 1; i <= n; i++) {
        pref[i] = (pref[i - 1] + a[i]) % 3;
    }

    int l0 = -1;
    for(int i = 1; i <= n; i++) {
        if (pref[i] == 0) {
            l0 = i;
        }
    }
    if(l0 == -1){
        cout << "Yes\n";
        return;
    }

    vector<int> cnt(3, 0);
    for (int i = 0; i < l0; i++) {
        cnt[pref[i]]++;
    }

    bool flag = false;
    for (int i = l0; i <= n; i++) {
        if(cnt[pref[i]] == 0) {
            flag = true;
            break;
        }
        cnt[pref[i]]++;
    }

    if(flag) {
        cout << "Yes\n";
        return;
    }
    cout << "No\n";
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