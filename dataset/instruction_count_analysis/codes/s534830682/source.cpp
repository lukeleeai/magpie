#include<cstdio>

#include<algorithm>

#define MAXN 20006

using namespace std;

int a[MAXN],cnt,n;

int main()

{

	scanf("%d",&n);

	if(n==3)

	{

		printf("2 5 63");

		return 0;

	}

	cnt=4;

	n-=4;

	a[1]=3;

	a[2]=9;

	a[3]=2;

	a[4]=4;

	while(n>=2&&a[cnt]+6<=30000)

	{

		n-=2;

		cnt++;

		a[cnt]=a[cnt-1]+4;

		cnt++;

		a[cnt]=a[cnt-1]+2;

	}

	while(n>=2&&(a[cnt]%2==0||a[cnt]+4*3<=30000))

	{

		n-=2;

		cnt++;

		if(a[cnt-1]%2==0) a[cnt]=15;

		else a[cnt]=a[cnt-1]+6;

		cnt++;

		a[cnt]=a[cnt-1]+6;

	}

	while(n>=1&&(a[cnt]%6!=0||a[cnt]+6<=30000))

	{

		n--;

		cnt++;

		if(a[cnt-1]%6!=0) a[cnt]=6;

		else a[cnt]=a[cnt-1]+6;

	}

	sort(a+1,a+1+cnt);

	for(int i=1;i<=cnt;i++)

		printf("%d ",a[i]);

}