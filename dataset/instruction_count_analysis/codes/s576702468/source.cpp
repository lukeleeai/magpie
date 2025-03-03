// luogu-judger-enable-o2

#include <cstdio>

int n,t,a;

int main(){

//	freopen("a.in","r",stdin);

	scanf("%d%d",&n,&t);

	scanf("%d",&a);

	int min1=a,ans=0,maxc=0;

	for(int i=2;i<=n;++i){

		scanf("%d",&a);

		if(a-min1==maxc) ans++;

		if(a-min1>maxc) maxc=a-min1,ans=1;

		if(min1>a) min1=a;

	}

	printf("%d",ans);

	return 0;

}