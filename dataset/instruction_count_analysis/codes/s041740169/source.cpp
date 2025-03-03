#include <cstdio>

#include <cmath>

using namespace std;

int try1(int array[][5], int a, int b ,int len);

int max(int a, int b);

void sort(int array[][5], int len, int key);

int try2(int array[][5], int a , int b, int H, int len);

int main()

{

    int x, y, len, H;

    int array[100][5];

    scanf("%d", &len);

    for(int iter = 0;iter < len; iter++)

    {

        scanf("%d%d%d",&array[iter][0], &array[iter][1], &array[iter][2]);

    }

    for(x = 0; x <= 100;x++)

    {

        for(y = 0; y <= 100; y++)

        {

            H = try1(array, x, y, len);

            if((H >= 1)&&try2(array, x, y, H, len))

                break;

        }

        if(y != 101)

            break;

    }

    printf("%d %d %d", x, y, H);

}

int try1(int array[][5], int a, int b ,int len)

{

    int iter, i;

    for(iter = 0; iter < len; iter ++)

    {

        if(array[iter][2] == 0)//取max取出来的

        {

            array[iter][3] = -1;

            array[iter][4] = abs(array[iter][0] - a) + abs(array[iter][1] - b) +array[iter][2];

            continue;

        }

        else

            array[iter][3] = abs(array[iter][0] - a) + abs(array[iter][1] - b) +array[iter][2];

    }

    sort(array, len ,3);

    for(iter = 0; iter < len-1;iter++)

    {

        if((array[iter][3] == -1)||(array[iter+1][3] == -1))

            continue;

        else

            if(array[iter][3]!=array[iter+1][3])

                return -1;

    }

    if(array[len-1][3]!=-1)

        return array[len-1][3];

    else//全部取0

        sort(array, len, 4);

    return array[0][4];

}

void sort(int array[][5],int len, int key)

{

    int temp[5];

    int iter = 0;

    for(;iter < len-1;iter ++)

    {

        for(int j = 0;j < len -1 - iter;j++)

            if(array[j][key] >array[j+1][key])

            {

                temp[0] = array[j][0];

                temp[1] = array[j][1];

                temp[2] = array[j][2];

                temp[3] = array[j][3];

                temp[4] = array[j][4];

                array[j][0] = array[j+1][0];

                array[j][1] = array[j+1][1];

                array[j][2] = array[j+1][2];

                array[j][3] = array[j+1][3];

                array[j][4] = array[j+1][4];

                array[j+1][0]=temp[0];

                array[j+1][1]=temp[1];

                array[j+1][2]=temp[2];

                array[j+1][3]=temp[3];

                array[j+1][4]=temp[4];

            }

    }

}

int try2(int array[][5], int a , int b, int H, int len)

{

    for(int i = 0;i< len; i++)

    if(max(H-abs(a-array[i][0])-abs(b-array[i][1]),0) != array[i][2])

        return 0;

    return 1;

}

int max(int a, int b)

{

    return (a>b)?a:b;

}