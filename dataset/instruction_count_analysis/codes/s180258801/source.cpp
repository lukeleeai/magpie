#include<cstdio>  

#include<cmath>  

#include<iostream>  

#include<cstring>  

#include<iostream>  

#include<cstdlib>  

#include<string>  

using namespace std;  

#define LL long long   

const int MaxN = 1e5 + 7;  

LL a[MaxN], b[MaxN];    

LL x[MaxN], v[MaxN];  

  

int main()  

{  

    LL n, c;  

    scanf("%lld %lld", &n, &c);  

    for(int i = 1; i <= n; i++)   

        scanf("%lld %lld", &x[i], &v[i]);  

      

    for(LL i = 1; i <= n; i++)   

        a[i] = a[i - 1] + v[i] - (x[i] - x[i - 1]);  // 顺时针走到i点时的能量  

    x[n + 1] = c;  

    for(LL i = n; i >= 1; i--)   

        b[i] = b[i + 1] + v[i] - (x[i+1] - x[i]);  // 逆时针走到i点时的能量  

  

    for(LL i = 2; i <= n; i++)   

        a[i] = max(a[i-1], a[i]);  //走或者不走（和走之前的值进行比较）  

    for(LL i = n-1; i >= 1; i--)   

        b[i] = max(b[i], b[i + 1]);  

  

    LL ans = 0;  

    for(LL i = 1; i <= n; i++) {  

        ans = max(ans, a[i] - x[i] + b[i + 1]);  // 顺时针走后并返回一次的值  

        ans = max(ans, b[i] - (c - x[i]) + a[i - 1]);  // 逆时针走后返回一次的值  

        ans = max(ans, a[i]);  // 顺时针的最大值  

        ans = max(ans, b[i]); //逆时针的最大值  

    }  

  

    printf("%lld\n", ans);  

} 