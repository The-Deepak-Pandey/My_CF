#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef vector<ll> vll;

bool hasUniqueElement(const vll& vec) {
    unordered_map<ll, int> countMap;
    for (const ll& elem : vec) {
        countMap[elem]++;
    }
    for (const auto& pair : countMap) {
        if (pair.second == 1) {
            return true;
        }
    }
    return false;
}

vll reorderElements(const vll& vec) {
    int n = vec.size();
    vll newVec = vec;
    if (n == 1) {
        return {-1}; // Cannot reorder a single element
    }
    // Perform a cyclic permutation
    rotate(newVec.begin(), newVec.begin() + 1, newVec.end());
    return newVec;
}

void solve() {
    ll n;
    cin >> n;
    vll s(n);
    for (ll i = 0; i < n; i++) {
        cin >> s[i];
    }
    if (hasUniqueElement(s)) {
        cout << -1 << endl;
        return;
    }
    vll newVec(n);
    ll i = 0;
    while (i < n) {
        vll temp;
        ll tempo = s[i];
        while (i < n && s[i] == tempo) {
            temp.push_back(i + 1);
            i++;
        }
        temp = reorderElements(temp);
        for (ll j = 0; j < temp.size(); j++) {
            newVec[temp[j] - 1] = temp[(j + 1) % temp.size()];
        }
    }
    for (ll i = 0; i < newVec.size(); i++) {
        cout << newVec[i] << " ";
    }
    cout << endl;
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