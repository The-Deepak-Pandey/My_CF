#include <bits/stdc++.h>
using namespace std;

int main() {

    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        string s;
        cin >> s;
        char curr = s[0];
        int temp = 1;
        int ans = 1;
        for (int i = 1; i < n; i++)
        {
            if(s[i-1] == s[i]){
                temp++;
            }
            else{
                temp = 1;
            }
            ans = max(ans, temp);
        }
        cout << ans+1<<endl;
        
    }

    return 0;
}