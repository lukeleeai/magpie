#import <iostream>

#import <sstream>

using namespace std;



int main(){

      int firstNumber;

      int secondNumber;

      while (cin >> firstNumber >> secondNumber){

            int summation = firstNumber + secondNumber;

            int digitCount = 0;

            while (summation != 0) {

                  summation /= 10;

                  digitCount += 1;

            }

            cout << digitCount << endl;

      }

}
