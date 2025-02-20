#include <string>

#include <vector>

#include <iostream>



#pragma warning(disable : 4996)



#define mod 100000



using namespace std;



int H, W, dp[2][1 << 19][2][2]; string M[20];



int main()

{

	scanf("%d", &H);

	scanf("%d", &W);



	for (int i = 0; i < H; i++) cin >> M[i];



	if (M[0][0] == 'J' || M[0][0] == '?') dp[0][0][0][0] += 1;

	if (M[0][0] == 'O' || M[0][0] == '?') dp[0][0][1][0] += 1;

	if (M[0][0] == 'I' || M[0][0] == '?') dp[0][0][1][0] += 1;



	int maxbits = 1 << (W - 1);



	for (int i = 0; i < H * W - 1; i++)

	{

		for (int j = 0; j < maxbits; j++)

		{

			dp[(i ^ 1) & 1][j][0][0] = 0;

			dp[(i ^ 1) & 1][j][0][1] = 0;

			dp[(i ^ 1) & 1][j][1][0] = 0;

			dp[(i ^ 1) & 1][j][1][1] = 0;

		}



		for (int j = 0; j < maxbits; j++)

		{

			char c = M[(i + 1) / W][(i + 1) % W];



			int nxt = (j << 1) % (1 << (W - 1));



			int sum0 = (dp[i & 1][j][0][0] + dp[i & 1][j][1][0]) % mod;

			int sum1 = (dp[i & 1][j][0][1] + dp[i & 1][j][1][1]) % mod;



			if (c == 'J' || c == '?')

			{

				dp[(i ^ 1) & 1][nxt][0][0] += sum0;

				dp[(i ^ 1) & 1][nxt][0][1] += sum1;

			}



			if (c == 'O' || c == '?')

			{

				if ((M[i / W][i % W] == 'J' || M[i / W][i % W] == '?') && i % W != W - 1)

				{

					dp[(i ^ 1) & 1][nxt + 1][1][0] += dp[i & 1][j][0][0];

					dp[(i ^ 1) & 1][nxt + 1][1][1] += dp[i & 1][j][0][1];



					dp[(i ^ 1) & 1][nxt + 1][1][0] %= mod;

					dp[(i ^ 1) & 1][nxt + 1][1][1] %= mod;



					dp[(i ^ 1) & 1][nxt][1][0] += (sum0 - dp[i & 1][j][0][0] + mod);

					dp[(i ^ 1) & 1][nxt][1][1] += (sum1 - dp[i & 1][j][0][1] + mod);

				}

				else

				{

					dp[(i ^ 1) & 1][nxt][1][0] += sum0;

					dp[(i ^ 1) & 1][nxt][1][1] += sum1;

				}

			}



			if (c == 'I' || c == '?')

			{

				if (j & (1 << (W - 2)))

				{

					dp[(i ^ 1) & 1][nxt][1][1] += sum0;

				}

				else

				{

					dp[(i ^ 1) & 1][nxt][1][0] += sum0;

				}



				dp[(i ^ 1) & 1][nxt][1][1] += sum1;

			}



			dp[(i ^ 1) & 1][nxt][1][0] %= mod;

			dp[(i ^ 1) & 1][nxt][1][1] %= mod;

		}

	}



	int ret = 0;



	for (int i = 0; i < maxbits; i++)

	{

		ret += dp[(H * W - 1) % 2][i][0][1];

		ret += dp[(H * W - 1) % 2][i][1][1];



		ret %= mod;

	}



	printf("%d\n", ret);



	return 0;

}