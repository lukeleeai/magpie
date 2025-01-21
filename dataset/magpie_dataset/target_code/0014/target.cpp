#include<cstdio>

#include<cstring>

#include<cstdlib>

#include<algorithm>

#include<cmath>

#include<queue>

#include<vector>

#include<ctime>

#include<map>

#include<bitset>

#include<set>

#define LL long long

#define mp(x,y) make_pair(x,y)

#define pll pair<long long,long long>

#define pii pair<int,int>

using namespace std;

inline int read()

{

	int f=1,x=0;char ch=getchar();

	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}

	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}

	return x*f;

}

int stack[20];

inline void write(LL x)

{

	if(x<0){putchar('-');x=-x;}

    if(!x){putchar('0');return;}

    int top=0;

    while(x)stack[++top]=x%10,x/=10;

    while(top)putchar(stack[top--]+'0');

}

inline void pr1(int x){write(x);putchar(' ');}

inline void pr2(LL x){write(x);putchar('\n');}



const int MAX_N=20;

int bin[MAX_N];

#define pr pair<int,int>

#define FR first

#define SE second

#define MP make_pair

int a[1<<MAX_N];pr b[1<<MAX_N];

int gmax(int x,int y){return a[x]>a[y]?x:y;}

pr merge(pr x,pr y)

{

	if(a[x.FR]>a[y.FR]) return MP(x.FR,gmax(x.SE,y.FR));

	else return MP(y.FR,gmax(x.FR,y.SE));

}

void fwt(int n)

{

	for(int i=0;i<n;i++)

		for(int j=bin[n]-1;j>=0;j--) if(j&bin[i])

				b[j]=merge(b[j],b[j^bin[i]]);

}

int main()

{

	bin[0]=1;for(int i=1;i<MAX_N;i++) bin[i]=bin[i-1]<<1;

	

	int n;scanf("%d",&n);a[bin[n]]=0;

	for(int i=0;i<bin[n];i++) scanf("%d",&a[i]),b[i]=MP(i,bin[n]);

	fwt(n);

	int lst=0;

	for(int i=1;i<bin[n];i++)

	{

		lst=max(a[b[i].FR]+a[b[i].SE],lst);

		printf("%d\n",lst);

	}

}

/*

4

75 26 45 72 81 47 97 97 2 2 25 82 84 17 56 32

*/
