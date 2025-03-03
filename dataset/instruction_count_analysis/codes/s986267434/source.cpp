#include <iostream>

using namespace std;



int N, bil, freq[100100], total;



int main() {

    cin >> N;

    for(int i=1; i<=N; i++){

        cin >> bil;

        if (bil>100000){

            total++;

        } else {

            freq[bil]++;

        }

    }

    for (int i=1; i<=100000; i++){

        if(freq[i]>=i){

            total += freq[i]-i;

        }

        else {

            total += freq[i];

        }

    }

    cout << total <<endl;

}
