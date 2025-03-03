//l

#include<stdio.h>



int n, a[200005], b[200005]={0}, c[200005], idx=0;



int main()

{

	scanf("%d", &n);

	for(int i=1; i<=n; i++)

	{

		scanf("%d", a+i);

	}

	for(int i=n; i>0; i--)

	{

		int tmp=0;

		for(int j=2; j*i<=n; j++) tmp+=b[i*j], tmp&=1;

		b[i]=tmp^a[i];

		if(b[i]) c[idx++]=i;

	}

	printf("%d\n", idx);

	if(idx)

	{

		printf("%d", c[0]);

		for(int i=1; i<idx; i++) printf(" %d", c[i]);

		puts("");

	}

	return 0;

}