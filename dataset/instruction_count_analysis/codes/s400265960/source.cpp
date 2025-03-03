#include<cstdio>

#include<cstring>

#include<cctype>

#include<cmath>

#include<algorithm>

#define reg register

#define max(a,b) (a>b?a:b)

#define min(a,b) (a<b?a:b)

typedef long long ll;

template<typename T>inline T read(){

    reg T x=0,f=1;reg char ch=getchar();

    for(;!isdigit(ch);f=ch=='-'?-1:1,ch=getchar());

    for(;isdigit(ch);x=(x*10)+(ch^48),ch=getchar());

    return x*f;

}

char buf[15];

inline void write(int v){

	if(!v){puts("0");return;}

	reg int cnt=0;

	while(v)buf[++cnt]=v%10+'0',v/=10;

	for(reg int i=cnt;i;i--)putchar(buf[i]);

	putchar('\n');

}

const int maxn=2005;

const int inf=0x7fffffff;

int f[maxn][maxn],col[maxn<<1],a[maxn<<1],p[2][maxn],c[2][maxn<<1][maxn];

char ch[10];

int main(){

	reg int n=read<int>();

	for(reg int i=1;i<=n*2;i++){

		scanf("%s",ch);a[i]=read<int>();col[i]=ch[0]=='B'?1:0;

		p[col[i]][a[i]]=i;

	}

	for(reg int i=1;i<=n*2;i++)

		for(reg int j=0;j<=n;j++)

			c[0][i][j]=c[0][i-1][j]+(a[i-1]>j&&!col[i-1]),

			c[1][i][j]=c[1][i-1][j]+(a[i-1]>j&&col[i-1]);

	for(reg int i=0;i<=n;i++)

		for(reg int j=0;j<=n;j++){

			if(!(i|j))continue;

			f[i][j]=inf;

			if(i)f[i][j]=min(f[i][j],f[i-1][j]+c[0][p[0][i]][i-1]+c[1][p[0][i]][j]);

			if(j)f[i][j]=min(f[i][j],f[i][j-1]+c[1][p[1][j]][j-1]+c[0][p[1][j]][i]);

		}

	write(f[n][n]);

    return 0;

}