#include "stdc++.h"

using namespace std;



int calc(int x){

    int ret = 0;

    while(x % 100 == 0){

        x /= 100;

        ret++;

    }

    return ret;

}



int main(){

    int D, N;

    cin >> D >> N;



    int num = 0, cnt = 0;

    while(cnt < N){

        num++;

        if(calc(num) == D) cnt++;

    }

    cout << num << endl;

}