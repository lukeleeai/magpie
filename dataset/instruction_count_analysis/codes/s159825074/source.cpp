#include<cstdio>



int n,k,ans;



int main() {

	scanf("%d %d",&n,&k);

	ans=k;

	for(int i=2;i<=n;i++)

		ans*=(k-1);

	printf("%d\n",ans);

	return 0;

}