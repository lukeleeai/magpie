#include <cstdio>

int a[40],b;

char S[40];

int main ()

{

	scanf ("%s",S);

	for (b=0;S[b];b++) a[S[b]-'a']++;

	for (b=0;b<26;b++) b=a[b]>1?27:b;

	printf ("%s\n",b==26?"yes":"no");

	return 0;

}
