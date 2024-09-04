#include <bits/stdc++.h>
using namespace std;
#define lli long long int

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        lli x, y,k;
        cin >> x >> y >> k;
        while(k>0 && x!=1){
            lli rem = (x/y+1)*y - x;
            rem = min(rem, k);
            x+=rem;
            k-=rem;
            while(x%y==0){
                x/=y;
            }
        }
        cout<< x + k%(y-1)<<endl;
    }
}