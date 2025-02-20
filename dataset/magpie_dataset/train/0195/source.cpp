#include<iostream>

#include<algorithm>

#include<cstring>

using namespace std;



#define MAX_M 120

#define MAX_N 60



int x[MAX_N][6];

int y[MAX_N][6];

int z[MAX_M][3];

long long int a[MAX_M][MAX_M][MAX_M];

bool b[MAX_M][MAX_M][MAX_M];



int main() {

	memset(b, false, sizeof(b));

	int n, m;

	int MAXX[3] = { 0,0,0 };

	int SUMX[3] = { 0,0,0 };

	cin >> n >> m;

	for (int i = 0; i < n; i++) {

		for (int j = 0; j < 6; j++) {

			cin >> x[i][j];

			MAXX[j % 3] = max(MAXX[j % 3], x[i][j]);

		}

	}



	for (int i = 0; i < 3; i++) {

		for (int j = 0; j <= MAXX[i]; j++) {

			for (int k = 0; k < n; k++) {

				if (x[k][i] == j) {

					y[k][i] = SUMX[i];

					z[SUMX[i]][i] = j;

					SUMX[i] += 1;

				}

				if (x[k][i + 3] == j) {

					y[k][i + 3] = SUMX[i];

					z[SUMX[i]][i] = j;

					SUMX[i] += 1;

				}

			}

		}

	}



	for (int i = 0; i < SUMX[0]; i++) {

		for (int j = 0; j < SUMX[1]; j++) {

			for (int k = 0; k < SUMX[2]; k++){

				a[i][j][k] = z[i + 1][0] - z[i][0];

				a[i][j][k] *= z[j + 1][1] - z[j][1];

				a[i][j][k] *= z[k + 1][2] - z[k][2];

			}

		}

	}



	int p;

	long long int sum = 0;



	for (int i = 0; i < SUMX[0]; i++) {

		for (int j = 0; j < SUMX[1]; j++) {

			for (int k = 0; k < SUMX[2]; k++) {

				p = 0;

				for (int l = 0; l < n; l++) {

					if (((y[l][0] <= i && y[l][3]>i) && (y[l][1] <= j && y[l][4]>j)) && (y[l][2] <= k && y[l][5]>k)) {

						p++;

					}

				}

				if (p >= m) {

					sum += a[i][j][k];

					b[i][j][k] = true;

				}

			}

		}

	}



	cout << sum << endl;



	return 0;

}