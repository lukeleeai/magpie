#include<iostream>

#include<cstdio>

#define K 21000

using namespace std;

int a[20100],b[20100],p[20100],n;

int main()

{

	scanf("%d",&n);

	for(int i=1;i<=n;i++)scanf("%d",&p[i]);

	for(int i=1;i<=n;i++)a[i]=i*K;

	for(int i=n;i>=1;i--)b[i]=a[n-i+1];

	for(int i=1;i<=n;i++)

	{

		a[p[i]]-=(n-i+1);b[p[i]]-=(n-i+1);

	}

	for(int i=1;i<=n;i++)printf("%d ",a[i]);cout<<endl;

	for(int i=1;i<=n;i++)printf("%d ",b[i]);return 0;

 } 