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
    int n;
    cin >> n;
    vector<pair<int, int>> a(n); // skiing
    vector<pair<int, int>> b(n); // movie
    vector<pair<int, int>> c(n); // board games

    for(int i = 0; i < n; i++) {
        cin >> a[i].fi;
        a[i].se = i + 1;
    }

    for(int i = 0; i < n; i++) {
        cin >> b[i].fi;
        b[i].se = i + 1;
    }

    for(int i = 0; i < n; i++) {
        cin >> c[i].fi;
        c[i].se = i + 1;
    }

    vector<vector<pair<int, int>>> top3(3, vector<pair<int, int>>(3)); // pair is the value and indice

    // Get top 3 for each activity

    sort(rall(a));
    sort(rall(b));
    sort(rall(c));

    for(int i = 0; i < 3; i++) {
        top3[0][i] = a[i];
        top3[1][i] = b[i];
        top3[2][i] = c[i];
    }

    // Now we have the top 3 for each activity, we can try all combinations of one from each activity
    int ans = INT_MIN;

    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            for(int k = 0; k < 3; k++) {
                if(top3[0][i].se != top3[1][j].se && top3[1][j].se != top3[2][k].se && top3[0][i].se != top3[2][k].se) {
                    ans = max(ans, top3[0][i].fi + top3[1][j].fi + top3[2][k].fi);
                }
            }
        }
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