#include <stdio.h>

int a[5];

int main(){

	int n,m,i,s,c;

	scanf("%d%d",&n,&m);

	for(i=1;i<=n;i++)a[i]=-1;

	for(i=1;i<=m;i++){

		scanf("%d%d",&s,&c);

		if(a[s]!=-1&&a[s]!=c){//同一位上有不同数值

			printf("-1\n");

			return 0;

		}else{

			a[s]=c;

		}

	}

	if(n>1&&a[1]==0)printf("-1\n");//至少两位数，首位是0

	else if(n==1){//只有一位数

		if(a[1]==-1)printf("0\n");

		else printf("%d\n",a[1]); 

	}

	else{//多位数

		for(i=1;i<=n;i++)

			if(i==1&&a[i]==-1)printf("1");//若对首位没有说明，那么设置为1

			else if(a[i]==-1)printf("0");

			else printf("%d",a[i]);

		printf("\n");

	}

	return 0;

}