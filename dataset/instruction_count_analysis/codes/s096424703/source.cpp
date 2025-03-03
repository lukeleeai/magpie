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



	inline int ts(char *s)

	{

		int a=0,c=fetch();

		while(c<=32 && c!=EOF)c=fetch();

		while(c>32 && c!=EOF)s[a++]=c,c=fetch();

		s[a]=0;

		return a;

	}

}

using ae86::ty;

using ae86::ts;



const int _ = 200007;



int n;char s[_];



int main()

{

	n=ts(s+1);



	lint ans=0;int cnta=0;

	for(int i=1;i<=n;)

	{

		if(s[i]=='A')cnta++,i++;

		else if(s[i]=='B' && s[i+1]=='C')ans+=cnta,i+=2;

		else cnta=0,i++;

	}

	printf("%lld\n",ans);



	return 0;

}
