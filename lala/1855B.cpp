#include <bits/stdc++.h>
using namespace std;

#define int long long int

int32_t main() {

    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        if(n%2!=0){
            cout << "1\n";
        }
        else{
            int ans = 1;
            while(n%ans==0){
                ans++;
            }
            cout<<ans-1<<endl;
        }
    }

    return 0;
}