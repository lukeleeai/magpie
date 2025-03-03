#include <cstdio>

#include <cmath>

using  namespace std;



int A=10,B=11,C=12,D=13,E=14,F=15;



int main()

{

	char X,Y;

	scanf("%c %c",&X,&Y);

	if(X > Y) printf(">\n");

	if(X < Y) printf("<\n");

	if(X == Y) printf("=\n");

	return 0;

}