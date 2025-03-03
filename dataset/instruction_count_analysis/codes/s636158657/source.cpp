#include<cstdio>

#include<cstring>

char a[11];

int add[10],len;

long long ans=0;

void getsum1()

{

    long long temp=0;

    for (int i = 0; i < len; i++)

    {

        if(add[i])

        {

            ans+=temp;

            temp=0;

        }

        temp=temp*10+a[i]-'0';

    }

    ans+=temp;

}

void getsum2()

{

    long long temp = a[0]-'0';

    for (int i = 1; i < len; i++)

    {

        if (!add[i])

        {

            ans += temp;

            temp = 0;

        }

        temp = temp * 10 + a[i] - '0';

    }

    ans += temp;

}

void dfs(int pos,int num)

{

    if(!num)

    {

        getsum1();

        //getsum2();

        return;

    }

    for (int i = pos; i < len-num+1; i++)

    {

        add[i]=1;

        dfs(i+1,num-1);

        add[i]=0;

    }

}

int main()

{

    scanf("%s",a);

    len=strlen(a);

    for (int i = 0; i < len; i++)

    {

        dfs(1,i);

    }

    printf("%lld",ans);

}