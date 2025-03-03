#include<stdio.h>

#include<stdlib.h>

using namespace std;

const int maxn=1e5+10;

int n;

int a[maxn];

bool pre(int key)

{

    int left,right;

    left=0;

    right=n-1;

    int mid;

    while(left<=right)

    {

        mid=(left+right)/2;

        if(a[mid]==key)

            return true;

        if(key>a[mid])

            left=mid+1;

        else if(key<a[mid])

            right=mid-1;

    }

    return false;

}

int main()

{

    int sum=0;

    scanf("%d",&n);

    for(int i=0; i<n; i++)

        scanf("%d",&a[i]);

    int m;

    scanf("%d",&m);

    while(m--)

    {

        int x;

        scanf("%d",&x);

        if(pre(x))

            sum++;

    }

    printf("%d\n",sum);

    return 0;

}


