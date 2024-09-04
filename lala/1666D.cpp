#include <bits/stdc++.h>
using namespace std;

int main() {

    int t;
    cin >> t;
    while(t--){
        string s, t;
        cin >> s >> t;
        int fs[26]={0}, ft[26]={0};
        for (int i = 0; i < s.length(); i++)
        {
            fs[s[i]-'A']++;
        }
        for (int i = 0; i < t.length(); i++)
        {
            ft[t[i]-'A']++;
        }
        int called[26]={0};
        int flag = 0;
        for (int i = 0; i < 26; i++)
        {
            called[i] = fs[i]-ft[i];
            if(called[i]<0){
                flag = 1;
                cout<<"NO\n";
                break;
            }
        }
        if(flag==1){
            continue;
        }
        else{
            string ans = "";
            for (int i = 0; i < s.length(); i++)
            {
                if(called[s[i]-'A']==0){
                    ans.push_back(s[i]);
                }
                else{
                    called[s[i]-'A']--;
                }
            }
            // cout << ans<<endl;
            if(ans==t){
                cout << "YES\n";
            }
            else{
                cout << "NO\n";
            }
        }
        
    }

    return 0;
}