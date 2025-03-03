#include <cstdio>

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



const int N = 1e5+11,mod = 1e9+7;

LL ans1,ans2,sum;

int n;

int a[N];



inline LL abs(LL x) {

	if(x<0) x=-x;

	return x;

}

inline LL min(LL x,LL y) {

	if(x<y) return x;

	return y;

}



int main() {

	n=read();

	For(i, 1, n) a[i]=read();

	For(i, 1, n) {

		sum= sum+a[i];

		if(i%2==1) 

			if(sum<=0) {

				ans1=ans1 + abs(1-sum);

				sum=1;

			}

			else {}

		else 

			if(sum>=0) {

				ans1=ans1 + abs(-1-sum);

				sum=-1;

			}

	}

	

	sum = 0;

	For(i, 1, n) {

		sum = sum+a[i]; 

		if(i%2==0) 

			if(sum<=0) {

				ans2=ans2 + abs(1-sum);

				sum=1;

			}

			else {}

		else 

			if(sum>=0) {

				ans2=ans2 + abs(-1-sum);

				sum=-1;

			}

	}

	printf("%lld\n",min(ans1,ans2));

}








