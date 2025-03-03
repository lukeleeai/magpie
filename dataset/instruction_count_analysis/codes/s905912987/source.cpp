#include <iostream>

#include <cmath>

#include <string>

#include <algorithm>

using namespace std;



int main(){

    int N;

    int A[200000]={};

    cin >> N;

    for(int i=0;i<N;i++){

        cin >> A[i];

        A[i] -= (i+1);

    }

    sort(A,A+N);

    int b = A[N/2];

    long long sum=0;

    for(int i=0;i<N;i++){

        sum += abs(A[i] - b);

    }

    cout << sum << endl;

}
