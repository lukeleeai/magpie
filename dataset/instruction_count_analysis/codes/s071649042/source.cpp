#include<algorithm>

#include<stdio.h>

#include<cmath>

using namespace std;

int main(){

	int x,y,z;

	scanf("%d%d%d",&x,&y,&z);

	int ans=floor((x-z)/(y+z));

	printf("%d\n",ans); 

	return 0;

}
