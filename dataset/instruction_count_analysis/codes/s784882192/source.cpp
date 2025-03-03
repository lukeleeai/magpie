#include <set>

#include <string>

#include <vector>

#include <iostream>

#include <algorithm>



using namespace std;



int main()

{

	int N, M, L, R, C; string S; char Q[4];



	scanf("%d", &N);

	scanf("%d", &M);

	

	cin >> S;



	L = 0;

	R = 0;

	C = 0;



	vector<vector<int> > F(N + 1, vector<int>());



	for (int i = 0; i < M; i++)

	{

		scanf("%s", Q);



		if (Q[0] == 'L' && Q[1] == '+') { L++; }

		if (Q[0] == 'L' && Q[1] == '-') { L--; }

		if (Q[0] == 'R' && Q[1] == '+') { R++; }

		if (Q[0] == 'R' && Q[1] == '-') { R--; }



		F[R - L + 1].push_back(L);



		C = max(C, R - L + 1);

	}



	vector<vector<int> > D(N + 1, vector<int>());



	for (int i = 1; i <= N; i++)

	{

		sort(F[i].begin(), F[i].end());



		if (F[i].size())

		{

			D[i].push_back(F[i][0]);

		}



		for (int j = 1; j < F[i].size(); j++)

		{

			if (F[i][j - 1] != F[i][j])

			{

				D[i].push_back(F[i][j]);

			}

		}

	}



	int Answer = 0;



	for (int i = 1; i <= C; i++)

	{

		set<string> s;



		for (int j = 0; j < D[i].size(); j++)

		{

			s.insert(S.substr(D[i][j], i));

		}



		Answer += s.size();

	}



	cout << Answer << endl;



	return 0;

}