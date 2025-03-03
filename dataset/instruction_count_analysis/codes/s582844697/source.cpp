#include<cstdio>

#include<algorithm>

int n,a[200001];

long long sum=0;

int Abs(int a){return a>0?a:-a;}

using namespace std;

int main(){

	scanf("%d",&n);

	for(int i=0;i<n;i++){

		scanf("%d",&a[i]);a[i]-=i;

	}

	sort(a,a+n);

	for(int i=0;i<n;i++){

		sum+=1ll*Abs(a[i]-a[n/2]);

	}

	printf("%lld",sum);

}