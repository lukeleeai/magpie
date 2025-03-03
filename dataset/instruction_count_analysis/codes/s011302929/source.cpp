#include <iostream>

#include<stdio.h>

#include<cmath>

using namespace std;

int main()

{

    int N,s=1,temp=0;

    int a[100000];

    int b[100000]={0};

    const int c=1e9+7;

    scanf("%d",&N);

    for(int i=0;i<N;i++)

    {

        scanf("%d",&a[i]);

        if(N%2==0)

       {

           if((a[i]%2==0&&a[i])||a[i]==0) {printf("0\n");temp=0;break;}

           else

           {

               b[a[i]]++;

        if(b[a[i]]>2) {printf("0\n");temp=0;break;}

        else if(b[a[i]]==1) {s=(s*2)%c; temp=1;}

           }

       }

        else

        {

            if(a[i]%2!=0) printf("0\n");

        b[a[i]]++;

        if(b[a[i]]>2||b[0]>1) { printf("0\n");temp=0;break;}

        else if(b[a[i]]==1&&a[i]) {s=(s*2)%c; temp=1;}

        else if(b[a[i]]==1&&a[i]==0) {s=s%c;temp=1;}

        }

    }

    if(temp==1)

    printf("%d\n",s);

    return 0;

}