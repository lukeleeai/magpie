#include<cstdio>

#include<cmath>

#include<cstring>

#include<string>

#include<algorithm>

#include<vector>



#define maxn 205

#define maxm 10000005



using namespace std;



inline int getint()

{

	int num=0,flag=1;char c;

	while((c=getchar())<'0'||c>'9')if(c=='-')flag=-1;

	while(c>='0'&&c<='9')num=num*10+c-48,c=getchar();

	return num*flag;

}



int n;

long long F[3];



int main()

{

	n=getint();F[1]=F[2]=-1ll<<60;

	while(n--)

	{

		int x=getint();

		F[0]+=x,F[1]-=x,F[2]+=x;

		if(x<0)F[2]=max(F[2],F[1]),F[1]=max(F[1],F[0]);

		F[1]=max(F[1],F[2]),F[0]=max(F[0],F[1]);

	}

	printf("%lld\n",F[0]);

}