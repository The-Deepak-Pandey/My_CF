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


int f(vector<int> &b){
    sort(b.begin(), b.end());
    //count distinct numbers
    int cnt = 1;
    for(int i = 1; i < b.size(); i++){
        if(b[i] != b[i-1]){
            cnt++;
        }
    }
    return cnt;
}


void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {   
        cin >> a[i];
    }
    // make frequency mapping
    map<int, int> freq;
    for(int i = 0; i < n; i++){
        freq[a[i]]++;
    }
    // if k = 0, then we can't change anything
    if(k == 0){
        cout << f(a) << endl;
        return;
    }
    
    // // sort the map by frequency
    // vector<pair<int, int>> v;
    // for(auto x: freq){
    //     v.push_back({x.second, x.first});
    // }

    // sort(v.begin(), v.end());

    vector<pair<int, int>> v(freq.begin(), freq.end());
    sort(v.begin(), v.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
        return a.second < b.second;
    });
    for (auto& p : v) {
        if (k == 0) break;
        int freq_to_remove = min(p.second, k);
        p.second -= freq_to_remove;
        k -= freq_to_remove;
    }

    vector<int> remaining_elements;
    for (auto& p : v) {
        for (int i = 0; i < p.second; i++) {
            remaining_elements.push_back(p.first);
        }
    }

    cout << f(remaining_elements) << endl;

    
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