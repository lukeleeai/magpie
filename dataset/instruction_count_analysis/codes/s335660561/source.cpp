#include<cstdio>

#include<algorithm>

#include<cmath>

using namespace std;

const int maxn=2e5+10;

const int N=1e6+10;

typedef long long ll;

const ll mod=1e9+7;

#define per(i,a,b) for(int i=a;i<b;i++)

#define rep(i,a,b) for(int i=a;i<=b;i++)

#define inf 0x3f3f3f3f

#define qwq puts("QWQ");

#define qaq puts("QAQ");

#define mem(a,b) memset(a,b,sizeof(a))

#define mid ((l+r)>>1)

#define l(x) x<<1

#define r(x) x<<1|1

#define lson rt<<1,l,mid

#define rson rt<<1|1,mid+1,r

void read(int &x)

{

	int f=1;x=0;

	char s=getchar();

	while(s<'0'||s>'9')

    {

    	if(s=='-')f=-1;

    	s=getchar();

	}

	while(s>='0'&&s<='9')x=x*10+s-'0',s=getchar();

	x*=f;

}

int main()

{

	double w,h,x,y,sa,sb,sc,sd,ans,sum;

	int flag=0;

	scanf("%lf%lf%lf%lf",&w,&h,&x,&y);

	sum=w*h;

	if(x==w/2&&y==h/2)flag=1;

	printf("%.6lf %d\n",sum/2,flag);

}