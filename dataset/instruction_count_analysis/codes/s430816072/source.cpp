#include <iostream>



int main()

{

    long long X;

    std::cin >> X;

    constexpr int RANGE_MAX = 178;

    long long pow5[RANGE_MAX];

    for (int i = 0; i < RANGE_MAX; i++)

    {

        long x = i;

        pow5[i] = x * x * x * x * x;

    }



    for (int A = 0; A < RANGE_MAX; A++)

    {

        for (long long B = 0; B < A; B++)

        {

            if (pow5[A] - pow5[B] == X)

            {

                std::cout << A << " " << B << std::endl;

                return 0;

            }

            else if (pow5[A] + pow5[B] == X)

            {

                std::cout << A << " " << -B << std::endl;

                return 0;

            }

        }

    }

}
