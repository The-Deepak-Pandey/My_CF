#include <iostream>
#include <vector>
#include <string>
using namespace std;

typedef long long ll;
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

void solve() {
    int n, r, b;
    cin >> n >> r >> b;
    string s;
    
    int d = r / (b + 1);
    int dl = r % (b + 1); 

    for (int i = 0; i < b + 1; ++i) {
        for (int j = 0; j < d; ++j) {
            s += 'R';
        }
        if (dl > 0) {
            s += 'R';
            --dl;
        }
        if (i < b) {
            s += 'B';
        }
    }

    cout << s << endl;
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