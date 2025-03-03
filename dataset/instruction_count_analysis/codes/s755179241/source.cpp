# include "cstdio"

# include "iostream"



using namespace std;



long long d,n; 



int main(){

	long long ans=1; 

	scanf("%lld%lld",&d,&n);

	if(n==100){

		n++; 

	} 

	for(int i=1;i<=d;i++){

		ans*=100; 

	} 

	printf("%lld",ans*n); 

	return 0; 

} 