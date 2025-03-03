#include<stdio.h>

#include<string.h>

#include<algorithm>

using namespace std;

#define N 200010

char s1[N],s2[N];

int a[30],b[30];

int main()

{

    int i,j,k;

    scanf("%s%s",s1,s2);

    k=strlen(s1);

    for(i=0;i<k;i++)

    {

        j=s1[i]-'a';

        a[j]++;

    }

    k=strlen(s2);

    for(i=0;i<k;i++)

    {

        j=s2[i]-'a';

        b[j]++;

    }

    sort(a,a+30);

    sort(b,b+30);

    for(i=0;i<30;i++)

    if(a[i]!=b[i])

    {

        printf("No\n");

        return 0;

    }

    printf("Yes\n");

    return 0;

}