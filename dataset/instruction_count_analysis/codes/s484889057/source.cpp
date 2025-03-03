#include <iostream>

#include "stdc++.h"

#define p 1000000007

using namespace std;

int N,k;





const int A = 2e5 + 11;

const int B = 1e6 + 11;

const int inf = 0x3f3f3f3f;



inline int read() {

	char c = getchar(); int x = 0, f = 1;

	for( ; !isdigit(c); c = getchar()) if(c == '-') f = -1;

	for( ; isdigit(c); c = getchar()) x = x * 10 + (c ^ 48);

	return x * f;

}



int T, fac[A];



inline int power(long long a, long long  b) {

	long long res = 1;

	while (b) {

		if (b & 1) res = res * a % p;

		a = a * a % p, b >>= 1;

	}

	return res;

}



inline int C(int n, int m) {

	if (m > n) return 0;



	return (1LL*fac[n] * power(fac[m], p - 2) % p) *  power(fac[n - m], p - 2) % p;

}



inline int Lucas(int n, int m) {

	if (!m) return 1;

	//cout <<"CL:"<<C(n%p,m%p) << " "<<Lucas(n / p, m / p)<<endl;

	return C(n % p, m % p) * Lucas(n / p, m / p) % p;

}



inline void init() {

	int maxn = N*2;

	fac[0] = 1;

	for (int i = 1; i <= maxn; i++) fac[i] = (1LL*fac[i - 1] * i) % p;

}





int main()

{

    scanf("%d%d",&N,&k);

    long long b = k,r = N-k;

    init();



    for(int i=1;i<=k;++i)

    {

        long long i1 = 1,i2 = 1;

        if(r-i+1<0) {

            printf("0\n");continue;

        }

        i1 = Lucas(k-1,k-i);

        //cout << k << " "<<i<<" "<<i1 << endl;

        i2 = Lucas(r+1,r-i+1);

        //cout <<r+1<<" "<<r-i+1<<" "<<i2<<endl;

        printf("%lld\n",(1LL*i1*i2)%p);

    }

    return 0;

}
