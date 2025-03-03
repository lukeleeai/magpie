#include<cstdio>

int n,ans;long long t,f[233];char a[1200][2];

int main(){

	scanf("%d",&n);

	if(n&1){

			for(int i=1;i<=n;i++)

	for(int j=i+1;j<=n;j++)

	if(i+j!=n) ans++;printf("%d\n",ans);

	for(int i=1;i<=n;i++)

	for(int j=i+1;j<=n;j++)

	if(i+j!=n) 

	printf("%d %d\n",i,j); 

	}

	else {

		for(int i=1;i<=n;i++)

	for(int j=i+1;j<=n;j++)

	if(i+j!=n+1) ans++;printf("%d\n",ans);

	for(int i=1;i<=n;i++)

	for(int j=i+1;j<=n;j++)

	if(i+j!=n+1) printf("%d %d\n",i,j); 

	}



}
