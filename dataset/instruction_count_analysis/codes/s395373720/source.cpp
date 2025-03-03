#include<stdio.h>  

#include<string.h>  

#include<math.h>  

#include<algorithm>  

using namespace std;  

int main()  

{  

    long long n, a, b, x1, x2;  

    scanf("%lld%lld%lld", &n, &a, &b);  

    x1=a;x2=b;  

    for(int i=0;i<n-1;i++)  

    {  

        scanf("%lld%lld", &a, &b);  

        long long temp=x1/a;  

        if(x1%a!=0)  

            temp++;  

        long long temp2=x2/b;  

        if(x2%b!=0)  

            temp2++;  

        long long m=max(temp, temp2);  

        x1=a*m;x2=b*m;  

    }  

    printf("%lld\n", x1+x2);  

    return 0;  

}   

       	

  

 