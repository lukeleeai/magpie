#include <cstdio>

using namespace std;



int main()

{

	char ch;

	bool c=false;

	while((ch=getchar())!='\n')

		if(ch=='C')

			c=true;

		else if(ch=='F' && c)

			return printf("Yes")&0;

	printf("No");

	return 0;

}