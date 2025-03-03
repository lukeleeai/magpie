#include <cstdio>



int freind[111111], block[111111], group[111111];



int Find(int x)

{

    if (freind[x] == x)

		return x;

	else

		return freind[x] = Find(freind[x]);

}



int main(void)

{

	int n, m, k, i;



	scanf("%d %d %d" ,&n, &m, &k);



	for (i = 1; i <= n; i++)

		freind[i] = i, group[i] = 1;



	while (m--)

	{

        int a, b;



        scanf("%d %d" ,&a, &b);



        block[a]++;

        block[b]++;



        a = Find(a);

        b = Find(b);



        if (a != b)

		{

			if (a < b)

			{

				freind[b] = a;

				group[a] += group[b];

			}

			else

			{

				freind[a] = b;

				group[b] += group[a];

			}

		}

	}



    while (k--)

	{

		int c, d;



		scanf("%d %d" ,&c, &d);



		if (Find(c) == Find(d))

		{

			block[c]++;

			block[d]++;

		}

	}



    for (i = 1; i <= n; i++)

		printf("%d " ,group[Find(i)] - block[i] - 1);

	return 0;

}