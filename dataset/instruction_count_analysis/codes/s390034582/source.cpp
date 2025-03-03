#include "stdc++.h"



using namespace std;



int main() { 

	

	//freopen ("in.txt", "r", stdin);

	

	int t;

	scanf ("%d", &t);

	

	long a[t][t];

	

	for (int i=0; i<t; i++) for (int j=0; j<t; j++) scanf ("%ld", &a[i][j]);

	

	long sum = 0;

	bool mark[t][t];

	memset(mark, false, sizeof mark);

	bool impossible = false;

	for (int i=0; i<t; i++) { 

		for (int j=0; j<t; j++) { 

			for (int k=j+1; k<t; k++) { 

				if(a[j][k]==a[j][i]+a[i][k] && i!=j && i!=k) mark[j][k] = true;

				if(a[j][k]>a[j][i]+a[i][k]) { 

					impossible = true;

					break;

				}

			}

		}		

	}

	if(impossible) { printf ("-1\n");  return 0;}

	for (int i=0; i<t; i++) for (int j=i+1; j<t;j++) if(!mark[i][j]) sum+=a[i][j];

	

	

	

		printf ("%ld\n", sum);

	

	return 0;

}
