#include "stdc++.h"

using namespace std;

int i,j,n,m,x,y,ans[2100],minn;

int main()

{

	scanf("%d%d%d",&n,&x,&y);

	for (i=1;i<n;i++)

	 for (j=i+1;j<=n;j++)

	  if (i>=y||j<=x)  ans[j-i]++;else

	  if (i<=x&&j>=y) ans[j-i-(y-x)+1]++;else

	  {

	  	minn=j-i;

	  	minn=min(minn,abs(i-x)+1+abs(j-y));

	  	minn=min(minn,abs(i-y)+1+abs(j-x));

	  	minn=min(minn,abs(j-y)+1+abs(i-x));

		minn=min(minn,abs(j-x)+1+abs(i-y)); 

		ans[minn]++;

	  }

	for (i=1;i<n;i++) printf("%d\n",ans[i]);

}