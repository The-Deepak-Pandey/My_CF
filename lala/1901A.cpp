#include<bits/stdc++.h>
using namespace std;

int main() {

    int t;
    cin>>t;
    while(t--){
        int n, x;
        cin>>n>>x;
        int a[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        int maxi = 2*(x-a[n-1]);
        maxi = max(maxi, a[0]-0);
        for (int i = 1; i < n; i++)
        {
            maxi = max(a[i]-a[i-1], maxi);
        }
        cout<<maxi<<endl;
    }

    return 0;
}