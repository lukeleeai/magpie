#include <cstdio>

#include <algorithm>

using namespace std;



const double EPS = 1e-8;

const int N = 105;

const int M = 55;



int n, m, l, t[N], v[N];

double dp[N][M];

double sum[N][M];



void gao(double p, double dp[], double sum[]) {

	double q = 1-p, f[2][M] = {};

	f[0][0] = 1;

	for (int i = 1, x = 1; i <= m; ++i, x^=1) {

		f[x][0] = f[!x][0] * q;

		for (int j = 1; j <= i; ++j) {

			f[x][j] = f[!x][j-1] * p + f[!x][j] * q;

		}

	}

	dp[m+1] = sum[m+1] = 0;

	for (int i = m, x = m & 1; i >= 0; --i) {

		sum[i] = sum[i+1] + (dp[i] = f[x][i]);

	}

}



// return true if (i,j) < (x,y)

bool faster(int i, int j, int x, int y) {

	return l*v[x] + t[i]*j*v[i]*v[x] < l*v[i] + t[x]*y*v[i]*v[x];

}



int binsearch(int i, int j, int k) {

	int l = -1, r = m+1, mid;

	while (l + 1 < r) {

		mid = (l+r)>>1;

		faster(i,j,k,mid) ? r=mid : l=mid;

	}

	return r;

}



void debug(double a[], int s, int t) {

	for(int i=s;i<t;++i)printf("%f ", a[i]);puts("");

}



int main() {

	while (3==scanf("%d%d%d", &n, &m, &l)) {

		for (int p,i = 0; i < n; ++i) {

			scanf("%d%d%d", &p, &t[i], &v[i]);

			gao(p/100., dp[i], sum[i]);

//			debug(dp[i], 0, m+2);

//			debug(sum[i], 0, m+2); 

		}

		for (int i = 0; i < n; ++i) {

			double ans = 0;

			for (int j = 0; j <= m; ++j) {

				double p = dp[i][j];

				for (int r,k = 0; k < n; ++k) {

					if (i == k) continue;

					r = binsearch(i, j, k);

					p *= sum[k][r];

				}

				ans += p;

			}

			printf("%.10f\n", ans);

		}

	}

}