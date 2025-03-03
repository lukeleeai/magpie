#include<stdio.h>

#include<fstream>

#include<algorithm>

using namespace std;

int a[2000005];

int main()

{

    int n;

    scanf("%d",&n);

    for(int i=0;i<n;i++)

    {

        scanf("%d",&a[i]);

    }

    sort(a,a+n);

    for(int i=0;i<n;i++)

    {

        if(i) printf(" ");

        printf("%d",a[i]);

    }

    printf("\n");

    return 0;

}