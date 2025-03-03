#include<cstdio>

using namespace std;

int main()

{

	int n,m,k;

	scanf("%d%d",&n,&m);

	k=m/n;

	for(int i=k;i>=1;i--)

	if(m%i==0)

	{

		printf("%d",i);

		return 0;

	}

}