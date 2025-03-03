#import <iostream>

#import <sstream>

using namespace std;



void problemOne(){

      int a;

      int b;

      while (cin >> a >> b){

            int sum = a + b;

            int intLength = 0;

            while (sum != 0) {

                  sum /= 10;

                  intLength += 1;

            }

            cout << intLength << endl;

      }

}



int main(){

      problemOne();

}