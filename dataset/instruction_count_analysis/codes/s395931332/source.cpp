#include "stdc++.h"



using namespace std;



int N, digit, counter;

bool ok = false;



int main()

{

        cin >> N;



        digit = N % 10;

        counter = 1;

        N /= 10;



        while (N > 0)

        {

                int currentDigit = N % 10;

                if (digit == currentDigit)

                {

                        ++counter;

                        if (counter == 3)

                                ok = true;

                }

                else

                {

                        digit = currentDigit;

                        counter = 1;

                }



                N /= 10;

        }



        if (ok == true)

                cout << "Yes";

        else

                cout << "No";



        return 0;

}