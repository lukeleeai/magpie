#include <stdio.h>

#include <iostream>

#include <algorithm>

#include <string.h>

#define ll long long 

using namespace std;

struct node 

{

	int a[1000]={0};

	int num;

	

 }s[1005]; 

int main()

{	

	s[0].a[0]=2;s[0].num=0;

	s[1].a[0]=1;s[1].num=0;

	for(int i=2;i<=1000;i++)

	{

		for(int k=0;k<=s[i-1].num;k++)

		{

			s[i].a[k]+=s[i-1].a[k]+s[i-2].a[k];

			if(s[i].a[k]>=10)

			{

				s[i].a[k+1]++;

				s[i].a[k]-=10;

			}			

		}

		if(s[i].a[s[i-1].num+1]!=0)

		s[i].num=s[i-1].num+1;

		else

		s[i].num=s[i-1].num;

	}

		int n;

		scanf("%d",&n);

		for(int i=s[n].num;i>=0;i--)

		printf("%d",s[n].a[i]);

		puts("");

	return 0;

}