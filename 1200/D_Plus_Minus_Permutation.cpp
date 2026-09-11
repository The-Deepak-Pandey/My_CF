#include <bits/stdc++.h>
using namespace std;

long long rangeSum(long long l, long long r) {
    if(l > r)
        return 0;

    return (l + r) * (r - l + 1) / 2;
}

int main() {

    int t;
    cin >> t;

    while(t--) {

        long long n, x, y;
        cin >> n >> x >> y;

        long long l = x / __gcd(x, y) * y;

        long long plus = n / x - n / l;
        long long minus = n / y - n / l;

        long long ans =
            rangeSum(n - plus + 1, n)
            - rangeSum(1, minus);

        cout << ans << '\n';
    }

    return 0;
}