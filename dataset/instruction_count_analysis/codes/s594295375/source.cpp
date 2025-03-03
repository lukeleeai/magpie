#include <stdio.h>

#define N 2005

#define reg register

#define F(i,n) for(i=1;i<=n;++i)

#define R(i,n) for(i=n;i;--i)

int n,m,l[N][N],r[N][N],u[N][N];

char s[N][N],v[N][N];

inline void smin(int &a,int b){if(b<a)a=b;}

inline void smax(int &a,int b){if(b>a)a=b;}

int main() {

	reg int i,j,ans;

	scanf("%d%d",&n,&m);

	F(i,n) {

		scanf("%s",s[i]+1);

		F(j,m) s[i][j]=s[i][j]=='#'?1:0;

	}

	--n;--m;

	F(i,n) {

		F(j,m) {

			v[i][j]=s[i][j]^s[i+1][j]^s[i][j+1]^s[i+1][j+1];

		}

	}

	F(i,n) {

		F(j,m) {

			if(!v[i][j]) {

				u[i][j]=u[i-1][j]+1;

				l[i][j]=l[i][j-1]+1;

			}

		}

		R(j,m) {

			if(!v[i][j]) r[i][j]=r[i][j+1]+1;

		}

	}

	ans=(n>m?n:m)+1;

	F(i,n) {

		F(j,m) {

			if(u[i][j]>1) {

				smin(l[i][j],l[i-1][j]);

				smin(r[i][j],r[i-1][j]);

			}

			smax(ans,(l[i][j]+r[i][j])*(u[i][j]+1));

		}

	}

	printf("%d\n",ans);

	return 0;

}