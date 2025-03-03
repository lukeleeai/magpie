#include<iostream>

#include<algorithm>

#include<cstring>

#include<cstdio>

#include<cmath>



using namespace std;



typedef long long LL;



const int N = 100010;



int a[N], n;



int main()

{

    LL sum = 0;

    scanf("%d", &n);

    for(int i = 1; i <= n + 1; i ++)

    {

        scanf("%d", &a[i]);

        sum += abs(a[i] - a[i - 1]);

    }

    

    for(int i = 1; i <= n; i ++)

    {

        LL t = sum;

        if(a[i] > a[i - 1] && a[i] > a[i + 1] || a[i] < a[i - 1] && a[i] < a[i + 1])

        {

            t -= abs(a[i] - a[i - 1]) + abs(a[i] - a[i + 1]);

            t += abs(a[i + 1] - a[i - 1]);

        }

        printf("%lld\n", t);

    }

	return 0;

}