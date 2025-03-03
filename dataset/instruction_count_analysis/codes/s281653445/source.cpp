#include <stdio.h>

#include <stdlib.h>

#include <string.h>

#include <math.h>

#define INF 0x3f3f3f3f



char s[100];

typedef long long ll;



void step(int x, int y)

{

    for (int i = 0; i < y; ++i)

    {

        printf("U");

    }

    for (int i = 0; i < x; ++i)

    {

        printf("R");

    }

    for (int i = 0; i < y; ++i)

    {

        printf("D");

    }

    for (int i = 0; i < x; ++i)

    {

        printf("L");

    }

}



int main()

{

    //freopen("C:\\Users\\tiger\\Desktop\\a.txt","r",stdin);

	int x1,y1;

    int x2,y2;

    while ( ~scanf("%d %d %d %d", &x1, &y1, &x2, &y2) )

    {

        int x = x2 - x1;

        int y = y2 - y1;

        step(x,y);

        printf("L");

        for (int i = 0; i <= y; ++i)

        {

            printf("U");

        }

        for (int i = 0; i <= x; ++i)

        {

            printf("R");

        }

        printf("D");

        printf("R");

        for (int i = 0; i <= y; ++i)

        {

            printf("D");

        }

        for (int i = 0; i <= x; ++i)

        {

            printf("L");

        }

        printf("U\n");

    }

	return 0;

}