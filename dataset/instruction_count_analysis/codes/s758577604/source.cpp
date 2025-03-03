#include<bitset>

#include<cstdio>

#include<algorithm>

#define rep(i,l,r) for (int i=(l); i<=(r); i++)

using namespace std;



const int N=510,mod=998244353;

int n,m,y,rk,ans,a[N][N],pw[N];

bitset<N> b[N];



int main(){

	scanf("%d%d",&n,&m); pw[0]=1;

	rep(i,1,n){

		bitset<N>x(0);

		rep(j,1,m) scanf("%d",&y),x[j-1]=y;

		for(int j=m-1; ~j; j--)

			if (x[j]){

				if (b[j].any()) x^=b[j];

				 else{ b[j]=x; break; }

			}

	}

	rep(i,1,max(n,m)) pw[i]=2*pw[i-1]%mod;

	rep(i,0,m-1) if (b[i].any()) rk++;

	ans=1ll*(pw[n]-pw[n-rk])*pw[m-1]%mod;

	printf("%d\n",(ans+mod)%mod);

	return 0;

}