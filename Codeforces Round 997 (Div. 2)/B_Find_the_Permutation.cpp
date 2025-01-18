#include <bits/stdc++.h>
using namespace std;

bool compare(int u, int v, const vector<string> &graph)
{
    if (u < v)
        return graph[u][v] == '1';
    return graph[v][u] == '0';
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<string> graph(n);

        for (int i = 0; i < n; i++)
        {
            cin >> graph[i];
        }

        vector<int> perm(n);

        for (int i = 0; i < n; i++)
        {
            perm[i] = i;
        }

        sort(perm.begin(), perm.end(), [&](int u, int v)
             { return compare(u, v, graph); });

        for (int i = 0; i < n; i++)
        {
            cout << perm[i] + 1 << (i + 1 == n ? "\n" : " ");
        }
    }
}