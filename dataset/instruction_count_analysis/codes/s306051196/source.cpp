#include<iostream>

#include<algorithm>

#include<cstdio>

#include<cmath>

#include<cstring>

#include<stack>

using namespace std;

#define ll long long

#define mod 1000000007



int a[100005];

int a2[100005];

int main()

{

    int i,t,j,len,temp,N,Q,K;

    while(scanf("%d%d%d",&N,&K,&Q)!=EOF)

    {

        memset(a2,0,sizeof(a2));

        for(i=0;i<Q;i++)

        {

            scanf("%d",&temp);

            a2[temp]++;

        }

        for(i=1;i<=N;i++)

        {

            a[i]=K-Q+a2[i]; //不成功的局都得-1分

            if(a[i]<=0)

                printf("No\n");

            else

                printf("Yes\n");

        }

    }

    return 0;

}


