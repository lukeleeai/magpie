#include "stdc++.h"

using namespace std;



int a[100001];

int N, i, cnt;

main(){

    cin >> N;

    for(; i<N; i++) cin >> a[i];

    for(int i = 0; i < N; i++){

        if(a[a[i] - 1] - 1 == i){

            cnt++;

        }

    }

    cout << cnt / 2 << endl;

    return 0;

}
