#include<cstdio>

int main()

{

	int flag=0;

	char c;

	while(~(c=getchar()))

	{

		if(c=='C') flag=1;

		if(flag==1 && c=='F') 

			return printf("Yes")&0;

	}

	return printf("No")&0;

}