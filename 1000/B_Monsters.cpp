#include <bits/stdc++.h>
using namespace std;

#define fastio               \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);

typedef long long ll;

bool mysort(pair<ll, ll> p1, pair<ll, ll> p2)
{
    if (p1.first == p2.first)
        return (p1.second < p2.second);
    else
        return (p1.first > p2.first);
}

typedef ll lli;
#define REP(i, m, n) for (lli i = m; i < n; i++)

void solve()
{
    lli n, k;
    cin >> n >> k;
    vector<lli> monsters(n);
    vector<pair<lli, lli>> sortmonster(n);
    REP(i, 0, n)
    {
        cin >> monsters[i];
        if (monsters[i] % k)
        {
            sortmonster[i].first = monsters[i] % k;
            sortmonster[i].second = i;
        }
        else
        {
            sortmonster[i].first = k;
            sortmonster[i].second = i;
        }
    }
    sort(sortmonster.begin(), sortmonster.end(), mysort);
    REP(i, 0, n)
    {
        cout << sortmonster[i].second + 1 << " ";
    }
 
    cout << endl;
}

int main()
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
