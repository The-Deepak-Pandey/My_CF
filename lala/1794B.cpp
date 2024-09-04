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
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        for (int i = 0; i < n; i++)
        {
            arr[i]+=1;
        }
        for (int i = 1; i < n; i++)
        {
            if(arr[i]%arr[i-1]==0){
                arr[i]+=1;
            }
        }
        
        for (int i = 0; i < n; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    return 0;
}