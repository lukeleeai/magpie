#include "stdc++.h"



using namespace std;



/*

 * 

 */

int main(int argc, char** argv) {

    cin.tie(NULL);

    ios::sync_with_stdio(0);

    

    long n; cin >> n;

    long arr[100010];

    memset(arr, 0, sizeof arr);

    

    for(int i = 0; i < n; i++){

        long aux; cin >> aux;

        arr[i] = aux;

    }

    

    long contA = 0, contB = 0, sumB = 0, sumA = 0;

    

    if(arr[0] < 0){

        contB += abs(arr[0]) + 1;

        sumB = 1;     

        sumA = arr[0];       

    }else if(arr[0] > 0){

        contA += abs(arr[0]) + 1;

        sumA = -1;

        sumB = arr[0];     

    }

    if(arr[0] == 0){

        contB++;

        contA++;

        sumA = -1;

        sumB = 1;

    }

    //cout << "SUM a "<<sumA<<" SUM b "<<sumB<<'\n';

    //cout <<"A "<< contA <<" B "<<contB<<'\n';

    for(int i = 1; i < n; i++){

        if(sumA > 0){

            sumA += arr[i];

            if(sumA >= 0){

                contA += sumA + 1;

                sumA = -1;

            }

        }else if(sumA < 0){

            sumA += arr[i];

            if(sumA <= 0){

                contA += abs(sumA) + 1;

                sumA = 1;                            

            }

        }

        

        if(sumB > 0){

            sumB += arr[i];

            if(sumB >= 0){

                contB += sumB + 1;

                sumB = -1;

            }

        }else if(sumB < 0){

            sumB += arr[i];

            if(sumB <= 0){

                contB += abs(sumB) + 1;

                sumB = 1;

            }

        }

        //cout << "SUM a "<<sumA<<" SUM b "<<sumB<<'\n';

        //cout <<"A "<< contA <<" B "<<contB<<'\n';

    }

    

    cout << min(contA, contB)<<'\n';

    return 0;

}
