#include <map>

#include <iostream>



using namespace std;



int main()

{

	int N, M;



	char A, B, C;



	while (true)

	{

		cin >> N;



		if (N == 0) { break; }



		map<char, char> converse;



		for (char i = '0'; i <= 'z'; i++)

		{

			converse[i] = i;

		}



		for (int i = 0; i < N; i++)

		{

			cin >> A >> B;



			converse[A] = B;

		}



		cin >> M;



		for (int i = 0; i < M; i++)

		{

			cin >> C;



			cout << converse[C];

		}



		cout << endl;

	}



	return 0;

}