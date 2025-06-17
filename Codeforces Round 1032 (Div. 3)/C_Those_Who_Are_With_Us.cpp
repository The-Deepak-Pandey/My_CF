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
    int n, m;
    cin >> n >> m;

    vector<vector<int>> mat(n, vector<int>(m));
    vector<int> M_row(n, 0), M_col(m, 0);
    map<int, int> freq;
    int max_val = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> mat[i][j];
            max_val = max(max_val, mat[i][j]);
            M_row[i] = max(M_row[i], mat[i][j]);
            M_col[j] = max(M_col[j], mat[i][j]);
            freq[mat[i][j]]++;
        }
    }
    int sec_max = 0;
    for (auto it = freq.begin(); it != freq.end(); ++it) {
        int val = it->first;
        if (val != max_val) {
            sec_max = max(sec_max, val);
        }
    }
    vector<int> MC_row(n, 0), MC_col(m, 0);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (mat[i][j] == max_val) {
                MC_row[i]++;
                MC_col[j]++;
            }
        }
    }
    int ans = INT_MAX;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int rc = MC_row[i] + MC_col[j];
            if (mat[i][j] == max_val) rc--;
            bool flag = (rc == freq[max_val]);
            int cur;
            if (flag) {
                cur = max(sec_max, max(M_row[i], M_col[j]) - 1);
            } 
            else {
                cur = max(max_val, max(M_row[i], M_col[j]) - 1);
            }
            ans = min(ans, cur);
        }
    }

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