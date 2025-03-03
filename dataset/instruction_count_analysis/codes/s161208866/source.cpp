#include<cstdio>

#include<algorithm>

using namespace std;



int a[100001];

int main(){

	int n;

	scanf("%d",&n);

	for(int i=1;i<=n;i++)

		scanf("%d",&a[i]);

	int ql=1;

	for(int i=1;i<=n;i++)

		if(a[i])ql=0;

	if(ql){

		printf("Yes\n");

		return 0;

	}

	if(n%3){

		printf("No\n");

		return 0;

	}

	sort(a+1,a+n+1);

	for(int i=2;i<=n;i++)

		if(i!=n/3+1&&i!=n/3*2+1&&a[i]!=a[i-1]){

			printf("No\n");

			return 0;

		}

	if(a[1]^a[n/3+1]^a[n/3*2+1]){

		printf("No\n");

		return 0;

	}

	printf("Yes\n");

}