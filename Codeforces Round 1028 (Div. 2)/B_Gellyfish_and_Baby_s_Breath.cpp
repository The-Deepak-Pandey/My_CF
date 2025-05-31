#include <bits/stdc++.h>
using namespace std;

#define fastio               \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);
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

// Common Functions
ll gcd(ll a, ll b)
{
    while (b)
    {
        a %= b;
        swap(a, b);
    }
    return a;
}
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }
bool is_prime(ll n)
{
    if (n <= 1)
        return false;
    if (n <= 3)
        return true;
    if (n % 2 == 0 || n % 3 == 0)
        return false;
    for (ll i = 5; i * i <= n; i += 6)
    {
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    }
    return true;
}
vector<ll> sieve(ll n)
{
    vector<ll> primes;
    vector<bool> is_prime(n + 1, true);
    for (ll p = 2; p <= n; p++)
    {
        if (is_prime[p])
        {
            primes.pb(p);
            for (ll i = p * p; i <= n; i += p)
            {
                is_prime[i] = false;
            }
        }
    }
    return primes;
}

int MOD = 998244353;
const int MAXN = 100000;

long long int pw[MAXN + 1];

void init_pw()
{
    pw[0] = 1;
    for (int i = 1; i <= MAXN; i++)
    {
        pw[i] = (pw[i - 1] * 2) % MOD;
    }
}

void solve()
{
    int n;
    cin >> n;

    vector<int> p(n), q(n);
    for (int i = 0; i < n; i++)
    {
        cin >> p[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> q[i];
    }

    vector<int> posp(n), posq(n);
    for (int i = 0; i < n; i++)
    {
        posp[p[i]] = i;
        posq[q[i]] = i;
    }

    vector<vector<int>> bucket(n);
    for (int k = 0; k < n; k++)
    {
        int mpk = min(posp[k], posq[k]);
        bucket[mpk].push_back(k);
    }

    vector<long long> r(n, 0);
    int curMaxK = -1;

    for (int i = 0; i < n; i++)
    {
        for (int k : bucket[i])
        {
            curMaxK = max(curMaxK, k);
        }
        int K = curMaxK;

        int other1 = -1, other2 = -1;

        if (posp[K] <= i)
        {
            int idxQ = i - posp[K];
            other1 = q[idxQ];
        }

        if (posq[K] <= i)
        {
            int idxP = i - posq[K];
            other2 = p[idxP];
        }

        int m_exp = max(other1, other2);
        r[i] = (pw[K] + pw[m_exp]) % MOD;
    }

    for (int i = 0; i < n; i++)
    {
        cout << r[i] << (i + 1 < n ? ' ' : '\n');
    }
}
int main()
{
    fastio;

    init_pw();

    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}