#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
int main()
{
    int t;
    scanf("%d", &t);
    int mincoins = 0;
    while (t--)
    {
        int n;
        scanf("%d", &n);
        int arr15[16] = {0, 1, 2, 1, 2, 3, 1, 2, 3, 2, 1, 2, 3, 2, 3, 1};
        int brr[5] = {1, 3, 6, 10, 15};
        int arr1[2] = {0, 1};
        int arr6[7] = {0, 1, 2, 1, 2, 3, 1};
        int arr3[5] = {0, 1, 2, 1, 2};
        int arr10[11] = {0, 1, 2, 1, 2, 3, 1, 2, 3, 2, 1};
        int ans = __INT_MAX__;
        if ((n / 15) + arr15[n % 15] < ans)
        {
            ans =( n / 15) + arr15[n % 15];
        }
        if ((n / 10) + arr10[n % 10] < ans)
        {
            ans = (n / 10) + arr10[n % 10];
        }
        if ((n / 6) + arr6[n % 6] < ans)
        {
            ans = (n / 6) + arr6[n % 6];
        }
        if ((n / 3) + arr3[n % 3] < ans)
        {
            ans = (n / 3) + arr3[n % 3];
        }
        // if((n/1)+arr10[n%10]<ans)
        // {
        //     ans=(n/10)+arr10[n%10];
        // }

        printf("%d\n", ans);
    }
}