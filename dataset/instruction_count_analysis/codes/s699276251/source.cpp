#include<stdio.h>

#include<string.h>



int main()

{

 char a[255];

 char b[255];

 char c[255];

 scanf("%s %s %s", a, b, c);

 int len = strlen(a);

 int n = strlen(b);

 int s = strlen(c);

 if (a[len - 1] == b[0] && b[n - 1] == c[0]){

  puts("YES");

 }

 else{

  puts("NO");

  }

	

	return 0;

}