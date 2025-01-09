#include <iostream>
#include <vector>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--)
    {
        long long l, r;
        cin >> l >> r;


        long long a = l;
        long long b;
        long long c=1;

        while(c*2<=r){
            c*=2;
        }
        if(c<1){
            c=1;
        }
        b = c-1;

        
        
        cout << a << " " << b << " " << c << endl;

    }
        return 0;
}
