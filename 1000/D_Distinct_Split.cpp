#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int distinct_characters(const string &s) {
    int counter = 0;
    bool flag[26] = {0};
    for (auto it : s) {
        if (!flag[it - 'a']) {
            counter++;
            flag[it - 'a'] = 1;
        }
    }
    return counter;
}

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int total = distinct_characters(s);
    int cp = 0;
    int cs = 0;
    bool prefix_flag[26] = {0};
    bool suffin_flag[26] = {0};
    int prefix[n];
    int suffin[n];
    fill(prefix, prefix + n, 0);
    fill(suffin, suffin + n, 0);

    for (int i = 0; i < n; i++) {
        if (!prefix_flag[s[i] - 'a']) {
            cp++;
            prefix_flag[s[i] - 'a'] = 1;
        }
        prefix[i] = cp;

        //similarly for suffix
        if (!suffin_flag[s[n - i - 1] - 'a']) {
            cs++;
            suffin_flag[s[n - i - 1] - 'a'] = 1;
        }
        suffin[n - i - 1] = cs;
    }
    
    int ans = 0;
    for (int i = 0; i < n - 1; i++) {
        ans = max(ans, prefix[i] + suffin[i + 1]);
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}