#include<stdio.h>

long long a[100005];

long long ans;

main(){

	int n,k;scanf("%d%d",&n,&k);

	for(register int i=1;i<=n;i++)

		scanf("%lld",&a[i]);

	for(register int i=1;i<n;i++){

		if(a[i]+a[i+1]>k){

			ans+=a[i]+a[i+1]-k;

			if(a[i]<=k)

				a[i+1]-=a[i]-k+a[i+1];

			else{

				a[i+1]=0;

				a[i]=k;

			}

		}

	}

	printf("%lld\n",ans);

	return 0;

}