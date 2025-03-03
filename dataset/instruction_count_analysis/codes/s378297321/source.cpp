#include <stdio.h>

#include <math.h>

#include <stdlib.h>



int min(int a, int b)

{

    return a < b ? a : b;

}

int main()

{

    int n;

    scanf("%d", &n);

    int a[n];

    int dp[n];

    for (int i = 0; i < n; i++)

    {

        scanf("%d", &a[i]);

    }

    dp[0] = 0;

    dp[1] = abs(a[0] - a[1]);

    for (int i = 2; i < n; i++)

    {

        dp[i] = min((dp[i - 1] + abs(a[i] - a[i - 1])), (dp[i - 2] + abs(a[i] - a[i - 2])));

    }

    printf("%d\n", dp[n - 1]);

}