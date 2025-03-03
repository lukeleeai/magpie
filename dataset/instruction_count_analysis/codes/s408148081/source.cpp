#include<stdio.h>

#include<string.h>

#include<algorithm>

using namespace std;

char a[5];

int main()

{

	scanf("%s",a);

	int l=strlen(a);

	sort(a,a+4);

	if(a[0]==a[1]&&a[2]==a[3]&&a[0]!=a[2])printf("Yes\n");

	else printf("No\n");

}