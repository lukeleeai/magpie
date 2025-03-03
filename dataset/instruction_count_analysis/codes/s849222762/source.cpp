#include<cstdio>

#define tin int

#define itn int

#define tni int

#define nit int

#define nti int

#define pritnf printf

#define scnaf scanf

#define retrun return

#define sizoef sizeof

#define ll long long

#define inl inline

#define br break

#define con continue

#define mst(a,b) memset(a,b,sizeof(a))

#define re register itn

#define fora(x,a,b) for(re x=a;x<=b;++x)

#define forb(x,a,b) for(re x=a;x>=b;--a)

#define infa 0x3f3f3f3f

#define infb 0x7fffffff

#define infc 1061109567

#define infd 0x7f

using namespace std;

#define maxa 100004

#define maxb 10004

#include<cstring>



tni num,x,n[maxa]={0},sum=0;



tin main()

{

	scanf("%d",&num);

	fora(i,1,num)

	{

		scanf("%d",&x);

		if(x>num)

		{

			++sum;

		}

		else

		{

			++n[x];

		}

	}

	//

	fora(i,1,num)

	{

		if(n[i]<i)

		{

			sum+=n[i];

		}

		else if(n[i]>i)

		{

			sum+=n[i]-i;

		}

	}

	//

	printf("%d\n",sum);

	return 0;

}