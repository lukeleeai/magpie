#include<cstdio>

#include<cstring>

#include<algorithm>

int n,k,tmp;

bool u[11];

bool check(int t)

{

    while(t)

    {

        if (u[t%10]) return 0;

        t/=10;

    }

    return 1;

}

int main()

{

    scanf("%d%d",&n,&k);

    for(int i=1;i<=k;i++)

    {

        scanf("%d",&tmp);

        u[tmp]=1;

    }

    int cur=n;

    while(!check(cur)) cur++;

    printf("%d",cur);

}
