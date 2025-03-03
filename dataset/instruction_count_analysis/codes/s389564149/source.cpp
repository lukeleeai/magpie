#include "stdc++.h"

using namespace std;



int func(int n, int a){

    int res = 0;

    while(n>0){

        res += n % a;

        n /= a;

    }

    return res;

}

int main() {

    int N; cin >> N;

    int res = N;

    for (int i=0;i<=N;++i){

        int tmp = func(i,6) + func(N-i, 9);

        res = min(res, tmp);

    }   

    cout << res << endl;

    return 0;

}