#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    if (!(cin >> n)) return;

    vector<int> c(n + 1);
    vector<int> bad_child_count(n + 1, 0);
    vector<int> total_children(n + 1, 0);
    int root = -1;

    for (int i = 1; i <= n; i++) {
        int p;
        cin >> p >> c[i];
        if (p == -1) {
            root = i;
        } else {
            total_children[p]++;
            if (c[i] == 1) {
                bad_child_count[p]++;
            }
        }
    }

    vector<int> ans;
    for (int i = 1; i <= n; i++) {
        if (i == root) continue;
        // Vertex doesn't respect its parent AND none of its children respect it
        if (c[i] == 1 && bad_child_count[i] == total_children[i]) {
            ans.push_back(i);
        }
    }

    if (ans.empty()) {
        cout << -1 << "\n";
    } else {
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << (i + 1 == ans.size() ? "" : " ");
        }
        cout << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}