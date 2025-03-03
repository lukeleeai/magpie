#include <cstdio> 

#include <cmath> 

#include <cstdlib> 

#define For(i,j,k) for(int i=j;i<=k;i++)

#define Dow(i,j,k) for(int i=j;i>=k;i--)

#define LL long long

using namespace std ;

inline int read() {

	int x = 0 , f = 1 ;

	char ch = getchar() ;

	while(ch<'0'||ch>'9') { if(ch=='-') f = -1 ; ch = getchar() ; }

	while(ch>='0'&&ch<='9') { x = x * 10+ch-48 ; ch = getchar() ; }

	return x * f ;

}



const int inf = 1e9; 

int n,Mn,sum;



int main() {

	n = read();

	Mn = inf;

	For(i, 1, n) {

		int x = read();

		if( x%10!=0 && x<Mn ) Mn = x;

		sum+=x;

	}

	if(sum%10!=0) {

		printf("%d\n",sum);

		return 0;

	}

	if(Mn==inf) puts("0");

	else printf("%d\n",sum-Mn);

	return 0;

}










