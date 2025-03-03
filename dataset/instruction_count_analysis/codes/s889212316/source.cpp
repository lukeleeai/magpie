#include <iostream>

#include <string>

#include <vector>



using namespace std;



void solve()

{

	int N;

	scanf("%d\n", &N);

	while(N--)

	{

		string s;

		getline(cin, s);

		string sbuf = s;

		sbuf += ' ';

		int n = sbuf.size();

		int start = 0;

		int end = 0;

		vector<string> Vec;

		string temp;

		for(int i = 0; i < n; ++i)

		{

			if(sbuf[i] == ' ')

			{

				if(end - start == 4)

				{

					Vec.push_back(temp);

				}

				start = end = i + 1;

				temp.clear();

				continue;

			}

			temp += sbuf[i];

			++end;

		}

		int a = 0;

		int b = 0;

		for(int i = 0; i < Vec.size(); ++i)

		{

			for(int j = 0; j < 4; ++j)

			{

				Vec[i][j] %= 26;

			}

		}

		for(int i = 0; i < 26; ++i)

		{

			for(int j = 0; j < 27; ++j)

			{

				for(int k = 0; k < Vec.size(); ++k)

				{

					string check = "asdf";

					for(int l = 0; l < 4; ++l)

					{

						check[l] = (i * Vec[k][l] + j) % 26 + 'a';

					}

					if(check == "this" || check == "that")

					{

						a = i;

						b = j;

						goto END;

					}

				}

			}

		}

END:

		n = s.size();

		for(int i = 0; i < n; ++i)

		{

			if(s[i] == ' ')

			{

				cout << s[i];

				continue;

			}

			s[i] = (a * (s[i] % 26) + b) % 26 + 'a';

			cout << s[i];

		}

		cout << endl;

	}

}



int main()

{

	solve();

	return(0);

}