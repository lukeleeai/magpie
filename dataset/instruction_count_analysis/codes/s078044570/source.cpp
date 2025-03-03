#include<iostream>

#include<cstdio>

#include<cstring>

#include<algorithm>

using namespace std;

#define maxn 100010

char ss[maxn];

int main()

{

	int n;

	cin>>n;

	cin>>ss;

	int siz=sizeof(ss);

	char pre;

	pre=ss[0];

	int cnt=0;

	for(int i=1;i<siz;i++)

	{

		if(pre!=ss[i])

		{

			cnt++;

			pre=ss[i];

		 } 

	}

	cout<<cnt;

	return 0;

 } 