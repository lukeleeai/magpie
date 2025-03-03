#include"stdc++.h"

using namespace std;



typedef long long lint;

typedef long double louble;



template<typename T1,typename T2> inline T1 max(T1 a,T2 b){return a<b?b:a;}

template<typename T1,typename T2> inline T1 min(T1 a,T2 b){return a<b?a:b;}



namespace ae86

{

	const int bufl = 1<<15;



	char buf[bufl],*s=buf,*t=buf;



	inline int fetch()

	{

		if(s==t){t=(s=buf)+fread(buf,1,bufl,stdin);if(s==t)return EOF;}

		return *s++;

	}



	inline int ty()

	{

		int a=0,b=1,c=fetch();

		while(!isdigit(c))b^=c=='-',c=fetch();

		while(isdigit(c))a=a*10+c-48,c=fetch();

		return b?a:-a;

	}



	template<typename T> inline int ts(T *s)

	{

		int a=0,c=fetch();

		while(c<=32 && c!=EOF)c=fetch();

		while(c>32 && c!=EOF)s[a++]=c,c=fetch();

		return a;

	}

}

using ae86::ty;

using ae86::ts;



const int alp = 26 , _ = 500007;



int n,s[_],las[alp],f[_],wha[_],nex[_];



int main()

{

	n=ts(s);

	for(int i=0;i<n;i++)s[i]-='a';

	for(int i=0;i<alp;i++)las[i]=n;



	memset(f,63,sizeof(f)),memset(nex,63,sizeof(nex));

	f[n+1]=0;

	for(int i=n-1;i>=0;i--)

	{

		las[s[i]]=i;

		for(int j=0;j<alp;j++)

			if(f[i]>f[las[j]+1]+1)

				f[i]=f[las[j]+1]+1,wha[i]=j,nex[i]=las[j]+1;

	}



	int now=0;

	while(now<n)putchar('a'+wha[now]),now=nex[now];

	puts("");



	return 0;

}
