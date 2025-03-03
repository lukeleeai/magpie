#include <stdio.h>

#include <iostream>

#include <algorithm>

#include <string>

#include <iomanip>

#include <math.h>

#include <utility>



#define div1 1000000007



using namespace std;



int main(void)

{

    long long N, X[100001], L[100001], i, S[100001], T[100001], ans=0, t=-10000000000;



    cin >> N;



    for(i=1; i<=N; i++){

        cin >> X[i] >> L[i];

        

        S[i] = X[i] - L[i];

        T[i] = X[i] + L[i];

    }



    pair<int, int> itv[100001];



    for(i=1; i<=N; i++){

        itv[i].first = T[i];//終

        itv[i].second = S[i];//始

    }



    sort(itv+1, itv+N+1);



    for(i=1; i<=N; i++){

        if(t <= itv[i].second){

            ans++;

            t = itv[i].first;

        }

    }



    cout << ans << endl;



    return 0;

}