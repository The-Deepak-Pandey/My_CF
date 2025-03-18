#include <bits/stdc++.h>
using namespace std;

int main()
{

    int t;
    cin >> t;

    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<int> freq(n + 1, 0);
        vector<int> colors(m);
        for (int i = 0; i < m; i++)
        {
            cin >> colors[i];
            freq[colors[i]]++;
        }
        vector<int> cCnt(n + 2, 0);
        for (int i = n; i >= 1; i--)
        {
            cCnt[i] = freq[i] + cCnt[i + 1];
        }
        long long answer = 0;
        for (int i = 1; i < n; i++)
        {
            int leftCount = cCnt[i];
            int rightCount = cCnt[n - i];
            int common = cCnt[max(i, n - i)];
            answer += 1LL * leftCount * rightCount - common;
        }
        cout << answer << "\n";
    }

    return 0;
}