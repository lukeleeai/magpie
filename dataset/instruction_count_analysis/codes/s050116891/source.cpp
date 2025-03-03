#include<cmath>

#include<cstdio>

#include<cstring>

#include<algorithm>

#define gt getchar()

#define ll long long

#define File(s) freopen(s".in","r",stdin),freopen(s".out","w",stdout)

typedef std::pair<int,int> P;

#define mk std::make_pair

#define fr first

#define sc second

inline int in()

{

	int k=0;char ch=gt;bool p=1;

	while(ch<'-')ch=gt;if(ch=='-')ch=gt,p=0;

	while(ch>'-')k=k*10+ch-'0',ch=gt;

	return p?k:-k;

}

const int N=3005,YL=1e9+7;

inline int MO(const int &x){return x>=YL?x-YL:x;}

inline void add(int &x,int y){if((x+=y)>=YL)x-=YL;}

int f[2][N][2],now;

int main()

{

	int n=in(),m=in();f[now][0][1]=1;

	for(int i=1;i<=n;++i)f[now][i][0]=1;

	for(int i=1;i<=m;++i)

	{

		now^=1;memset(f[now],0,sizeof f[now]);

		for(int j=1;j<=n;++j)add(f[now][j][0],f[now^1][j-1][0]);//WW

		for(int j=1;j<=n;++j)add(f[now][j][1],f[now^1][j-1][1]);

		for(int j=1;j< n;++j)add(f[now][j][0],f[now^1][j+1][0]);//BB

		for(int j=1;j< n;++j)add(f[now][j][1],f[now^1][j+1][1]);

		add(f[now][0][1],f[now^1][1][1]),add(f[now][0][1],f[now^1][1][0]);

		for(int j=0;j< n;++j)add(f[now][j][0],f[now^1][j][0]);//WB

		for(int j=0;j< n;++j)add(f[now][j][1],f[now^1][j][1]);

		for(int j=2;j<=n;++j)add(f[now][j][0],f[now^1][j][0]);//BW

		for(int j=2;j<=n;++j)add(f[now][j][1],f[now^1][j][1]);

		add(f[now][1][1],f[now^1][1][1]),add(f[now][1][1],f[now^1][1][0]);

	}

	int ans=0;

	for(int i=0;i<=n;++i)add(ans,f[now][i][1]);

	printf("%d\n",ans);

	return 0;

}
