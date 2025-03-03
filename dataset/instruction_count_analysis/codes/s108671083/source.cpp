#include<cstdio>

#include<cstring>

#include<algorithm>

#define MN 2005

using namespace std;

inline int in(){

    int x=0;bool f=0; char c;

    for (;(c=getchar())<'0'||c>'9';f=c=='-');

    for (x=c-'0';(c=getchar())>='0'&&c<='9';x=(x<<3)+(x<<1)+c-'0');

    return f?-x:x;

}

bool s[MN][MN];

char ch[MN];

int s1[MN][MN],s2[MN][MN],f[MN][MN],sum[MN][MN];

int n,m,q,xa,ya,xb,yb,res;

int main()

{

	n=in();m=in();q=in();

	for (int i=1;i<=n;++i){

		scanf("%s",ch);

		for (int j=0;j<m;++j) s[i][j+1]=ch[j]-'0';

	}

	for (int i=1;i<=n;++i){

		for (int j=1;j<=m;++j){

			s1[i][j]=s1[i][j-1]+(s[i][j]&&s[i-1][j]);

			s2[i][j]=s2[i-1][j]+(s[i][j]&&s[i][j-1]); 

			f[i][j]=f[i-1][j]+f[i][j-1]-f[i-1][j-1]+(s[i][j]&&s[i-1][j])+(s[i][j]&&s[i][j-1]);

			sum[i][j]=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+(s[i][j]);

		}

	}

	for (int i=1;i<=q;++i){

		xa=in();ya=in();xb=in();yb=in();

		res=sum[xb][yb]-sum[xa-1][yb]-sum[xb][ya-1]+sum[xa-1][ya-1];

		res-=f[xb][yb]-f[xa-1][yb]-f[xb][ya-1]+f[xa-1][ya-1];

		res+=s1[xa][yb]+s2[xb][ya]-s1[xa][ya-1]-s2[xa-1][ya];printf("%d\n",res);

	}

	return 0;

}