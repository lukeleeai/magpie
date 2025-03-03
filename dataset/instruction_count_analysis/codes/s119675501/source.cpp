#include<iostream>

#include<cstdlib>

#include<algorithm>

#include<cmath>

#include<cstring>

#include<cstdio>

#include<queue>

#define LL long long

using namespace std;

int n,tot,r,ans; 

int a[1000001],b[1000001];

int read()

{

	int _=0,__=1;char ch=getchar();

	while(ch<'0'||ch>'9') {if(ch=='-')__=-1;ch=getchar();}

	while(ch>='0'&&ch<='9'){_=_*10+ch-'0';ch=getchar();}

	return _*__;

}

//该题主要思路在于想到去求连续(数字连续而不是位置连续)的上升子序列，然后用总数减就可以了，这题的结论得出的比较玄学，未能严格证明 

int main()

{

	n=read();

	for(int i=1;i<=n;i++)

	a[i]=read();

	for(int i=1;i<=n;i++)

	b[a[i]]=i; 

	r=-1;ans=-1;

	for(int i=1;i<=n;i++)

	{

		if(b[i]>r)

		{

			++tot;

			r=b[i];

		}

		else

		{

			ans=max(ans,tot);

			tot=1;

			r=b[i];

		}

	}

	ans=max(ans,tot);

	printf("%d\n",n-ans);

	return 0;

	

 }


