#include<cstdio>

#include<cstring>

#include<queue>

#include<cmath>

using namespace std;

char s[100001];

int main()

{

    scanf("%s",s);

    int len=strlen(s);

    if(s[0]==s[len-1])

    {

        if(len%2==1)

    printf("Second");

        else

    printf("First");

    }

    else

    {

        if(len%2==1)

    printf("First");

        else

    printf("Second");

    }

    return 0;

}