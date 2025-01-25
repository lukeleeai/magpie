#include <iostream>

#include <algorithm>

#include <cmath>

#include <iomanip>

using namespace std;



bool eq(double x,double y){

  if(abs(x-y)<0.00001*y)return true;

  else return false;

}



int main(void){

    long long q;

    double x[100], x1;

    while(cin >> q){

        if(q == -1) break;

        x[1] = q/2.0;

        for(int i = 2; ; i++){

            x[i] = x[i-1]-(x[i-1]*x[i-1]*x[i-1]-(double)q)/(3*x[i-1]*x[i-1]);

            if(eq(x[i]*x[i]*x[i],(double)q)){

                x1 = x[i]; 

                break;

            }

        }

        cout <<fixed;

        cout << setprecision(7) << x1 << endl;

    } 

    return 0;

}


