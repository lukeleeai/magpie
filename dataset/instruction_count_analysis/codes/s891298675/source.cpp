#include <cstdio>



typedef long long ll;



inline ll abs(ll x){ return x>0?x:-x; }



const int N=1e3+5;



char s[45]; int n,m; ll x[N],y[N],c[45];



int main(){

	scanf("%d",&n);

	for(int i=1;i<=n;++i) scanf("%lld%lld",&x[i],&y[i]);

	int op=abs(x[1]+y[1])&1;

	for(int i=2;i<=n;++i){

		if((abs(x[i]+y[i])&1)!=op){ puts("-1"); return 0; }

	}

	if(op){

		printf("%d\n",31);

		for(int i=0;i<=30;++i) printf("%lld ",c[++m]=1<<i);

		printf("\n");

	}

	else{

		printf("%d\n",32);

		printf("%lld ",c[++m]=1);

		for(int i=0;i<=30;++i) printf("%lld ",c[++m]=1<<i);

		printf("\n");

	}

	for(int i=1;i<=n;++i){

		ll nx=0,ny=0;

		for(int j=m;j;--j){

			ll dx=x[i]-nx,dy=y[i]-ny;

			if(abs(dx)>abs(dy)){

				if(dx>0) s[j]='R',nx+=c[j];

				else s[j]='L',nx-=c[j];

			}

			else{

				if(dy>0) s[j]='U',ny+=c[j];

				else s[j]='D',ny-=c[j];

			}

		}

		printf("%s\n",s+1);

	}

	return 0;

}