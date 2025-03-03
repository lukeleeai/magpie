#include <iostream>

using namespace std;

long long n, m, a, b, c, d[1005][1005];

int main() {

	int i, j, k;

	cin>>n>>m;

	for(i=1; i<=n; i++) {

		for(j=1; j<=n; j++) d[i][j] = -1e18;

		d[i][i] = 0;

	}

	while(m--) cin>>a>>b>>c, d[a][b] = c;

	for(k=1; k<=n; k++) for(i=1; i<=n; i++) {

		if(d[i][k] == -1e18) continue;

		for(j=1; j<=n; j++) if(d[i][k] + d[k][j] > d[i][j]) d[i][j] = d[i][k] + d[k][j];

	}

	d[1][1]>0 ? cout<<"inf" : cout<<d[1][n];

	return 0;

}