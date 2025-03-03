#include<cstdio>

#include<vector>

using namespace std;

#define LL long long



int n,m;

vector<int>a[100001];

char b[100001][2];

LL ans,sum[3];



inline char readc(void){

	static char fl[10000],*A=fl,*B=fl;

	return A==B&&(B=(A=fl)+fread(fl,1,10000,stdin),A==B)?EOF:*A++;

}

inline int read(void){

	int a=0;static char c;

	while((c=readc())<'0'||c>'9');

	while(c>='0'&&c<='9')a=a*10+c-'0',c=readc();

	return a;

}

void Dfs(int x,int d){

	b[x][d]=1;

	for(int i=0;i<a[x].size();++i)

		if(b[a[x][i]][d^1]==0)

			Dfs(a[x][i],d^1);

	return;

}

int main(void){

	n=read(),m=read();

	register int i,x,y;

	for(i=1;i<=m;++i)

		x=read(),y=read(),a[x].push_back(y),a[y].push_back(x);

	Dfs(1,0);

	for(i=2;i<=n;++i){

		if(b[i][0]&&!b[i][1])

			++sum[0];

		if(b[i][1]&&!b[i][0])

			++sum[1];

		if(b[i][1]&&b[i][0])

			++sum[2];

	}

	ans=sum[1]+sum[2];

	ans+=sum[2]*(sum[2]-1)>>1;

	ans+=sum[2]*sum[1];

	ans+=sum[2]*sum[0];

	ans+=sum[0]*sum[1];

	printf("%lld\n",ans-m);

	return 0;

}