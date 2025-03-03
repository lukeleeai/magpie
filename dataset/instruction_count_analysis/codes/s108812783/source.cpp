#include<cstdio>

#include<algorithm>

using namespace std;



int a[100005],b[100005],c[100005];



int main(){

	int ans=0;

	int n;

	scanf("%d",&n);

	for(register int i=1;i<=n;i++){

		scanf("%d",&a[i]);

	}

	int m=0;

	sort(a+1,a+n+1);

	for(register int i=1;i<=n;i++){

		if(a[i]!=c[m]){

			c[++m]=a[i];

			b[m]=1;

		}

		else{

			b[m]++;

		}

	}

	for(register int i=1;i<=m;i++){

		if(b[i]>=c[i]){

			ans+=b[i]-c[i];

		}

		else ans+=b[i];

	}

	printf("%d",ans);

	return 0;

}