#include<stdio.h>

#include<string.h>

#include<algorithm>

#include<queue>

using namespace std;

typedef struct pp

{   char x[50];

    int t,R;

}S;

S s[105];

bool cmp(int a,int b)

{   return a>b;

}

int main()

{   int i,j,T,n,maxn=0,k,s=0,q;

    int y[26]={0};

    char x[6000];

    scanf("%d",&n);

    scanf("%s",x);

    for(i=0;i<n-1;i++)

    {

        for(j=i+1;j<n;j++)

        {   if(x[i]==x[j]&&x[i-1]!=x[j-1])

            {   //if(j==2)printf("##\n");

                q=1;

                for(k=1;k<j-i;k++)

                {   if(x[i+k]==x[j+k])q++;

                    else break;

                }

                if(q>maxn&&j-i>=q)maxn=q;

                //if(j==2)printf("##%d\n",q);

            }

        }

    }

    printf("%d\n",maxn);

    return 0;

}


