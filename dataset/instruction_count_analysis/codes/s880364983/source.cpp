#include <cstdio>

#include <cstring>

#include <algorithm>

void Unused(...) {}

#ifndef DEBUG

  #define echo(...) Unused(__VA_ARGS__)

#else

  #define echo(...) fprintf(stderr, __VA_ARGS__)

#endif



const int MaxN = 100 + 7;



int h, w;

bool a[MaxN][MaxN];

bool used[2][MaxN];



int main()

{

    scanf("%d %d", &h, &w);

    for (int i = 1; i <= h; ++i)

    {

        getchar();

        for (int j = 1; j <= w; ++j)

        {

            if (getchar() == '.')

                a[i][j] = false;

            else

                a[i][j] = true;

        }

    }

    for (int i = 1; i <= h; ++i)

    {

        bool hide = true;

        for (int j = 1; j <= w; ++j)

            if (a[i][j])

            {

                hide = false;

                break;

            }

        used[0][i] = !hide;

    }

    for (int i = 1; i <= w; ++i)

    {

        bool hide = true;

        for (int j = 1; j <= h; ++j)

            if (a[j][i])

            {

                hide = false;

                break;

            }

        used[1][i] = !hide;

    }

    

    for (int i = 1; i <= h; ++i)

    {

        if (used[0][i])

        {

            for (int j = 1; j <= w; ++j)

                if (used[1][j])

                {

                    if (a[i][j])

                        printf("#");

                    else

                        printf(".");

                }

            printf("\n");

        }

    }



    return 0;

}


