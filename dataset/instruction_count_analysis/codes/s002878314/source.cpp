#include <vector>

#include <iostream>

#include <algorithm>



#pragma warning(disable : 4996)



#define INF (1 << 25)



using namespace std;



int main()

{

	int N;



	scanf("%d", &N);



	vector<int> D(N - 1);



	for (int i = 0; i < N - 1; i++)

	{

		scanf("%d", &D[i]);

	}



	vector<vector<vector<int> > > dp(2, vector<vector<int> >(N / 2 + 1, vector<int>(2, INF)));



	dp[0][0][0] = 0;



	for (int i = 1; i < N; i++)

	{

		for (int j = 0; j <= N / 2; j++)

		{

			dp[i % 2][j][0] = min(dp[(i - 1) % 2][j][0], dp[(i - 1) % 2][j][1] + D[i - 1]);

			

			if (j != 0)

			{

				dp[i % 2][j][1] = min(dp[(i - 1) % 2][j - 1][1], dp[(i - 1) % 2][j - 1][0] + D[i - 1]);

			}

		}

	}



	printf("%d\n", min(dp[1][N / 2][0], dp[1][N / 2][1]));



	return 0;

}