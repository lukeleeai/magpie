#include "stdc++.h"

using namespace std;



const long double PI = (acos(-1));

const long double EPS = 0.0000000001;



long double a, b, x;



long double f(long double a, long double b, long double theta){

    if(theta > PI/2.0 - EPS) return 0.0;

    long double ret;

    if(a*tan(theta) <= b)

        ret = a*a*b - a*a*a*tan(theta)/2.0;

    else

        ret = b*b/tan(theta)*a/2.0;

    return ret;

}



void solve(){

    long double ok = PI/2.0;

    long double ng = 0.0;

    for(int _ = 1; _ <= 100000; _++){

        long double mid = (ok+ng)/2.0;

        if(f(a, b, mid) < x) ok = mid;

        else ng = mid;

    }

    cout << fixed << setprecision(10) << ok/PI*180 << endl;

}



int main(){

    cin.tie(0);

    ios::sync_with_stdio(false);

    cin >> a >> b >> x;

    solve();

    return 0;

}