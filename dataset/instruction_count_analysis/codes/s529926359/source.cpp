#include<cstdio>

#include<cmath>

#include<algorithm>

#include<cstring>



using namespace std;



char orin[100005];



int main(void)

{

	int grades = 0, ok = 0;

	scanf("%s", orin);

	for (int i = 0; orin[i]; ++i)

	{

		if (orin[i] == 'g')

		{

			if (ok)

			{

				++grades;

				--ok;

			}

			else

				++ok;

		}

		else

		{

			if (ok)

				--ok;

			else

			{

				--grades;

				++ok;

			}

		}

	}

	printf("%d", grades);

}