#include <iostream>

#include <string>

#include <algorithm>

#include <cmath>

#include <vector>

#include <limits>



using namespace std;



int main()

{

    int N,a;

    long long sum[200001] = {};

    long long min_num = 2 * pow(10, 9.0);



    cin >> N;



    for (int i = 1; i <= N; i++) {

        cin >> a;

        sum[i] = sum[i - 1] + a;

    }

    

    for ( int i = 1; i < N; i++) {

        min_num = min(min_num, abs(sum[N] - sum[i] - sum[i]));

    }

    cout << min_num << '\n';



}