#include <bits/stdc++.h>
using namespace std;
#define int long long int

int32_t main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int a, b;
        cin >> a >> b;
        int xk, yk;
        cin >> xk >> yk;
        int xq, yq;
        cin >> xq >> yq;

        int dx[] = {-a, -a, a, a, -b, b, -b, b};
        int dy[] = {-b, b, -b, b, -a, -a, a, a};
        set<pair<int, int>> st1, st2;
        for(int i  = 0; i<8; i++){
            int nx = xk+dx[i];
            int ny = yk+dy[i];
            st1.insert({nx, ny});

            nx = xq+dx[i];
            ny = yq+dy[i];
            st2.insert({nx, ny});
        }
        int ans = 0;
        for(auto it : st1){
            if(st2.find(it)!=st2.end()){
                ans++;
            }
        }
        cout<<ans<<endl;
    }

    return 0;
}