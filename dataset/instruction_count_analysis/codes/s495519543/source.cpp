#include<stdio.h>

#include<string.h>

#include<algorithm>

using namespace std;

int n,ans;

int a[2005]; 

int main(){

	scanf("%d",&n);

	for(int i=1;i<=n;++i)scanf("%d",a+i);

	sort(a+1,a+n+1);

//	int d=unique(a+1,a+n+1)-a-1; 

	for(int i=1;i<=n;++i)

	for(int j=i+1;j<=n;++j)

	for(int k=j+1;k<=n;++k)

	if(a[i]+a[j]>a[k])ans++;

	else break;

//	if(ans==0) puts("No triangles can be formed."); 

	printf("%d\n",ans); 

	return 0;

} 