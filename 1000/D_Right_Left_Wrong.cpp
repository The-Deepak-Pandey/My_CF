#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        string s;
        cin >> s;

        long long maxScore = 0;
        
        vector<long long> prefixSum(n + 1, 0);
        for (int i = 0; i < n; i++) {
            prefixSum[i + 1] = prefixSum[i] + a[i];
        }

        int left = 0, right = n - 1;
        long long score =0;
        while (left < right) {
            if (s[left] == 'L' && s[right] == 'R') {
                score += prefixSum[right + 1] - prefixSum[left];
                // maxScore += score;
                left++;
                right--;
            } else if (s[left] == 'L') {
                right--;
            } else {
                left++;
            }
        }

        cout << score << endl;
    }

    return 0;
}