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


class DSU{
    
    public:
    vector<int> parent, size;
    DSU(int n){
        parent.resize(n);
        size.resize(n, 1);
        for(int i = 0; i < n; i++){
            parent[i] = i;
        }
    }

    int find(int a){
        if(parent[a] == a) return a;
        return parent[a] = find(parent[a]);
    }

    void union_sets(int a, int b){
        a = find(a);
        b = find(b);
        if(a != b){
            if(size[a] < size[b]) swap(a, b);
            parent[b] = a;
            size[a] += size[b];
        }
    }
};

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> group(m);
    for(int i = 0; i < m; i++){
        int numPpl;
        cin >> numPpl;
        for(int j = 0; j < numPpl; j++){
            int person;
            cin >> person;
            group[i].push_back(person - 1); // Store 0-indexed
        }
    }

    // union everyone in the same group
    DSU dsu(n);
    for(int i = 0; i < m; i++){
        for(int j = 1; j < group[i].size(); j++){
            dsu.union_sets(group[i][0], group[i][j]);
        }
    }

    // Count the size of each node from 0 to n-1 and print
    for(int i = 0; i < n; i++){
        cout << dsu.size[dsu.find(i)] << " ";
    }

    cout << endl;
}

int main() {
    fastio;

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}