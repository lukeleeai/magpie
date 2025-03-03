#include "stdc++.h"



using namespace std;



long long MOD = 1000000007;

long long prod(long long a, long long b){

    return (a*b)%MOD;

}



int main(){

    int n, m;

    cin >> n >> m;

    long long vert[n], hori[m];

    for(int one = 0; one < n; one++){

        cin >> vert[one];

    }

    for(int one = 0; one < m; one++){

        cin >> hori[one];

    }



    long long xaxis = 0, yaxis = 0, temp = 0, temp2 = 0, ans = 0;

    for(int one = 1; one < n; one++){

        temp = prod(one, n-one);

        temp2 = vert[one] - vert[one-1];

        temp = prod(temp, temp2);

        xaxis = (xaxis+temp)%MOD;

    }

    for(int one = 1; one < m; one++){

        temp = prod(one, m-one);

        temp2 = hori[one] - hori[one-1];

        temp = prod(temp, temp2);

        yaxis = (yaxis+temp)%MOD;

    }

    ans = prod(xaxis, yaxis);

    cout << ans;

}