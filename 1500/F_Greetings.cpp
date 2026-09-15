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

ll merge_and_count(ll left, ll mid, ll right, vector<ll> &arr) {
    ll inv_count = 0;
    ll n1 = mid - left + 1;
    ll n2 = right - mid;

    vector<ll> L(n1), R(n2);
    for (ll i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (ll j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    ll i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++];
            inv_count += (n1 - i); // Count inversions
        }
    }

    while (i < n1)
        arr[k++] = L[i++];
    while (j < n2)
        arr[k++] = R[j++];

    return inv_count;
}

ll count_inversions(ll left, ll right, vector<ll> &arr){
    ll inv_count = 0;
    if(right > left) {
        ll mid = left + (right - left) / 2;
        inv_count += count_inversions(left, mid, arr);
        inv_count += count_inversions(mid + 1, right, arr);

        // Merge the two halves and count inversions
        inv_count += merge_and_count(left, mid, right, arr);
    }
    return inv_count;
}


void solve() {
    ll n;
    cin >> n;
    vector<pair<ll, ll>> ppl(n);
    for (ll i = 0; i < n; i++) {
        cin >> ppl[i].first >> ppl[i].second;
    }
    sort(ppl.begin(), ppl.end());

    // now in the second part of the pair we need to calculate inversions i.e., ppl[i].second > ppl[j].second for i < j

    vector<ll> second_values(n);
    for (ll i = 0; i < n; i++) {
        second_values[i] = ppl[i].second;
    }

    cout << count_inversions(0, n-1, second_values) << endl;

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