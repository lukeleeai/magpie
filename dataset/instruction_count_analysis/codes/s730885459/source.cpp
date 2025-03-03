#include<cmath>

#include<cstdio>

using namespace std;

int main() {

	int Q;

	scanf("%d",&Q);

	for(int i=1; i<=Q; i++) {

		long long a,b;

		scanf("%lld %lld",&a,&b);

		long long pr=a*b;

		long long t=sqrt(pr),ans;

		if(t*(t+1)<pr)

			ans=t*2-1;

		else if(t*t==pr) {

			ans=(t-1)*2;

			if(a!=b) ans--;

		} else

			ans=(t-1)*2;

		printf("%lld\n",ans);

	}

	return 0;

}