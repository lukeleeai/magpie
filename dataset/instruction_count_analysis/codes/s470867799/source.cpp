#include<stdio.h>

int n,a[200000],flg=0,ans,j=1;

int main(){

	scanf("%d",&n);

	for(int i=1;i<=n;++i){

		scanf("%d",&a[i]);

		}

	for(int i=1;i<=n;++i){

		j=a[j];

		ans++;

		if(j==2) {

			flg=1;

			break;

		}

	}

	if(flg==1)

	printf("%d",ans);

	else printf("-1");

	return 0;

}