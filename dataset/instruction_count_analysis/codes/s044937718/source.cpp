#include "stdc++.h"

using namespace std;

int main()

{

    int exist[50000];

    for(int i = 0; i < 50000; i++)exist[i] = i + 1;

    int N;

    cin >> N;

    for(int i = 0; i < 50000; i++){

        if((int)((float)exist[i]*1.08) == N){

            cout << exist[i];

            return 0;

        }

    }

    cout << ":(";

    return 0;

}


