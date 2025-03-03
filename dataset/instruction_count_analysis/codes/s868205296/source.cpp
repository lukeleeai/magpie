#include <cstdio>

#include <cstring>

#include <algorithm>

using namespace std; 

const int MAXN=1100;

int f[MAXN][MAXN],p[MAXN];

int main() {

	int N,K;

	scanf("%d%d",&N,&K);

	for(int i=1;i<=N;++i) {

		scanf("%d",&p[i]);

	}

	sort(p+1,p+N+1);

	long long ans=0;

	for(int i=1;i<=K;++i) {

		ans+=p[i];

	}

	printf("%lld\n",ans);

	return 0;

} 