#include <iostream>

#include<cmath>

#include<cstdio>

using namespace std;

int main()

{

    long long a,b,c;

    while(~scanf("%lld",&a))

    {

        while(1)

        {

            b=sqrt(a);

            c=b*b;

            if(a==c)

            {

                printf("%lld\n",a);

                break;

            }



            else

                a--;

        }



    }



    return 0;

}
