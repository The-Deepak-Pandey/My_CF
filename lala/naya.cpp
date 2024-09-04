#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t; // Read the number of test cases

    while (t--) { // Loop for each test case
        int n;
        cin >> n; // Read the size of the array
        vector<int> arr(n); // Create a vector to store the input array

        for (int i = 0; i < n; i++) {
            cin >> arr[i]; // Read each element of the array
        }

        int counting = 0; // Initialize the count of "good" arrays to 0
        int prefixSum = 0;
        int maxElement = LLONG_MIN;

        for (size_t i = 0; i < arr.size(); ++i) {
            prefixSum += arr[i];
            maxElement = max(maxElement, arr[i]);

            if (maxElement == prefixSum - maxElement) {
                ++counting;
            }
        }

        cout << counting << endl; // Print the count of "good" arrays
    }
    return 0;
}
