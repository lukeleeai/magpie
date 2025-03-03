# include "cstdio" 



using namespace std;



int

	d,

	n;

	

long long

	mul=1ll; 



int main(){

	scanf("%d%d",&d,&n);	 

	register int i;

	for(i=1;i<=d;i++){

		mul*=100; 

	}

	printf("%lld",(n+(n==100))*mul);

	return 0; 

} 