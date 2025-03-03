#include <stdio.h>

#include <math.h>

#include <stdlib.h>

/*int min(double *x,int n){

	int i,c=0;

	double ans;

	ans=100005;

	for(i=0; i<n; i++){

		if(ans>x[i]){

			ans=x[i];

			c=i;

		}

	}

	return c;

}*/

int main()

{

	int n,i,c=0;

	double h[1005],max,m=0.006,f,t,a,ans[1005];

	scanf("%d%lf%lf",&n,&t,&a);

	max=1000000.000;

	for(i=0; i<n; i++){

		scanf("%lf",&h[i]);

		f=(h[i]*m);

		f=t-f;

		ans[i]=abs(a-f);

		if(ans[i]<max){

			max=ans[i];

			c=i;

		}

		//printf("%lf\n",ans[i]);

	}

	printf("%d\n",c+1);

	return 0;

}
