#include<stdio.h>

#include<stdlib.h>

#include<math.h>

#include<ctype.h>

#include<string.h>



#define size 100005



int main()

{

    int i, n, x, arr[size], least=0, sum, ans, min;

    scanf("%d%d", &n, &x);



    min = 1001;

    for(i=1; i<=n; i++)

    {

        scanf("%d", &arr[i]);

        least = least + arr[i];

        if(arr[i]<min)

            min = arr[i];

    }

    sum = x - least;

    ans = n + sum/min;

    printf("%d\n", ans);



    return 0;

}
