#pragma GCC optimize(2)

#include <cstdio>

#include <cstring>

using namespace std;



char a[110000];



int main()

{

	scanf("%s",a);

	int l=strlen(a);

	for(int i=0;i<l;i+=2) printf("%c",a[i]);

	printf("\n");

	return 0;

}