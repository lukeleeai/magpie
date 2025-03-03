#include<stdio.h>

#include<algorithm>

using namespace std;

int a[2000005];

int b[2000005];

int main()

{

	long long n;

	scanf("%lld",&n);

	for(int i=0;i<n;i++){

		scanf("%d",&a[i]);

		b[i]=a[i];

		}

		

		sort(a,a+n);

		

		for(int i=0;i<n;i++){

			if(b[i]!=a[n-1]){

				printf("%d\n",a[n-1]);

			}

			else{

				printf("%d\n",a[n-2]);

			}

		}

		

		return 0;

	

}