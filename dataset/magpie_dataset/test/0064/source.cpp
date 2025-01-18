#include<iostream>

#include<cstdio>

#include<cstdlib>

#include<cstring>

#include<cmath>

#include<algorithm>

using namespace std;

char a[10000005];

int b[10000005],l;

int main()

{

	scanf("%s",a);

	int x=strlen(a);

	for(int i=0;i<x;i++)

	{

		if(a[i]=='0')b[++l]=0;

		else if(a[i]=='1')b[++l]=1;

		else if((a[i]=='B')&&(l))l--;

	}

	for(int i=1;i<=l;i++)printf("%d",b[i]);

	printf("\n");

	return 0;

}