#include <vector>

#include <iostream>

#include <algorithm>



using namespace std;



int main()

{

	int D, N, M;



	while (true)

	{

		cin >> D;



		if (D == 0) { break; }

		

		cin >> N >> M;



		vector<int> S(N + 1);

		vector<int> T(M);



		S[0] = 0;

		S[N] = D;



		for (int i = 1; i < N; i++) { cin >> S[i]; }

		for (int i = 0; i < M; i++) { cin >> T[i]; }



		sort(S.begin(), S.end());



		long long distance_ = 0;



		for (int i = 0; i < M; i++)

		{

			int l = *(upper_bound(S.begin(), S.end(), T[i]) - 1);

			int r = *lower_bound(S.begin(), S.end(), T[i]);



			distance_ += min(T[i] - l, r - T[i]);

		}



		cout << distance_ << endl;

	}

	

	return 0;

}