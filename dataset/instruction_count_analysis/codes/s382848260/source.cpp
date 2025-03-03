#include"stdc++.h"

using namespace std;

typedef long long LL; //打板子留下的习惯~

LL n;

char s[11],s2[11]; //存储i 和 n / i,便于计算位数

int main()

{

    cin >> n;

    for (int i = sqrt(n); i >= 1; -- i) //正方形的启发

    {

        if (n % i == 0)

        {

            int i2 = n / i; //存储n / i

            sprintf(s,"%d",i);

            sprintf(s2,"%d",i2);//写入字符串

            cout << max(strlen(s),strlen(s2)) << endl; //strlen()函数直接搞定位数问题

            break;//由于从大到小枚举因数，故找到的一定是最优解，找到一组解直接跳循环

        }

    }

    return 0;

}