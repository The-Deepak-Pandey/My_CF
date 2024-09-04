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
    ll n, k;
    cin >> n >> k;
    ll arr[n];
    int flag = 0;
    ll mini = LLONG_MAX;
    ll pdt = 1;
    ll cntE = 0;
    ll cnt1 = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        // pdt *= arr[i];
        // if(pdt%k==0){
        //     pdt = 0;
        //     flag = 1;
        // }
        if(arr[i]==k){
            flag = 1;
        }
        if(arr[i]%k==0){
            flag = 1;
        }
        mini = min(mini, k - (arr[i] % k));
        // for n==4 case
        if (k == 4)
        {
            if(arr[i]%2==0){
                cntE++;
            }
        }
    }
    if (flag==1)
    {
        cout << "0\n";
        return;
    }
    if(k==4){
        cout << min(mini, max(1ll*0, 2-cntE)) << endl;
    }
    else
    {
        cout << mini << endl;
        return;
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