#include<stdio.h>

#include<algorithm>

using namespace std;

const int MAX=200001;

int a[MAX];

int main()

{



  int n;

  scanf("%d",&n);

  for(int i=0;i<n;i++)

    scanf("%d",&a[i]);

    int maxv=-2000000000;

    int minv=a[0];

    for(int i=1;i<n;i++)

    {

        maxv=max(maxv,a[i]-minv);

        minv=min(minv,a[i]);

    }

    printf("%d\n",maxv);

    return 0;



}