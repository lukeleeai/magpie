#include <iostream>



using namespace std;



int L[100001],N;



int main(void)

{

	cin >> N;

	for(int i = 0;i < N;i++)

	{

		cin >> L[i];

	}

	int len = 0,t,s,l;

	t = 1;

	s = 0;

	while(L[t] != L[t+1] && t < N-1)

	t++;

	while(s > 0 && L[s] != L[s-1])

	s--;

	len = max(len,(t - s)+1);

	for(int i = 0;i < N-1;i++)

	{

		if(L[i] == L[i+1])

		{

			t = i+1;

			s = i;

			while(L[t] != L[t+1] && t < N-1)

				t++;

			while(s > 0 && L[s] != L[s-1])

				s--;

			if(t != N-1)

				l = t+1;

			else

				l = t;

			while(L[l] != L[l+1] && l < N-1)

				l++;

			//i = t-1;

			len = max(len,(l - s)+1);

		}

	}

	cout << len << endl;

}