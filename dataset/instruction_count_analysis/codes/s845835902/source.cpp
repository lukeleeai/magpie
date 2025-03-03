#include<cstdio>

#include<cstring>

#include<algorithm>

#include<cmath>

#define min(a,b) ((a)<(b)?(a):(b))

#define reg register

#define file(x) freopen(x".in","r",stdin);freopen(x".out","w",stdout);

#define endfile fclose(stdin);fclose(stdout);

namespace IO{

    char buf[1<<15],*S,*T;

    inline char gc(){

        if (S==T){

            T=(S=buf)+fread(buf,1,1<<15,stdin);

            if (S==T)return EOF;

        }

		return *S++;

    }

    inline int read(){

        reg int x;reg bool f;reg char c;

        for(f=0;(c=gc())<'0'||c>'9';f=c=='-');

        for(x=c^'0';(c=gc())>='0'&&c<='9';x=(x<<3)+(x<<1)+(c^'0'));

        return f?-x:x;

    }

}

const int MN=1005;

const int inf=0x3f3f3f3f;

int n,a[MN],f[MN],g[2][MN*5];

int to[MN],nxt[MN],h[MN],cnt;

inline void ins(int s,int t){to[++cnt]=t;nxt[cnt]=h[s];h[s]=cnt;}

bool dfs(int st){

	if(!h[st]){f[st]=0;return true;}

	for(reg int i=h[st];i;i=nxt[i])if(!dfs(to[i]))return false;

	reg int pos=0;memset(g[1],0x3f,sizeof(g[1]));g[1][0]=0;

	for(reg int i=h[st];i;i=nxt[i],pos^=1){

		memset(g[pos],0x3f,sizeof(g[pos]));

		for(reg int j=0;j<=a[st];j++){

			if(j>=f[to[i]])g[pos][j]=min(g[pos][j],g[pos^1][j-f[to[i]]]+a[to[i]]);

			if(j>=a[to[i]])g[pos][j]=min(g[pos][j],g[pos^1][j-a[to[i]]]+f[to[i]]);

		}

	}

	reg int res=inf;

	for(reg int i=0;i<=a[st];i++)res=min(res,g[pos^1][i]);

	if(res==inf)return false;f[st]=res;return true;

}

int main(){

	//file("division");

n=IO::read();

	for(reg int i=2;i<=n;i++)ins(IO::read(),i);

	for(reg int i=1;i<=n;i++)a[i]=IO::read();

	puts(dfs(1)?"POSSIBLE":"IMPOSSIBLE");endfile;

	return 0;

}