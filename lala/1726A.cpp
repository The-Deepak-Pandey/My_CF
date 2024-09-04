#include <bits/stdc++.h>
using namespace std;

#define int long long int

int32_t main() {

    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int arr[n];
        int maxi = LLONG_MIN;
        int mini = LLONG_MAX;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            maxi = max(maxi, arr[i]);
            mini = min(mini, arr[i]);
        }
        int maxi2 = LLONG_MIN;
        for (int i = 1; i < n; i++)
        {
            maxi2 = max(maxi2, arr[i-1]-arr[i]);
        }
        cout << max(maxi2, max(maxi - arr[0], arr[n-1]-mini)) << endl;
        

        
    }

    return 0;
}