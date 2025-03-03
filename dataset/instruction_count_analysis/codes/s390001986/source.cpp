#include<stdio.h>

int mx(int x,int y){return x>y?x:y;}

main()

{

	int x,y,z;scanf("%d%d%d",&x,&y,&z);

	printf("%d\n",(z+mx(x,y)-1)/mx(x,y));

	return 0;

}