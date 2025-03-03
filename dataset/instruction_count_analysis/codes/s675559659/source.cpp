#include<cstdio>



using namespace std;



int main(){

	long long s;

	scanf("%lld",&s);

	int z=1e9;

	int z2=(s+z-1)/z;

	printf("%d %d %d %d %d %d\n",0,0,z,(int)(1ll*z*z2-s),1,z2);

}
