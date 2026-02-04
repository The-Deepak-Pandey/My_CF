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

int find(int x, vector<int>& parent) {
    if(parent[x] < 0) {
        return x;
    }
    else{
        return parent[x] = find(parent[x], parent);
    }
}

void union_set(int x, int y, vector<int>& parent) {
    x = find(x, parent);
    y = find(y, parent);
    if(x != y) {
        if(parent[x] < parent[y]) {
            parent[x] += parent[y];
            parent[y] = x;
        } else {
            parent[y] += parent[x];
            parent[x] = y;
        }
    }
    return;
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<pair<int, int> > edges;
    vector<int> in_wt(m);

    for(int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges.pb({u-1, v-1});
        in_wt[i] = w;
    }

    int ans = -1;
    vector<int> temp_wt = in_wt;
    for(int i = 0; i <= m; i++){
        vector<int> vec(m, 0);
        for(int j = 0; j <i; j++){
            vec[j] = 1;
        }
        sort(vec.begin(), vec.end());

        do{
            temp_wt = in_wt;
            for(int j = 0; j < m; j++) {
                if(vec[j] == 1) {
                    temp_wt[j] = 1-temp_wt[j];
                }
            }

            vector<int> parent(n + 1, -1);
            bool cycle = false;
            for(int j = 0; j < m; j++) {
                if(temp_wt[j] == 0){
                    int u = edges[j].first;
                    int v = edges[j].second;
                    int set_u = find(u, parent);
                    int set_v = find(v, parent);
                    if(set_u == set_v) {
                        cycle = true;
                        break;
                    } else {
                        union_set(set_u, set_v, parent);
                    }
                }
            }
            if(cycle) {
                continue;
            }

            int comp0 = 0;
            for(int j = 0; j < n; j++) {
                if(parent[j] < 0) {
                    comp0++;
                }
            }

            if(comp0 >1){
                ans = i;
                break;
            }

        } while(next_permutation(vec.begin(), vec.end()));

        if(ans != -1) {
            break;
        }
    }

    if(ans == -1) {
        cout << m << endl;
    } else {
        cout << ans << endl;
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