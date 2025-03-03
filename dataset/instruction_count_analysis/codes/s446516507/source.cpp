#include<cstdio>

#include<cstring>

#include<cstdlib>

#include<cstring>

#include<cmath>

#define maxst 1<<20

using namespace std ;

int n , m , p , u , v ;

int r[maxst] ;

double f[maxst] ;



int main() {

	scanf("%d%d%d",&n,&m,&p) ;

	const int maxs = 1 << n;

	for(int i = 0 ; i < m ; i++) {

		scanf("%d%d",&u,&v) ; 

		u-- ; v-- ;

		for(int j = 0 ; j < maxs ; j++) if((j&(1<<u)) && (j&(1<<v)))

		r[j]++ ;

	}

	for(int i = 1 ; i < maxs ; i++) if(i&1){

		f[i] = 1.0 ;

		for(int j = i&(i-1) ; j ; j = i&(j-1)) if(j&1)

			f[i] -= f[j] * pow(p*0.01 , r[i]-r[j]-r[(~j)&i]) ;

	}

	printf("%.9f\n",f[maxs-1]) ;

	return 0 ;

}