#include <bits/stdc++.h>
 
using namespace std;
 
#define lli long long int
#define ffl(i,m,n) for(lli i=m;i<n;i++)
#define bfl(j,m,n) for(lli j=m;j>=n;j--)
#define sorting(arr) sort(arr.begin(),arr.end())
 
 
void solve() {
    lli n;
    cin >> n;
   
    lli x = sqrt(n);
    lli a = 1, b = n - 1;
    lli check = n - 1;
    lli mini = 1;
    for(lli i = 2; i <= x; i++) {
        if(n % i == 0) {
            mini = n/i;
            break;
        }
    }
    cout << mini << " " << n-mini << endl;
}
 
int main() {
    lli t;
    cin >> t;
    for(lli f = 0; f < t; f++) {
        solve();
    }
    return 0;
}