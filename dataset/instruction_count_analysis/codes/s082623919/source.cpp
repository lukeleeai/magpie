#include<cstdio>

#include<cstring>

#include<cmath>

#include<algorithm>

using namespace std;

const int maxn=1e5+100;

int a[maxn];

int main(){

	int n;

	while(~scanf("%d",&n)){

		for(int i=1;i<=n;i++)

			scanf("%d",a+i);

		sort(a+1,a+n+1);

		long long ans=0;

		if(n<=3){

			if(n==2)

				ans=a[2]-a[1];

			else

				ans=max(a[2]+a[3]-2*a[1],2*a[3]-a[1]-a[2]);

			goto loop;

		}

		if(n&1){

			for(int i=1;i<=n;i++){

				if(i==n/2+1)continue;

				else if(i<n/2+1){

					if(i==n/2)

						ans-=a[i];

					else

						ans-=a[i]*2;

				}

				else if(i>n/2+1){

					if(i==n/2+2)

						ans+=a[i];

					else

						ans+=a[i]*2;

				}

			}

			ans+=max(a[n/2+1]-a[n/2],a[n/2+2]-a[n/2+1]);

		}

		else{

			for(int i=1;i<=n;i++){

				if(i<n/2)

					ans-=a[i]*2;

				else if(i>n/2+1)

					ans+=a[i]*2;			

			}

			ans+=a[n/2+1]-a[n/2];

		}

loop:	printf("%lld\n",ans);

	}

}