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

void solve()
{
    int a;
    cin >> a;
    int counter = 0;
    string s = to_string(a);
    if (s.size() <= 2)
    {
        cout << "NO\n";
        return;
    }
    if (s[0] == '1' && s[1] == '0')
    {
        string sub = s.substr(2);
        int result = stoi(sub);
        if (s[2] != '0')
        {
            if (result < 2)
            {
                cout << "NO\n";
            }
            else
            {
                cout << "YES\n";
            }
        }
        else{
            cout << "NO\n";
        }
        // if (s[2] - '0' >= 2)
        // {
        //     cout << "YES\n";
        // }
        // else
        // {

        //     for (int i = 2; i < s.size(); i++)
        //     {
        //         counter += s[i] - '0';
        //     }
        //     if (counter >= 2)
        //     {
        //         cout << "YES\n";
        //         return;
        //     }
        //     else
        //     {
        //         cout << "NO\n";
        //     }
        // }
        // string sub = s.substr(2);
        // int result = stoi(sub);
        // if (result < 2)
        // {
        //     cout << "NO\n";
        // }
        // else
        // {
        //     cout << "YES\n";
        // }
    }
    else
    {
        cout << "NO\n";
    }
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