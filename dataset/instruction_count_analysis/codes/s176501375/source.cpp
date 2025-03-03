#include<stdio.h>

#include<string.h>

using namespace std;

char a[200050];

int main()

{

    while(~scanf("%s",a))

    {

        int pre=-1;

        int back=-1;

        int n=strlen(a);

        for(int i=0;i<n;i++)

        {

            if(a[i]=='A'&&pre==-1)pre=i;

            if(a[i]=='Z')back=i;

        }

        if(pre==-1||back==-1)

        {

            printf("0\n");

        }

        else printf("%d\n",back-pre+1);

    }

}