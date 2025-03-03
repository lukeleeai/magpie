#include "stdc++.h"

using namespace std;



int main()

{



    char aa[100100];

    char bb[100100];

    int dp[100100];

    int dp1[100100];

    int a1,a2,a3,a4;

    char ans1,ans2;

    scanf("%s%s",&aa,&bb);

    dp[0]=0;

    for(int i=0;aa[i];i++)

    {

        if(dp[i]==0)

        {

            dp[i+1]=aa[i]-'A'+1;

        }

        else if(dp[i]==1)

        {

            if(aa[i]=='B')

            {

                dp[i+1]=0;

            }

            else

            {

                 dp[i+1]=2;

            }

        }

        else

        {

             if(aa[i]=='B')

            {

                dp[i+1]=1;

            }

            else

            {

                 dp[i+1]=0;

            }

        }

    }

     dp1[0]=0;

    for(int i=0;bb[i];i++)

    {

        if(dp1[i]==0)

        {

            dp1[i+1]=bb[i]-'A'+1;

        }

        else if(dp1[i]==1)

        {

            if(bb[i]=='B')

            {

                dp1[i+1]=0;

            }

            else

            {

                 dp1[i+1]=2;

            }

        }

        else

        {

             if(bb[i]=='B')

            {

                dp1[i+1]=1;

            }

            else

            {

                 dp1[i+1]=0;

            }

        }

    }

    int n;

    scanf("%d",&n);

    int flag=0;

    for(int ii=0; ii<n; ii++)

    {

        scanf("%d%d%d%d",&a1,&a2,&a3,&a4);

       if(dp[a1-1]==dp[a2])

       {

           ans1='e';

          // flag=1;

       }

       else if(dp[a1-1]==0&&dp[a2]!=0)

       {

           ans1=dp[a2]-1+'A';

          // flag=2;

       }

       else if(dp[a2]==0)

       {

           if(dp[a1-1]==1)

           {

               ans1='B';

            //   flag=3;

           }

           else

           {

              ans1='A';

              //flag=4;

           }

       }

       else

       {

           ans1=dp[a1-1]-1+'A';

         //  flag=5;

       }

        if(dp1[a3-1]==dp1[a4])

       {

           ans2='e';

           flag=2;

       }

       else if(dp1[a3-1]==0&&dp1[a4]!=0)

       {

           ans2=dp1[a4]-1+'A';

           flag=3;

       }

       else if(dp1[a4]==0)

       {

           if(dp1[a3-1]==1)

           {

               ans2='B';

               flag=4;

           }

           else

           {

               ans2='A';

               flag=5;

           }

       }

       else

       {

           ans2=dp1[a3-1]-1+'A';

           flag=6;

       }

     //  printf("%d\n",flag);

       //printf("%c %c\n",ans1,ans2);

              if(ans1==ans2)

       {

           printf("YES\n");

       }

       else

       {

           printf("NO\n");

       }

    }

    return 0;

}
