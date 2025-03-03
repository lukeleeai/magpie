#include<cstdio>

#include<math.h>

#include<string.h>

#include<stdlib.h>

#include<algorithm>

long long int t=1e9+7;

long long int cnt[1000000],ara[1000000];

using namespace std;

int main()

{

    long long int num,i,flag=1,d,ans=1;

    scanf("%lld",&num);

    flag=1;

    for(i=0;i<num;i++)

    {

        scanf("%lld",&ara[i]);

        cnt[ara[i]]++;

    }

    sort(ara,ara+num);

    if(num%2)

    {

        if(cnt[0]!=1)

        {

            printf("0\n");

            flag=0;

        }

        else

        {

            for(i=1;i+1<num;i++)

            {

                if(i%2)

                {

                    if(ara[i]==ara[i+1])

                    {

                        continue;

                    }

                    else

                    {

                        printf("0\n");

                        flag=0;

                        break;

                    }

                }

                else

                {

                    d=ara[i+1]-ara[i];

                    if(d==2)

                    {

                        continue;

                    }

                    else

                    {

                        printf("0\n");

                        flag=0;

                        break;

                    }

                }

            }

        }

    }

    else

    {

        if(cnt[1]!=2)

        {

            printf("0\n");

            flag=0;

        }

        else

        {

            for(i=1;i+1<num;i++)

            {

                if(i%2)

                {

                     d=ara[i+1]-ara[i];

                    if(d==2)

                    {

                        continue;

                    }

                    else

                    {

                        printf("0\n");

                        flag=0;

                        break;

                    }

                }

                else

                {

                    if(ara[i]==ara[i+1])

                    {

                        continue;

                    }

                    else

                    {

                        printf("0\n");

                        flag=0;

                        break;

                    }

                }

            }

        }



    }

    if(flag==1)

    {

        for(i=0;i<num/2;i++)

        {

            ans=(ans*2)%t;

        }

        printf("%lld\n",ans);

    }

    return  0;

}