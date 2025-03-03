#include <iostream>

#include <algorithm>

#include <cmath>

#include <vector>

#include <string>

#include <iomanip>

//#include <string.h>

#include "stdc++.h"

#define INF 999999999

using namespace std;

#define ll long long

#define boost ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

struct shi

{

    int x=0;

    int T;

}s[1000000];

int cmd(shi a,shi b)

{

    return a.x<b.x;

}

/*long long cmd(long long a, long long  b)

{

    return a > b;

}*/



int main()

{

    boost;

    int N;

    cin >>N;

    int   hh[100000];

    for(int i=0;i<N;i++){

        cin >>hh[i];

    }

    sort(hh,hh+N);

    int kk[105000];

    int ma=0;

    for(int i=0;i<N;i++){

        if(i!=0&&i!=N-1){

            kk[i]+=abs(hh[i]-hh[N-1])*2;

            kk[i]+=abs(hh[i]-hh[0]);

        }

        else

            kk[i]+=abs(hh[0]-hh[N-1]);



    }



    sort(kk,kk+N);

    cout<<kk[0]<<endl;

    return 0;



}
