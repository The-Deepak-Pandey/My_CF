#include <bits/stdc++.h>
using namespace std;
#define int long long int

int32_t main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int n, k, x;
        cin >> n >> k >> x;
        int minSum = 0;
        int maxSum = 0;
        minSum = (k*(k+1))/2;
        maxSum = (n*(n+1) - (n-k)*(n-k+1))/2;
        if(x<=maxSum && x>=minSum){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }

    }

    return 0;
}