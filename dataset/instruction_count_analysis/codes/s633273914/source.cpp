#include<iostream>

#include<algorithm>

#include<cstdio>

#include<cstring>

#include<stdlib.h>

using namespace std;

const int N=1e4+50;

const int INF=0x3f3f3f;

char s[N];

int vis[N];

int main()

{

    scanf("%s",s);

    int len=strlen(s);

    for(int i=0;i<len;i++)

    {

        vis[(int)s[i]]++;

    }

    for(int i=97;i<=122;i++)

    {

        if(vis[i]%2!=0)

        {

            printf("No\n");

            return 0;

        }

    }

    printf("Yes\n");

    return 0;

}