#include <iostream>

using namespace std;

int main()
{

    int t;

    cin >> t;

    while (t--)
    {

        long long n, k;

        cin >> n >> k;

        if (n % 2 == 0)
        {

            long long steps = (n + k - 2) / (k - 1);

            cout << steps << endl;
        }
        else
        {

            if (n <= k)
            {

                cout << 1 << endl;
            }
            else
            {

                long long steps = 1 + (n - 2) / (k - 1);

                cout << steps << endl;
            }
        }
    }

    return 0;
}