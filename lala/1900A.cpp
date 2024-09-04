#include <bits/stdc++.h>
using namespace std;

int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<char> s(n);
        int dj = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> s[i];
            if (s[i] == '.')
            {
                dj++;
            }
        }
        int count = 0;
        int flag = 0;
        for (auto it : s)
        {
            if (it == '.')
            {
                count++;
                if (count == 3)
                {
                    flag = 1;
                    break;
                }
            }
            else
            {
                count = 0;
            }
        }
        if (flag)
        {
            cout << "2" << endl;
        }
        else
        {
            cout << dj << endl;
        }
    }

    return 0;
}