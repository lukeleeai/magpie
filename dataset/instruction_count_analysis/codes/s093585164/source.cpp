#include<cstdio>

#include<cstring>

#include<iostream>

#include<algorithm>

#include<string.h>

#include<cmath>

using namespace std;

int main()

{

    long long n,m;

    scanf("%lld",&n);

    for(long long i = 1; i*i <= n; i++)

        m = i * i;

    printf("%lld\n",m);

}