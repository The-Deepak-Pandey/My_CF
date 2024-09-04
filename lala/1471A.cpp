
#include <iostream>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--) {
        long long ans = 0, sum = 0;
        long long a, n, x;
        cin >> n >> x;
        for (int i = 0; i < n; i++) {
            cin >> a;
            sum += a;
            ans += a / x + (bool)(a % x);
        }
        cout << sum / x + (bool)(sum % x) << " " << ans << endl;
    }
    return 0;
}