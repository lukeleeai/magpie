#include<stdio.h>

#include"stdc++.h"

using namespace std;

struct node

{

    string s;

    int x,num;

}a[100000];

int cmp1(node a,node b)

{

    if(a.s==b.s)

    {

        return a.x>b.x;

    }

    else

    {

        return a.s<b.s;

    }

}

int main()

{

    int n;

    scanf("%d",&n);

    for(int i=1;i<=n;i++)

    {

        a[i].num=i;

        cin>>a[i].s;

        scanf("%d",&a[i].x);

    }

    sort(a+1,a+n+1,cmp1);

    for(int i=1;i<=n;i++)

    {

        printf("%d\n",a[i].num);

    }



    return 0;

}
