#include<cstdio>

#include<algorithm>

using namespace std;



int main()

{

	int A,B,C,D;

	scanf("%d %d %d %d",&A,&B,&C,&D);

	int area1,area2;

	area1=A*B;

	area2=C*D;

	printf("%d\n",area1>=area2?area1:area2);

return 0;

}