#include <cstdio>

int a;

char s[20];

int main ()

{

	scanf ("%s",s);

	for (a=0;s[a];a=s[a]=='A'&&s[a+1]=='C'?10:a+1) ;

	printf ("%s\n",a==10?"Yes":"No");

	return 0;

}
