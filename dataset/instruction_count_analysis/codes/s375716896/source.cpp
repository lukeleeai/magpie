#include <cstdio>



const int MOD = 998244353;

const int INV2 = (MOD + 1) >> 1;



int add(int x, int y) {return (x + y >= MOD ? x + y - MOD : x + y);}

int sub(int x, int y) {return (x - y < 0 ? x - y + MOD : x - y);}

int mul(int x, int y) {return 1LL*x*y%MOD;}



int pow_mod(int b, int p) {

	int ret = 1;

	for(int i=p;i;i>>=1,b=mul(b,b))

		if( i & 1 ) ret = mul(ret,b);

	return ret;

}



struct node{

	int k, b;

	node() : k(0), b(0) {}

	node(int _k, int _b) : k(_k), b(_b) {}

	int get(int x) {return add(mul(k, x), b);}

	friend node operator + (node a, node b) {

		return node(add(a.k, b.k), add(a.b, b.b));

	}

	friend node operator - (node a, node b) {

		return node(sub(a.k, b.k), sub(a.b, b.b));

	}

	friend node operator * (node a, int k) {

		return node(mul(a.k, k), mul(a.b, k));

	}

	friend node operator / (node a, int k) {

		return a * pow_mod(k, MOD - 2);

	}

};



void fwt(node *A, int m, int type) {

	int n = (1 << m), f = (type == 1 ? 1 : INV2);

	for(int i=1;i<=m;i++) {

		int s = (1 << i), t = (s >> 1);

		for(int j=0;j<n;j+=s)

			for(int k=0;k<t;k++) {

				node x = A[j+k], y = A[j+k+t];

				A[j+k] = (x + y)*f, A[j+k+t] = (x - y)*f;

			}

	}

}



node A[1<<18], B[1<<18], C[1<<18], f[1<<18];



int main() {

	int N, M, S = 0; scanf("%d", &N), M = (1 << N);

	for(int i=0;i<M;i++) scanf("%d", &A[i].b), S = add(S, A[i].b);

	S = pow_mod(S, MOD - 2);

	for(int i=0;i<M;i++) A[i].b = sub(i == 0 ? 1 : 0, mul(A[i].b, S));

	for(int i=0;i<M;i++) B[i].b = 1;

	C[0].b = MOD - 1;

	fwt(A, N, 1), fwt(B, N, 1), fwt(C, N, 1);

	int tmp = mul(B[0].b, pow_mod(C[0].b, MOD-2));

	for(int i=1;i<M;i++)

		f[i] = (B[i] - C[i]*tmp) / A[i].b;

	f[0].k = 1; fwt(f, N, -1);

	int x = sub(0, mul(pow_mod(f[0].k, MOD-2), f[0].b));

	for(int i=0;i<M;i++) printf("%d\n", f[i].get(x));

}