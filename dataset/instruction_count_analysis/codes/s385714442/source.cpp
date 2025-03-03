#include <cstdio>

#include <cstring>

#include <algorithm>

#define N 110000

using namespace std;

int n,c,k,t[N],l;

int main(){

//	freopen("a.in","r",stdin);

	scanf("%d%d%d",&n,&c,&k);

	for(int i=1;i<=n;++i) scanf("%d",&t[i]);

	sort(t+1,t+n+1);

	int ans=0;

	l=1;

	t[n+1]=0x7FFFFFFF;

	for(int i=2;i<=n+1;++i){

		int sum=0;

		while(l<i and t[l]+k<t[i]) l+=min(i-l,c),sum++;

		ans+=sum;

	}

	printf("%d\n",ans);

	return 0;

}