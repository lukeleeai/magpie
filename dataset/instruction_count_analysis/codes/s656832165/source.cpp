#include<stdio.h>



int main()

{

    long long int i, a, b, c, d,ans;

    long long int e,f,j,z;

    scanf("%lld%lld%lld%lld", &a, &b, &c, &d);



    z=a*c;

    e=a*d;

    f=b*c;

    j=b*d;

    //i = z;

   if(z>e&&z>f&&z>j)ans=z;

   else if(e>z&&e>f&&e>j)ans=e;

   else if(f>e&&f>z&&f>j)ans=f;

   else

    ans=j;

   printf("%lld",ans);



   return 0;

}