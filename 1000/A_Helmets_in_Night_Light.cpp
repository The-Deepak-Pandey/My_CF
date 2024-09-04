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
const ll MOD = 1e9 + 7;

#define int long long int

void solve()
{
    int n, p;
    cin >> n >> p;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int brr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> brr[i];
    }
    if (n == 1)
    {
        cout << p << endl;
        return;
    }
    vector<pair<int, int>> tempo;
    for (int i = 0; i < n; i++)
    {
        tempo.pb({brr[i], arr[i]});
    }
    sort(tempo.begin(), tempo.end());

    if (p <= tempo[0].first)
    {
        cout << n * p << endl;
        return;
    }
    int ans = 0;
    int index = 0;
    int size = n;
    ans+=p;
    n--;
    while (n > 0 && index < size)
    {
        if (tempo[index].first < p)
        {
        
            int av = tempo[index].second;
            int paisa = tempo[index].first;
            while (av && n )
            {
                ans += paisa;
                n--;
                av--;
            }
            index++;
        }
        else
        {
            ans+=n*p;
            break;
        }
    }
    cout << ans << endl;
    return;
}

int32_t main()
{
    fastio;

    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}