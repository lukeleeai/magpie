#include<stdio.h>//T2

#define For(i,a,b) for(register long long i=a;i<=b;i++)

#define Rof(i,a,b) for(register long long i=a;i>=b;i--)

#define int long long

using namespace std;

const int maxn=1e5+10;

int fa[maxn<<1];

inline int findfa(int i){

	return i==fa[i]?i:fa[i]=findfa(fa[i]);

}

inline void uni(int i,int j){

	int a=findfa(i),b=findfa(j);

	if(a!=b) fa[a]=b;

}

inline bool wxp(int i,int j){

	return findfa(i)==findfa(j);

}

int n,m;

signed main(){

	scanf("%lld%lld",&n,&m);

	Rof(i,n<<1,1){

		fa[i]=i;

	}

	For(i,1,m){

		int u,v;

		scanf("%lld%lld",&u,&v);

		uni(u,v+n);

		uni(u+n,v);

	}

	For(i,1,n){

		if(wxp(i,i+n)){

			printf("%lld\n",n*(n-1)/2-m);

			return 0;

		}

	}

	int ls=1,rs=0;

	For(i,2,n){

		if(wxp(i,1)){

			++ls;

		}else{

			++rs;

		}

	}

	printf("%lld\n",ls*rs-m);

}