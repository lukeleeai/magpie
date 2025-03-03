#include<cstdio>

int flag=0;char ch;

int main()

{

ch=getchar();

do

	{

	if(ch=='C')flag=1;

	if(flag&&ch=='F'){puts("Yes");return 0;}

	ch=getchar();

	}while(ch!=-1);

puts("No");

return 0;

}