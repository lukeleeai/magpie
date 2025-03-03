#include "cstdio"

int a[10005],b[10005],i,n;long long s1,s2;

int main(){

	scanf("%d",&n);

	for(i=1;i<=n;i++)

	scanf("%d",&a[i]);

	for(i=1;i<=n;i++)

	scanf("%d",&b[i]);

	for(i=1;i<=n;i++){

		if(a[i]>b[i])s1+=a[i]-b[i];

		if(a[i]<b[i])s2+=(b[i]-a[i])>>1;

	}

	if(s1<=s2)printf("Yes\n");

	else printf("No\n");

}