#include"stdc++.h"

using namespace std;

const int N=105;

int n,a[N],ans;

int main()

{

	scanf("%d",&n);

	for(int i=1;i<=n;i++)

		scanf("%d",&a[i]);

	sort(a+1,a+n+1);

	for(int i=1;i<=n;i++)

		for(int j=i+1;j<=n;j++)

			for(int k=j+1;k<=n;k++)

				if(a[i]+a[j]>a[k]&&a[i]!=a[j]&&a[j]!=a[k])

					ans++;

	printf("%d\n",ans);

	return 0;

}