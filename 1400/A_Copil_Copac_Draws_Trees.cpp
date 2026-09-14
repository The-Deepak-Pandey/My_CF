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


void dfs(ll node, ll parent, vector<vector<ll>>& adj, vector<ll>& visited, vector<ll>& dp, map<pair<ll, ll>, ll>& edgeIndex, ll& ans){
    visited[node] = 1;
    for(ll neighbor : adj[node]){
        if(neighbor != parent){
            if(edgeIndex[{node, neighbor}] > edgeIndex[{parent, node}]){
                dp[neighbor] = dp[node];
                ans = max(ans, dp[neighbor]);
            } else{
                dp[neighbor] = dp[node] + 1;
                ans = max(ans, dp[neighbor]);
            }
            dfs(neighbor, node, adj, visited, dp, edgeIndex, ans);
        }
    }
}

void solve() {
    ll n;
    cin >> n;
    vector<pair<ll, ll>> edges(n - 1);
    for (ll i = 0; i < n - 1; i++) {
        cin >> edges[i].first >> edges[i].second;
    }
    // ll nodesDrawn = 1;
    vector<ll> visited(n + 1, 0);
    vector<vector<ll>> adj(n + 1);
    for (ll i = 0; i < n - 1; i++) {
        adj[edges[i].first].pb(edges[i].second);
        adj[edges[i].second].pb(edges[i].first);
    }
    // visited[1] = 1;
    // ll readings = 0;
    // while(nodesDrawn < n){
    //     for(ll i = 0; i < n-1; i++){
    //         if(visited[edges[i].first] && !visited[edges[i].second]){
    //             visited[edges[i].second] = 1;
    //             nodesDrawn++;
    //         }
    //         else if(!visited[edges[i].first] && visited[edges[i].second]){
    //             visited[edges[i].first] = 1;
    //             nodesDrawn++;
    //         }
    //     }
    //     readings++;
    // }

    // cout << readings << "\n";

    vector<ll> dp(n + 1, 0);
    dp[1] = 1;
    map<pair<ll, ll>, ll> edgeIndex;
    edgeIndex[{0, 1}] = -1; // Initialize the edge index for the root node
    edgeIndex[{1, 0}] = -1; // Initialize the edge index for the root node
    for(ll i = 0; i < n - 1; i++) {
        edgeIndex[{edges[i].first, edges[i].second}] = i;
        edgeIndex[{edges[i].second, edges[i].first}] = i;
    }
    ll ans = 0;
    dfs(1, 0, adj, visited, dp, edgeIndex, ans);

    cout << ans << "\n";

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