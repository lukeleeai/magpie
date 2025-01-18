#include "stdc++.h"

using namespace std;



//count1...先頭＝＝末尾, count2...先頭！＝末尾

int count1 = 0, count2 = 0;



//先頭と末尾の判定

bool test1(long long A, long long B)

{

    string a = to_string(A), b = to_string(B);



    if (a.at(0) == b.at(b.length() - 1) && a.at(a.length() - 1) == b.at(0))

    {

        return true;

    }



    else

    {

        return false;

    }

}



//先頭と末尾の判定カウント

long long test2(long long A, long long B)

{

    string a = to_string(A), b = to_string(B);



    if (a.at(0) == b.at(b.length() - 1) && a.at(a.length() - 1) == b.at(0))

    {



        if (a.at(0) == a.at(a.length() - 1))

        {

            count1++;

        }



        else

        {

            count2++;

        }

    }

}



int main()

{

    long long N, ans = 0, count3 = 0;

    cin >> N;



    if (N < 100)

    {

        for (long long A = 1; A < N + 1; A++)

        {

            for (long long B = 1; B < N + 1; B++)

            {

                if (test1(A, B))

                {

                    ans++;

                }

            }

        }

    }



    else

    {



        ans += pow(N / 10, 2) + 8;



        if (N > (N % 10) * 10)

        {

            for (int j = (N / 10) * 10 + 1; j < N + 1; j++)

            {

                string a = to_string(j);



                if (a.at(0) == a.at(a.length() - 1))

                {

                    count3++;

                }



                for (int i = 1; i < N + 1; i++)

                {

                    test2(j, i);

                }

            }

        }



        ans += (count1 * 2 - count3) + count2 * 2;

    }



    cout << ans << endl;

}