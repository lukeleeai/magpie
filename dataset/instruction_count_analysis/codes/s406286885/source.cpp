#include"stdc++.h" 

using namespace std; 

#define MAXC 3000



char cads[MAXC+1], cadt[MAXC+1];

int dp[MAXC+1][MAXC+1];



int s,t;

char lcs[MAXC+1];



int main() { 

	int i,j;

        int posicion;

	scanf("%s",cads);

	scanf("%s",cadt);

	s=strlen(cads); t = strlen(cadt);

	for (i=0; i<=s; i++) {

		dp[i][0]=0;

	}

	for (j=1; j<=t; j++) {

		dp[0][j]=0;

	}



	for (i=1;i<=s; i++) {

		for (j=1; j<=t; j++) {

			if (cads[i-1]==cadt[j-1]) {

				dp[i][j]=dp[i-1][j-1]+1;

			}

			else {

				dp[i][j]=max(dp[i-1][j],dp[i][j-1]);

			}

		}

	}

	/*for (i=0; i<=s; i++) {

		for (j=0; j<=t; j++) {

			printf("%5d", dp[i][j]);

		}

		printf("\n");

	}

	printf("%d\n",dp[s][t]);*/

	posicion=dp[s][t];

	lcs[posicion]=0;

	for (i=s, j=t; i>0 && j>0; ) {

		if (cads[i-1]==cadt[j-1]) {

			posicion--; i--; j--;

			lcs[posicion]=cads[i];

		}

		else if (dp[i-1][j]>dp[i][j-1]) {

			i--;

		}

		else { 

			j--; 

		}

	}

	printf("%s\n", lcs);

	return 0; 

} 
