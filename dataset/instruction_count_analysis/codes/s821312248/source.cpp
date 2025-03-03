#include<stdio.h>

#include<bits/locale_facets.h>

#include<algorithm>

using namespace std;

int a[100001];

long long input();

int main()

{

	int n=input(),total=0;

	for(int i=1;i<=n;i++)a[i]=input();

	sort(a+1,a+n+1);

	if(a[n]-a[1]>1||a[n]>=n)printf("No");

	else if(a[n]==a[1])

	{

		if(a[n]*2>n&&a[n]<n-1)printf("No");

		else printf("Yes");

	}

	else

	{

		for(int i=1;i<=n&&a[i]<a[n];i++)total++;

		if(0<a[n]-total&&2*a[n]<=n+total)printf("Yes");

		else printf("No");

	}

	return 0;

}

long long input()

{

	long long value=0,positive=1;

	char digit=getchar();

	for(;!isdigit(digit);digit=getchar())

	if(digit=='-')positive=-positive;

	for(;isdigit(digit);digit=getchar())value=(value<<3)+(value<<1)+digit-'0';

	return positive*value;

}