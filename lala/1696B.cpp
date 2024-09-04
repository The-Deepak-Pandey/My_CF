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
        int count = 0;
        int flag = 0;
        for (int i = 0; i < n; i++)
        {
            if(arr[i]!=0 && flag == 0){
                flag = 1;
                count++;
            }
            else if(arr[i]==0){
                flag = 0;
            }
        }
        if(count>2){
            count = 2;
        }
        cout<<count<<endl;
        
    }

    return 0;
}