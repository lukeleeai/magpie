#include<cstdio>

#include<cstring>

#include<algorithm>

using namespace std;



int a,b;



int main()

{

	scanf("%d %d",&a,&b);

	if(a<=0 && b>=0)

		puts("Zero");

	else if(a>0 && b>0)

		puts("Positive");

	else

		puts((b-a)&1?"Positive":"Negative");

	return 0;

}