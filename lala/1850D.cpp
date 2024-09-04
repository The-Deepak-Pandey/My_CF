#include <bits/stdc++.h>
using namespace std;

int main() {

    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        int count = 0;
        sort(arr, arr+n);
        // for (int i = 0; i < n; i++)
        // {
        //     cout << arr[i] << " ";
        // }
        int ans = 0;
        for (int i = 1; i < n; i++)
        {
            if((arr[i]-arr[i-1]) <= k){
                count++;
            }
            else{
                count=0;
            }
            ans = max(count, ans);
        }
        cout << n-ans-1<<endl;
        
        
    }

    return 0;
}