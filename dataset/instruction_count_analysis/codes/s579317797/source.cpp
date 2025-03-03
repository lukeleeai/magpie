#include<iostream>

#include<cstdio>

#include<algorithm>

using namespace std;

#define MAX 100100

inline int read()

{

	int x=0;bool t=false;char ch=getchar();

	while((ch<'0'||ch>'9')&&ch!='-')ch=getchar();

	if(ch=='-')t=true,ch=getchar();

	while(ch<='9'&&ch>='0')x=x*10+ch-48,ch=getchar();

	return t?-x:x;

}

int n,C,K,T[MAX],ans,s,t;

int main()

{

	n=read();C=read();K=read();

	for(int i=1;i<=n;++i)T[i]=read();

	sort(&T[1],&T[n+1]);

	for(int i=1;i<=n;++i)

		if(!s)++ans,s=1,t=T[i];

		else

		{

			if(s==C)++ans,s=1,t=T[i];

			else

			{

				if(T[i]-t>K)++ans,s=1,t=T[i];

				else ++s;

			}

		}

	printf("%d\n",ans);

	return 0;

}
