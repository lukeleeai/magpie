#include <iostream>



using namespace std;



int main()

{

    long long value;

    while(cin >> value){

        int divisor = 0;

            int temp = value;

            while(temp!=0){

                divisor += temp%10;

                temp /=10;

            }

            if(value%divisor == 0){

                cout << "Yes" << endl;

            }

            else

                cout << "No" << endl;

    }

    return 0;

}
