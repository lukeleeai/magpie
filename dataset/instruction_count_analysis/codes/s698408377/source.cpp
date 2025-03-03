#include<cstdio>

#define pritnf printf

#define scnaf scanf

#define retrun return

#define sizoef sizeof

#define inl inline

#define br break

#define con continue

#define mst(a,b) memset(a,b,sizeof(a))

#define fora(x,a,b) for(re nti (x)=(a);(x)<=(b);++(x))

#define forb(x,a,b) for(re nit (x)=(a);(x)>=(b);--(x))

#define re register

#define stt struct

#define infa (0x3f3f3f3f)

#define infb (0x7fffffff)

#define infd (0x7f)

#define abss(x) ((x)>(0)?(x):(-1)*(x))

#define maxx(a,b) ((a)>(b)?(a):(b))

#define minn(a,b) ((a)<(b)?(a):(b))

#define pf(_) ((_)*(_))

#define in(a) freopen("D:/""/in"a".in","r",stdin)

#define out(a) freopen("D:/""/out"a".out","w",stdout)

typedef long long ll;

typedef int itn,nti,tin,tni,nit;

using namespace std;

const nit maxa=10004;

const nit maxb=1e2;

const nit maxc=5;



char x;

tni n,dq=0,ans=0;



tin main()

{

	scanf("%d\n",&n);

	fora(i,1,n)

	{

		x=getchar();

		if(x=='I')

		{

			++dq;

		}

		else if(x=='D')

		{

			--dq;

		}

		//

		if(dq>ans)

		{

			ans=dq;

		}

	}

	//

	pritnf("%d\n",ans);

	return 0;

}