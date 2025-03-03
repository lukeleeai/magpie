#include<stdio.h>

#include<iostream>

#include<string.h>

using namespace std;



const int M=1e5+5;

int a[M];

int datagroup=0;



int main()

{

    int num;

    memset(a,0,sizeof(a));

    scanf("%d",&datagroup);

    for(int i=1;i<=datagroup;i++)

    {

        scanf("%d",&num);

        a[num]=i;

    }

    for(int i=1;i<=datagroup;i++)

    {

        printf("%d",a[i]);

        if(i!=datagroup)

        printf(" ");

    }

    return 0;

}
