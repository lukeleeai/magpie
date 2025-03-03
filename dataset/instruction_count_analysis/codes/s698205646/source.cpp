#include"stdc++.h"



using namespace std;



int n,k,t,l;

double a,p,ans;



int main()

{

	scanf("%d%lf%lf",&n,&a,&p);

	a-=p;

	t=2*n;

	l=n;

	for(int i=1; i<=n; i++)

	{

		ans+=(double)(a*t+p*t*(t+1)/2)/t;

		a=a+a/l+3*p/(2*l);

		p=p+2*p/l;

		l--;

		t-=2;

	}

	printf("%.9lf",ans);

	return 0;

}