#include <vector>

#include <iostream>

#include <algorithm>



using namespace std;



int main()

{

	int N, M, D;



	while (true)

	{

		scanf("%d", &N);

		scanf("%d", &M);



		if (N == 0 && M == 0) { break; }



		vector<int> C; C.push_back(0);



		for (int i = 0; i < N; i++)

		{

			scanf("%d", &D);



			if (D <= M)

			{

				C.push_back(D);

			}

		}



		vector<int> r;



		for (int i = 0; i < C.size(); i++)

		{

			for (int j = 0; j < C.size(); j++)

			{

				if (C[i] + C[j] <= M)

				{

					r.push_back(C[i] + C[j]);

				}

			}

		}



		sort(r.begin(), r.end());



		int ret = 0;



		for (int i = 0; i < r.size(); i++)

		{

			int ptr = upper_bound(r.begin(), r.end(), M - r[i]) - r.begin() - 1;

			

			if (ptr >= 0)

			{

				ret = max(ret, r[i] + r[ptr]);

			}

		}



		printf("%d\n", ret);

	}



	return 0;

}