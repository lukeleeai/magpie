#include<stdio.h>

#include<string.h>

#include<algorithm>

using namespace std;

int a[120000];

int b[100000];

int main()

{

    int n;

    scanf("%d",&n);

    for(int i=0; i<n; i++)

        scanf("%d",&a[i]);

    sort(a,a+n);

    memset(b,0,sizeof(b));

    int s=0,j=0;

    for(int i=0; i<n; i++)

    {

        b[j]++;

        while(a[i]==a[i+1])

        {

            b[j]++;

            i++;

        }

        if(b[j]&1)

            s++;

        j++;

    }

    printf("%d\n",s);

    return 0;

}