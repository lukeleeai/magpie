#include "stdc++.h"



using namespace std;



int main(){

    int hei, wid, h, w;

    cin >> hei >> wid >> h >> w;

    if(hei%h == 0 && wid%w == 0){

        cout << "No";

    }

    else{

        cout << "Yes" << endl;

        //max 1000000000

        long long x = 999999999/(h*w-1);

        long long y = x*(h*w-1)+1;

        for(int one = 1; one <= hei; one++){

            for(int two = 1; two <= wid; two++){

                if(one%h == 0 && two%w == 0){

                    cout << -y << ' ';

                }

                else{

                    cout << x << ' ';

                }

            }

            cout << endl;

        }

    }

}