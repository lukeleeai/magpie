#include<cstdio>

using namespace std;

int ans,a,b;

char op,stp1,stp2;

int main(){

	scanf("%d",&a);

	scanf("%c",&stp1);

	scanf("%c",&op);

	scanf("%c",&stp2);

	scanf("%d",&b);

	if (op=='+'){

		ans=a+b;

	}else if (op=='-'){

		ans=a-b;

	}

	printf("%d",ans);

return 0;} 