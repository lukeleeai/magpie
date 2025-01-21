#include<cstdio>

#include<algorithm>

using namespace std;

int N,K;

long long ans=0;

int main() {

	#ifdef LOACL

	freopen("in.txt","r",stdin);

	freopen("out.txt","w",stdout);

	#endif

	scanf("%d %d",&N,&K);

	if(K==0)ans=1ll*N*N;

	else {

		for(int b=K+1;b<=N;b++) {

			int x1=b-K;

			int x2=N/b;

			int k=N-x2*b;

			if(k>=K)ans+=k-K+1;

			ans+=x1*x2;

		}

	}

	printf("%lld\n",ans);

	return 0;

}
