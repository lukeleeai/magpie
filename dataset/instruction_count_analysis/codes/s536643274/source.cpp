#include <vector>

#include <iostream>



using namespace std;



int main()

{

	int A, B;



	scanf("%d", &A);

	scanf("%d", &B);



	vector<int> P(A);

	vector<int> Q(B);



	for (int i = 0; i < A; i++) { scanf("%d", &P[i]); }

	for (int i = 0; i < B; i++) { scanf("%d", &Q[i]); }



	int l = 1;

	int r = B;

	int m;



	while(r - l > 1)

	{

		m = (l + r) / 2;



		bool ok = false;



		for (int j = 0; j < (B - m); j++)

		{

			int ptr = j;



			for (int k = 0; k < A; k++)

			{

				if (P[k] == Q[ptr])

				{

					ptr++;

				}



				if (ptr == j + m)

				{

					break;

				}

			}



			if (ptr == j + m)

			{

				ok = true;

			}

		}



		if (ok)

		{

			l = m;

		}

		else

		{

			r = m;

		}

	}



	printf("%d\n", l);



	return 0;

}