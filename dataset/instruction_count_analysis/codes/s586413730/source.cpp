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

}

using ae86::ty;



const int N = 400 , _ = N + 3 , mo = 998244353;



template<typename T1,typename T2> inline T1 ad(T1 &a,T2 b){return a=a+b>=mo?a+b-mo:a+b;}

template<typename T1,typename T2> inline T1 dl(T1 &a,T2 b){return a=a>=b?a-b:a-b+mo;}



inline lint powa(lint a,lint t)

{

	lint b=1;

	while(t){if(t&1)b=b*a%mo;a=a*a%mo,t>>=1;}

	return b;

}



inline lint inva(lint a)

{

	return powa(a,mo-2);

}



lint jc[_],rjc[_];



inline void fuck(int n=_-1)

{

	jc[0]=jc[1]=rjc[0]=1;

	for(int i=2;i<=n;i++)jc[i]=jc[i-1]*i%mo;

	rjc[n]=inva(jc[n]);

	for(int i=n-1;i>=1;i--)rjc[i]=rjc[i+1]*(1ll+i)%mo;

}



int n,lim[_];

lint f[_][_]={0},gai[_],sgai=0;



int main()

{

	n=ty();

	for(int i=1;i<=n;i++)gai[i]=ty(),lim[i]=ty(),sgai=(sgai+gai[i])%mo;

	

	fuck();

	f[0][0]=mo-1;

	for(int i=1;i<=n;i++)

		for(int j=sgai;j>=0;j--)

			for(int k=N;k>=0;k--)

				if(f[j][k])

					for(int a=0,x=1;a<lim[i];a++,x=1ll*x*gai[i]%mo)

						dl(f[j+gai[i]][k+a],f[j][k]*x%mo*rjc[a]%mo);

	lint ans=0;

	for(int i=1;i<=sgai;i++)

		for(int j=0,perx=inva(i),x=sgai*inva(i)%mo;j<=N;j++,x=1ll*x*perx%mo)

			ad(ans,f[i][j]*jc[j]%mo*x%mo);

	printf("%lld\n",ans);



	return 0;

}
