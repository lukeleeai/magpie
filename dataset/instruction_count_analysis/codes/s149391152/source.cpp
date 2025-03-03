#include<stdio.h>

#include<algorithm>

using namespace std;

int main()

{int n,d[100000],i,j;

while(~scanf("%d",&n))

  {

  for(i=0;i<n;i++)

    scanf("%d",&d[i]);

    sort(d,d+n);

    printf("%d\n",d[n/2]-d[n/2-1]);}

  

}