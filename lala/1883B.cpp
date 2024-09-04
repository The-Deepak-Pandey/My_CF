#include <bits/stdc++.h>
using namespace std;

int main() {

    int t;
    cin >> t;
    while(t--){
        int k, n;
        cin >> n >> k;
        string s;
        cin >> s;
        int freq[26] = {0};
        for(char it : s){
            freq[it-'a']++;
        }
        int cnt = 0;
        int odd = 0;
        int even = 0;
        for(int i = 0; i<26; i++){
            int it = freq[i];
            if(it!=0){
                cnt++;
                if(it%2==0){
                    even++;
                }
                else{
                    odd++;
                }
            }
        }
        // cout<< "Odd : "<<odd << "Even : "<< even << "Count : "<<cnt<<endl;
        if(odd>k+1){
            cout<<"NO"<<endl;
        }
        else{
            cout<<"YES"<<endl;
        }

    }

    return 0;
}