#include <bits/stdc++.h>
using namespace std;

int main()
{

    int r;
    cin >> r;
    while (r--)
    {
        string s;
        cin >> s;
        int n = s.length();
        int zero = 0;
        int one = 0;
        for(auto it : s){
            if(it == '1'){
                one++;
            }
            else{
                zero++;
            }
        }
        int count = 0;
        int flag = 0;
        for(auto it : s){
            if(it=='1' && zero>0){
                zero--;
                count++;
            }
            else if(it=='1' && zero == 0){
                cout<<n-count<<endl;
                flag = 1;
                break;
            }
            if(it=='0' && one>0){
                one--;
                count++;
            }
            else if(it=='0' && one==0){
                cout<<n-count<<endl;
                flag = 1;
                break;
            }
        }
        if(!flag)
        cout<<"0"<<endl;
    }

    return 0;
}