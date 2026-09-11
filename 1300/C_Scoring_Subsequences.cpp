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
    ll n;
    cin >> n;
    vector<ll> a(n);
    for(ll i = 0; i < n; i++) {
        cin >> a[i];
    }

    // // some precomputation for factorials
    // vector<ll> fact(n+1, 1);
    // for(ll i = 1; i <= n; i++){
    //     fact[i] = (fact[i-1]*i) % MOD;
    // }


    vector<ll> ans;
    // ans.push_back(a[0]);

    // for(ll i = 1; i < n; i++){
    //     //now i have window of {0...i}
    //     //mereku aisa minimum j chaahiye so that {j..i} gives the maximum score
    //     //so we can use binary search to find the minimum j

    //     ll l = 0, r = i-1;
    //     ll maxScore = 0; // {a[j]*a[j+1]*...*a[i]} / factorial(i-j+1)}
    //     ll maxJ = -1;

    //     while(l < r){
    //         ll mid = l + (r-l)/2;

    //         ll curScore = 1;

    //         for(ll k = mid; k <= i; k++){
    //             curScore = (curScore * a[k]) % MOD;
    //         }

    //         if(curScore > maxScore){
    //             maxScore = curScore;
    //             maxJ = mid;
    //         }

    //         if(curScore < maxScore){
    //             r = mid;
    //         } else {
    //             l = mid + 1;
    //         }
    //     }

    //     ans.push_back(a[maxJ]);
    // }

    for(ll i = 0; i < n; i++){
        ll low = 1, high = i+1; //in 1-based indexing
        ll best = 1;

        while(low <= high){
            ll mid = low + (high-low)/2;
            
            // if my smallest element in suffix at index (i-mid+1) >= mid (the length of suffix) then
            // i can have this length of suffix, so i can try for bigger length
            if(a[i-mid+1] >= mid){
                best = mid;
                low = mid + 1;
            } else{
                high = mid - 1;
            }
        }

        ans.push_back(best);
    }

    for(auto x: ans){
        cout << x << " ";
    }

    cout << "\n";


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