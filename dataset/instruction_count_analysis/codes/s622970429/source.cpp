#include<cstdio>



using namespace std;

int t,count=0;

void dfs(long long num,int flag357){

    if(num <= t){

        if(flag357==07)

            count++;

        dfs(num*10+3,flag357|01);

        dfs(num*10+5,flag357|02);

        dfs(num*10+7,flag357|04);

    }

}

int main()

{

    scanf("%d",&t);

    dfs(0,0);

    printf("%d",count);

    return 0;

}
