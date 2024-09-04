#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

typedef long long ll;
typedef vector<ll> vll;
typedef vector<string> vs;
const ll INF = 1e18;
const ll MOD = 1e9 + 7;

ll gcd(ll a, ll b) { while (b) { a %= b; swap(a, b); } return a; }

void solve() {
    int l, r;
    cin >> l >> r;
    if(l%2==0) l++;
    if(r%2==0) r--;
    cout << ((r-l+1)/2 + 1)/2<< endl;
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