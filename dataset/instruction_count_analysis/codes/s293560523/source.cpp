#include<stdio.h>

int s1=0,s2=0,sum=0,sss;

int w[200];

int main()

{

    int n;

    scanf("%d",&n);

    for(int i=1;i<=n;i++)

    {

        scanf("%d",&w[i]);

        if(i==1) s1+=w[i];

        else  s2+=w[i];

    }

    if(s1>s2) sum=s1-s2;

    else sum=s2-s1;

    if(sum==0) printf("%d\n",sum);

    else

    {

        for(int i=2;i<=n;i++)

        {

//            printf("*********%d\n",i);

            s1+=w[i];

            s2-=w[i];

            if(s1>s2) sss=s1-s2;

            else sss=s2-s1;

//            printf("&&&&&&&&%d\n",sss);

            if(sss<sum) sum=sss;

//            printf("################%d\n",sum);

            if(sum==0) break;

        }

        printf("%d\n",sum);

    }

    return 0;

}
