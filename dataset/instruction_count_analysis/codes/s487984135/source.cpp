#include <iostream>

#include <cstdio>

using namespace std;

long long n,m,sum;

int main()

{

    scanf("%lld%lld%lld",&n,&m,&sum);



        for(int i=0;i<n;i++)

        {

            if(i<m)

            {printf("%lld",sum);

            }

            else

            {

//                if(i==m &&m<n)

//                    printf("1000000000");

                if(sum!=1000000000)printf("1000000000");

                else printf("15485863");

            }

            if(i!=n-1) printf(" ");

            else printf("\n");

        }





    return 0;



}