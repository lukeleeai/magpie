#include <iostream>

using namespace std;



int main()

{

    char mun[55][55], num[55][55];

    int i = 0, j = 0, m = 0, n = 0, x = 0, k = 0, z = -1, s = 0, p = -1, o = 0, d = 0;

    cin >> m >> n;

    for(i = 0; i < m; i++)

    {

        for(j = 0; j < m; j++)

        {

            cin >> mun[i][j];

        }

    }

     for(i = 0; i < n; i++)

    {

        for(j = 0; j < n; j++)

        {

            cin >> num[i][j];

        }

    }

    for(i = 0; i < m - n + 1; i++)

    {

        z++;

        for(s = 0; s < m - n + 1; s++)

        {

            p++;

        for(j = z; j < m; j++)

        {

            d++;

            for(k = p; k < m; k++)

            {

                o++;

                if(num[j - z][k - p] == mun[j][k])

                {

                    x++;



                }

                if(x == n * n)

                {

                    cout << "Yes";

                    break;

                }

                if(o == n)

                {

                    o = 0;

                    break;

                }

            }

            if(x == n * n)

                {



                    break;

                }

             if(d == n)

                {

                    d = 0;

                    break;

                }

        }

        if(x == n * n)

                {



                    break;

                }

         x = 0;

        }

        if(x == n * n)

                {



                    break;

                }

        p = -1;

    }

if(x != n * n)

{

    cout << "No";

}





return 0;

}