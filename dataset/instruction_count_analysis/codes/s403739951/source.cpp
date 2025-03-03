#include <iostream>

#include <string>

using namespace std;



int main(){

    int w1=0,h1=0,w2,h2,n,i;

    cin >> w2 >> h2 >> n;

    int a[n];

    for (i=0;i<n;i++){

        int x,y;

        cin >> x >> y >> a[i];

        if (a[i] == 1){

            if(x > w1){

                w1 = x;

            }

        }

        if (a[i] == 2){

            if (x < w2){

                w2 = x;

            }

        }

        if (a[i] == 3){

            if (y > h1){

                h1 = y;

            }

        }

        if (a[i] == 4){

            if (y < h2){

                h2 = y;

            }

        }

    }



    int num = (w2 - w1) * (h2 - h1);

    if (w2 < w1 || h2 < h1){

        cout << 0;

    }

    else{

        cout << num;

    }

}


