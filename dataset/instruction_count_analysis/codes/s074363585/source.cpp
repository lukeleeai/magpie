#include <cstdio>

#include <algorithm> 

using namespace std;

int n,ans=24,a[24];

int main(){

	scanf("%d",&n);

	if (n>=24){puts("0");return 0;}

	for (int i=1;i<=n;i++) scanf("%d",&a[i]);++n;

	sort(a+1,a+1+n);

	for (int i=1;i<=n;i++){

		if (i&1) a[i]=24-a[i];

		if (a[i]==24) a[i]=0; 

	}

	sort(a+1,a+1+n);

	for (int i=2;i<=n;i++) ans=min(ans,a[i]-a[i-1]);

	printf("%d\n",ans);

	return 0;

}