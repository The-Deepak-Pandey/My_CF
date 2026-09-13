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


// bool help(string &s, int ind, char prev) {
//     if(ind >= s.size()) return true;

//     if(s[ind] != prev){
//         return help(s, ind + 1, s[ind]);
//     }

//     for(char c = 'a'; c <= 'z'; c++){
//         if(c != prev){
//             s[ind] = c;
//             if(help(s, ind + 1, c)) return true;
//         }
//     }

//     return false;

// }

// we need to minimize the number of changes

// pair<bool, int> help(string &s, int ind, char prev) {
//     if (ind >= s.size()) return {true, 0};

//     if (s[ind] != prev) {
//         auto res = help(s, ind + 1, s[ind]);
//         return {res.first, res.second};
//     }

//     int min_changes = INT_MAX;
//     char best_char = s[ind];

//     for (char c = 'a'; c <= 'z'; c++) {
//         if (c != prev) {
//             char original_char = s[ind];
//             s[ind] = c;
//             auto res = help(s, ind + 1, c);
//             if (res.first && res.second + 1 < min_changes) {
//                 min_changes = res.second + 1;
//                 best_char = c;
//             }
//             s[ind] = original_char; // revert the change
//         }
//     }

//     if (min_changes == INT_MAX) return {false, 0};

//     s[ind] = best_char; // apply the best change
//     return {true, min_changes};
// }

void solve() {
    string s;
    cin >> s;

    // help(s, 0, '#');

    // cout << s << endl;

    for(int i = 1; i < s.size(); i++) {
        if (s[i] == s[i - 1]) {
            for (char c = 'a'; c <= 'z'; c++) {
                if (c != s[i - 1] && (i + 1 >= s.size() || c != s[i + 1])) {
                    s[i] = c;
                    break;
                }
            }
        }
    }

    cout << s << endl;
}

int main() {
    fastio;

    int t =1;
    // cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}