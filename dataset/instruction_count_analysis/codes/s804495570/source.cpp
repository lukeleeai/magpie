// luogu-judger-enable-o2

// SeptEtavioxy

#include<cstdio>

#include<cctype>

#include<cstring>

#include<algorithm>

#include<cmath>

#define re register

#define ll long long

#define il inline

#define rep(i,s,t) for(re int i=(s);i<=(t);i++)

#define rev_rep(i,s,t) for(re int i=(s);i>=(t);i--)

#define each(i,u) for(int i=head[u];i;i=bow[i].nxt)

#define pt(ch) putchar(ch)

#define pti(x) printf("%d",x)

#define ptll(x) printf("%lld",x)

#define file(s) freopen(s".in","r",stdin),freopen(s".out","w",stdout)

using namespace std;

// c_ints

il int ci(){

	re char ch;int f=1;

	while(!isdigit(ch=getchar()))f= ch=='-'?-1:1 ;

	re int x= ch^'0';

	while(isdigit(ch=getchar()))x=(x*10)+(ch^'0');

	return f*x;

}

enum{N=100024};

int fa[N],dis[N];

void fd(int x){

	if( fa[x]==x ) return ;

	fd(fa[x]);

	dis[x]+= dis[fa[x]];

	fa[x]= fa[fa[x]];

}

int main(){

	int n=ci(), m=ci();

	rep(i,1,n) fa[i]= i;

	while( m-- ){

		int l=ci(), r=ci(), d=ci();

		fd(l), fd(r);

		if( fa[l]==fa[r] ){

			if( dis[r]-dis[l]!=d ){

				puts("No");

				return 0;

			}

		}

		else{

			int fl=fa[l], fr=fa[r];

			int x= dis[l]+d-dis[r];

//			printf("%d %d\n",fl,fr);

//			if( x<0 ){

//				puts("No");

//				return 0;

//			}

			dis[fr]= x;

			fa[fr]= fl;

		}

//		printf("fa :");rep(i,1,n) printf("%d ",fa[i]); pt('\n');

//		printf("dis:");rep(i,1,n) printf("%d ",dis[i]); pt('\n');

	}

	puts("Yes");

	return 0;

}