#include <cstdio>

#include <algorithm>

using namespace std;



typedef long long ll;



const int MAXN = 1000;

const int MOD = int(1E9) + 7;



inline int add(int x, int y) {return (x + y >= MOD ? x + y - MOD : x + y);}

inline int sub(int x, int y) {return (x - y < 0 ? x - y + MOD : x - y);}

inline int mul(int x, int y) {return 1LL * x * y % MOD;}



int pow_mod(int b, ll p) {

	int ret = 1;

	for(ll i=p;i;i>>=1,b=mul(b,b))

		if( i & 1 ) ret = mul(ret, b);

	return ret;

}



struct matrix{

	int a[2][2];

	friend matrix operator * (matrix A, matrix B) {

		matrix C;

		C.a[0][0] = add(mul(A.a[0][0], B.a[0][0]), mul(A.a[0][1], B.a[1][0]));

		C.a[0][1] = add(mul(A.a[0][0], B.a[0][1]), mul(A.a[0][1], B.a[1][1]));

		C.a[1][0] = add(mul(A.a[1][0], B.a[0][0]), mul(A.a[1][1], B.a[1][0]));

		C.a[1][1] = add(mul(A.a[1][0], B.a[0][1]), mul(A.a[1][1], B.a[1][1]));

		return C;

	}

};



matrix mpow(matrix A, ll p) {

	matrix ret; ret.a[0][0] = ret.a[1][1] = 1, ret.a[0][1] = ret.a[1][0] = 0;

	for(ll i=p;i;i>>=1,A=A*A)

		if( i & 1 ) ret = ret*A;

	return ret;

}



int a, b[MAXN + 5], c[MAXN + 5], d[MAXN + 5];



char s[MAXN + 5][MAXN + 5], t[MAXN + 5][MAXN + 5];

int main() {

	int H, W; ll K; scanf("%d%d%lld", &H, &W, &K);

	for(int i=0;i<H;i++)

		scanf("%s", s[i]);

	if( K == 0 ) {

		puts("1");

		return 0;

	}

	bool f1 = false, f2 = false;

	for(int i=0;i<H;i++)

		if( s[i][0] == '#' && s[i][W-1] == '#' ) {

			f1 = true;

			break;

		}

	for(int i=0;i<W;i++)

		if( s[0][i] == '#' && s[H-1][i] == '#' ) {

			f2 = true;

			break;

		}

	if( f1 && f2 )

		puts("1");

	else if( (!f1) && (!f2) ) {

		int cnt = 0;

		for(int i=0;i<H;i++)

			for(int j=0;j<W;j++)

				cnt += (s[i][j] == '#');

		printf("%d\n", pow_mod(cnt, K - 1));

	}

	else {

		if( f2 ) {

			for(int i=0;i<H;i++)

				for(int j=0;j<W;j++)

					t[j][i] = s[i][j];

			swap(H, W);

			for(int i=0;i<H;i++)

				for(int j=0;j<W;j++)

					s[i][j] = t[i][j];

		}

		for(int i=0;i<H;i++) {

			bool flag = true;

			for(int j=0;j<W;j++)

				if( s[i][j] == '.' ) {

					flag = false;

					break;

				}

			if( flag ) a++;

			else {

				int l, r;

				for(int j=0;j<W;j++)

					if( s[i][j] == '.' ) {

						l = j;

						break;

					}

				for(int j=W-1;j>=0;j--)

					if( s[i][j] == '.' ) {

						r = j;

						break;

					}

				int lst = l;

				for(int j=l;j<=r;j++) {

					if( s[i][j] == '.' ) {

						if( lst != j ) b[j-lst]++;

						lst = j + 1;

					}

				}

				c[i] = l, d[i] = W - r - 1;

			}

		}

		matrix A;

		A.a[0][0] = mul(a, W), A.a[1][1] = a, A.a[0][1] = A.a[1][0] = 0;

		for(int j=1;j<=W;j++)

			A.a[0][0] = add(A.a[0][0], mul(b[j], j)), A.a[0][1] = add(A.a[0][1], b[j]);

		for(int j=0;j<H;j++) {

			if( c[j] ) A.a[1][0] = add(A.a[1][0], c[j]), A.a[1][1] = add(A.a[1][1], 1);

			if( d[j] ) A.a[1][0] = add(A.a[1][0], d[j]), A.a[1][1] = add(A.a[1][1], 1);

			if( c[j] + d[j] ) {

				A.a[0][0] = add(A.a[0][0], c[j] + d[j]), A.a[0][1] = add(A.a[0][1], 1);

				A.a[1][0] = sub(A.a[1][0], c[j] + d[j]), A.a[1][1] = sub(A.a[1][1], 1);

			}

		}

		A = mpow(A, K - 1);

		printf("%d\n", add(A.a[0][1], A.a[1][1]));

/*

		int x = 0, y = 1;

		for(int i=2;i<=K;i++) {

			int x1 = mul(a, mul(x, W)), y1 = mul(a, y);

			for(int j=1;j<=W;j++)

				x1 = add(x1, mul(b[j], add(mul(x, j), y))); // x1 += b[j]*(x*j + y)

			for(int j=0;j<H;j++) {

				if( c[j] ) y1 = add(y1, add(mul(x, c[j]), y)); // y1 += c[j]*x + y

				if( d[j] ) y1 = add(y1, add(mul(x, d[j]), y)); // y1 += d[j]*x + y

				if( c[j] + d[j] ) {

					x1 = add(x1, add(mul(x, c[j] + d[j]), y)); // x1 += (c[j]+d[j])*x + y

					y1 = sub(y1, add(mul(x, c[j] + d[j]), y)); // y1 -= (c[j]+d[j])*x + y

				}

			}

			x = x1, y = y1;

		}

		printf("%d\n", add(x, y));

*/

	}

}